//
//  RealtimeClientPresence.swift
//  Ably
//
//  Created by Ricardo Pereira on 07/03/16.
//  Copyright © 2016 Ably. All rights reserved.
//

import Quick
import Nimble

func addRandomMembersToChannel(channelName: String, members: Int = 1, options: ARTClientOptions, done: ()->()) -> [ARTRealtime] {
    let client = ARTRealtime(options: options)
    let channel = client.channels.get(channelName)

    class Total {
        static var count: Int = 0
    }

    channel.attach() { _ in
        for _ in 1...members {
            channel.presence.enterClient(AblyTests.newRandomString(), data: nil) { _ in
                Total.count += 1
                if Total.count == members {
                    done()
                }
            }
        }
    }
    return [client]
}

class RealtimeClientPresence: QuickSpec {
    override func spec() {
        describe("Presence") {

            // RTP1
            context("ProtocolMessage bit flag") {

                it("when no members are present") {
                    let options = AblyTests.commonAppSetup()
                    options.autoConnect = false
                    let client = ARTRealtime(options: options)
                    client.setTransportClass(TestProxyTransport)
                    client.connect()
                    defer { client.close() }
                    let channel = client.channels.get("test")
                    channel.attach()

                    expect(channel.state).toEventually(equal(ARTRealtimeChannelState.Attached), timeout: testTimeout)

                    let transport = client.transport as! TestProxyTransport
                    let attached = transport.protocolMessagesReceived.filter({ $0.action == .Attached })[0]

                    expect(attached.flags & 0x1).to(equal(0))
                    expect(attached.isSyncEnabled()).to(beFalse())
                    expect(channel.presence.syncComplete).to(beFalse())
                    expect(channel.presenceMap.isSyncComplete()).to(beFalse())
                }

                it("when members are present") {
                    let options = AblyTests.commonAppSetup()

                    var disposable = [ARTRealtime]()
                    defer {
                        for clientItem in disposable {
                            clientItem.close()
                        }
                    }

                    waitUntil(timeout: testTimeout) { done in
                        disposable += addRandomMembersToChannel("test", members: 250, options: options) {
                            done()
                        }
                    }

                    options.autoConnect = false
                    let client = ARTRealtime(options: options)
                    client.setTransportClass(TestProxyTransport)
                    client.connect()
                    defer { client.close() }
                    let channel = client.channels.get("test")
                    channel.attach()

                    expect(channel.presence.syncComplete).to(beFalse())
                    expect(channel.state).toEventually(equal(ARTRealtimeChannelState.Attached), timeout: testTimeout)

                    let transport = client.transport as! TestProxyTransport
                    let attached = transport.protocolMessagesReceived.filter({ $0.action == .Attached })[0]

                    // There are members present on the channel
                    expect(attached.flags & 0x1).to(equal(1))
                    expect(attached.isSyncEnabled()).to(beTrue())
                    
                    expect(channel.presence.syncComplete).toEventually(beTrue(), timeout: testTimeout)

                    expect(transport.protocolMessagesReceived.filter({ $0.action == .Sync })).to(haveCount(3))

                }
            }

            // RTP15e
            let cases: [String:(ARTRealtimePresence, Optional<(ARTErrorInfo?)->Void>)->()] = [
                "enterClient": { $0.enterClient("john", data: nil, callback: $1) },
                "updateClient": { $0.updateClient("john", data: nil, callback: $1) },
                "leaveClient": { $0.leaveClient("john", data: nil, callback: $1) }
            ]
            for (testCase, performMethod) in cases {
                context(testCase) {
                    it("should implicitly attach the Channel") {
                        let client = ARTRealtime(options: AblyTests.commonAppSetup())
                        defer { client.close() }
                        let channel = client.channels.get("test")

                        expect(channel.state).to(equal(ARTRealtimeChannelState.Initialized))
                        waitUntil(timeout: testTimeout) { done in
                            //Call: enterClient, updateClient and leaveClient
                            performMethod(channel.presence) { errorInfo in
                                expect(errorInfo).to(beNil())
                                done()
                            }
                            expect(channel.state).to(equal(ARTRealtimeChannelState.Attaching))
                        }
                        expect(channel.state).to(equal(ARTRealtimeChannelState.Attached))
                    }

                    it("should result in an error if the channel is in the FAILED state") {
                        let client = ARTRealtime(options: AblyTests.commonAppSetup())
                        defer { client.close() }
                        let channel = client.channels.get("test")

                        channel.onError(AblyTests.newErrorProtocolMessage())

                        waitUntil(timeout: testTimeout) { done in
                            //Call: enterClient, updateClient and leaveClient
                            performMethod(channel.presence) { errorInfo in
                                expect(errorInfo!.message).to(contain("invalid channel state"))
                                done()
                            }
                        }
                    }

                    it("should result in an error if the channel moves to the FAILED state") {
                        let client = ARTRealtime(options: AblyTests.commonAppSetup())
                        defer { client.close() }
                        let channel = client.channels.get("test")

                        waitUntil(timeout: testTimeout) { done in
                            let error = AblyTests.newErrorProtocolMessage()
                            //Call: enterClient, updateClient and leaveClient
                            performMethod(channel.presence) { errorInfo in
                                expect(errorInfo).to(equal(error.error))
                                done()
                            }
                            channel.onError(error)
                        }
                    }
                }
            }

        }
    }
}
