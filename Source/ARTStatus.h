#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ARTState) {
    ARTStateOk = 0,
    ARTStateConnectionClosedByClient,
    ARTStateConnectionDisconnected,
    ARTStateConnectionSuspended,
    ARTStateConnectionFailed,
    ARTStateAccessRefused,
    ARTStateNeverConnected,
    ARTStateConnectionTimedOut,
    ARTStateAttachTimedOut,
    ARTStateDetachTimedOut,
    ARTStateNotAttached,
    ARTStateInvalidArgs,
    ARTStateCryptoBadPadding,
    ARTStateNoClientId,
    ARTStateMismatchedClientId,
    ARTStateRequestTokenFailed,
    ARTStateAuthorizationFailed,
    ARTStateAuthUrlIncompatibleContent,
    ARTStateBadConnectionState,
    ARTStateError = 99999
};

/**
 The list of all public error codes returned under the error domain ARTAblyErrorDomain
 */
typedef CF_ENUM(NSUInteger, ARTErrorCode) {
    ARTErrorNoError = 10000,
    ARTErrorBadRequest = 40000,
    ARTErrorInvalidRequestBody = 40001,
    ARTErrorInvalidParameterName = 40002,
    ARTErrorInvalidParameterValue = 40003,
    ARTErrorInvalidHeader = 40004,
    ARTErrorInvalidCredential = 40005,
    ARTErrorInvalidConnectionId = 40006,
    ARTErrorInvalidMessageId = 40007,
    ARTErrorInvalidContentLength = 40008,
    ARTErrorMaxMessageLengthExceeded = 40009,
    ARTErrorInvalidChannelName = 40010,
    ARTErrorStaleRingState = 40011,
    ARTErrorInvalidClientId = 40012,
    ARTErrorInvalidMessageDataOrEncoding = 40013,
    ARTErrorResourceDisposed = 40014,
    ARTErrorInvalidDeviceId = 40015,
    ARTErrorInvalidMessageName = 40016,
    ARTErrorUnsupportedProtocolVersion = 40017,
    ARTErrorUnableToDecodeMessage = 40018,
    ARTErrorBatchError = 40020,
    ARTErrorInvalidPublishRequest = 40030,
    ARTErrorInvalidClient = 40031,
    ARTErrorReservedForTesting = 40099,
    ARTErrorUnauthorized = 40100,
    ARTErrorInvalidCredentials = 40101,
    ARTErrorIncompatibleCredentials = 40102,
    ARTErrorInvalidUseOfBasicAuthOverNonTlsTransport = 40103,
    ARTErrorTimestampNotCurrent = 40104,
    ARTErrorNonceValueReplayed = 40105,
    ARTErrorUnableToObtainCredentials = 40106,
    ARTErrorAccountDisabled = 40110,
    ARTErrorAccountConnectionLimitsExceeded = 40111,
    ARTErrorAccountMessageLimitsExceeded = 40112,
    ARTErrorAccountBlocked = 40113,
    ARTErrorAccountChannelLimitsExceeded = 40114,
    ARTErrorApplicationDisabled = 40120,
    ARTErrorKeyErrorUnspecified = 40130,
    ARTErrorKeyRevoked = 40131,
    ARTErrorKeyExpired = 40132,
    ARTErrorKeyDisabled = 40133,
    ARTErrorTokenErrorUnspecified = 40140,
    ARTErrorTokenRevoked = 40141,
    ARTErrorTokenExpired = 40142,
    ARTErrorTokenUnrecognised = 40143,
    ARTErrorInvalidJwtFormat = 40144,
    ARTErrorInvalidTokenFormat = 40145,
    ARTErrorConnectionLimitsExceeded = 40150,
    ARTErrorOperationNotPermittedWithProvidedCapability = 40160,
    ARTErrorOperationNotPermittedAsItRequiresAnIdentifiedClient = 40161,
    ARTErrorErrorFromClientTokenCallback = 40170,
    ARTErrorNoMeansProvidedToRenewAuthToken = 40171,
    ARTErrorForbidden = 40300,
    ARTErrorAccountDoesNotPermitTlsConnection = 40310,
    ARTErrorOperationRequiresTlsConnection = 40311,
    ARTErrorApplicationRequiresAuthentication = 40320,
    ARTErrorUnableToActivateAccountUnspecified = 40330,
    ARTErrorUnableToActivateAccountIncompatibleEnvironment = 40331,
    ARTErrorUnableToActivateAccountIncompatibleSite = 40332,
    ARTErrorNotFound = 40400,
    ARTErrorMethodNotAllowed = 40500,
    ARTErrorRateLimitExceededUnspecified = 42910,
    ARTErrorMaxPerConnectionPublishRateLimitExceeded = 42911,
    ARTErrorRateLimitExceededFatal = 42920,
    ARTErrorMaxPerConnectionPublishRateLimitExceededFatal = 42921,
    ARTErrorInternalError = 50000,
    ARTErrorInternalChannelError = 50001,
    ARTErrorInternalConnectionError = 50002,
    ARTErrorTimeoutError = 50003,
    ARTErrorRequestFailedDueToOverloadedInstance = 50004,
    ARTErrorEdgeProxyServiceInternalError = 50010,
    ARTErrorEdgeProxyServiceBadGateway = 50210,
    ARTErrorEdgeProxyServiceUnavailableAblyPlatform = 50310,
    ARTErrorTrafficTemporarilyRedirectedToBackupService = 50320,
    ARTErrorEdgeProxyServiceTimedOutWaitingAblyPlatform = 50410,
    ARTErrorReactorOperationFailed = 70000,
    ARTErrorReactorPostOperationFailed = 70001,
    ARTErrorReactorPostOperationReturnedUnexpectedCode = 70002,
    ARTErrorReactorMaxNumberOfConcurrentRequestsExceeded = 70003,
    ARTErrorReactorInvalidOrUnacceptedMessageContents = 70004,
    ARTErrorExchangeErrorUnspecified = 71000,
    ARTErrorForcedReAttachmentDueToPermissionsChange = 71001,
    ARTErrorExchangePublisherErrorUnspecified = 71100,
    ARTErrorNoSuchPublisher = 71101,
    ARTErrorPublisherNotEnabledAsAnExchangePublisher = 71102,
    ARTErrorExchangeProductErrorUnspecified = 71200,
    ARTErrorNoSuchProduct = 71201,
    ARTErrorProductDisabled = 71202,
    ARTErrorNoSuchChannelInThisProduct = 71203,
    ARTErrorForcedReAttachmentDueToRemapped = 71204,
    ARTErrorExchangeSubscriptionErrorUnspecified = 71300,
    ARTErrorSubscriptionDisabled = 71301,
    ARTErrorRequesterHasNoSubscriptionToThisProduct = 71302,
    ARTErrorChannelDoesNotMatchTheChannelFilter = 71303,
    ARTErrorConnectionFailed = 80000,
    ARTErrorConnectionFailedNoCompatibleTransport = 80001,
    ARTErrorConnectionSuspended = 80002,
    ARTErrorDisconnected = 80003,
    ARTErrorAlreadyConnected = 80004,
    ARTErrorInvalidConnectionIdRemoteNotFound = 80005,
    ARTErrorUnableToRecoverConnectionMessagesExpired = 80006,
    ARTErrorUnableToRecoverConnectionMessageLimitExceeded = 80007,
    ARTErrorUnableToRecoverConnectionExpired = 80008,
    ARTErrorConnectionNotEstablishedNoTransportHandle = 80009,
    ARTErrorInvalidTransportHandle = 80010,
    ARTErrorUnableToRecoverConnectionIncompatibleAuthParams = 80011,
    ARTErrorUnableToRecoverConnectionInvalidConnectionSerial = 80012,
    ARTErrorProtocolError = 80013,
    ARTErrorConnectionTimedOut = 80014,
    ARTErrorIncompatibleConnectionParameters = 80015,
    ARTErrorOperationOnSupersededConnection = 80016,
    ARTErrorConnectionClosed = 80017,
    ARTErrorInvalidConnectionIdInvalidFormat = 80018,
    ARTErrorAuthConfiguredProviderFailure = 80019,
    ARTErrorContinuityLossDueToMaxSubscribeMessageRateExceeded = 80020,
    ARTErrorClientRestrictionNotSatisfied = 80030,
    ARTErrorChannelOperationFailed = 90000,
    ARTErrorChannelOperationFailedInvalidState = 90001,
    ARTErrorChannelOperationFailedEpochExpired = 90002,
    ARTErrorUnableToRecoverChannelMessagesExpired = 90003,
    ARTErrorUnableToRecoverChannelMessageLimitExceeded = 90004,
    ARTErrorUnableToRecoverChannelNoMatchingEpoch = 90005,
    ARTErrorUnableToRecoverChannelUnboundedRequest = 90006,
    ARTErrorChannelOperationFailedNoResponseFromServer = 90007,
    ARTErrorMaxNumberOfChannelsPerConnectionExceeded = 90010,
    ARTErrorUnableToEnterPresenceChannelNoClientid = 91000,
    ARTErrorUnableToEnterPresenceChannelInvalidState = 91001,
    ARTErrorUnableToLeavePresenceChannelThatIsNotEntered = 91002,
    ARTErrorUnableToEnterPresenceChannelMaxMemberLimitExceeded = 91003,
    ARTErrorUnableToAutomaticallyReEnterPresenceChannel = 91004,
    ARTErrorPresenceStateIsOutOfSync = 91005,
    ARTErrorMemberImplicitlyLeftPresenceChannel = 91100
};

/**
 The list of all client error codes returned under the error domain ARTAblyErrorDomain
 */
typedef CF_ENUM(NSUInteger, ARTClientCodeError) {
    ARTClientCodeErrorInvalidType,
    ARTClientCodeErrorTransport,
};

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const ARTErrorInfoRequestIdKey;

FOUNDATION_EXPORT NSString *const ARTAblyErrorDomain;

/**
 Ably client exception names
 */
FOUNDATION_EXPORT NSString *const ARTFallbackIncompatibleOptionsException;

/**
 Ably client error messages
 */
FOUNDATION_EXPORT NSString *const ARTAblyMessageNoMeansToRenewToken;

/**
 ARTErrorInfo is a type encapsulating error information containing an Ably-specific error code and generic status code.
 */
@interface ARTErrorInfo : NSError

@property (readonly) NSString *message;
@property (nullable, readonly) NSString *reason;
@property (readonly) NSInteger statusCode;
@property (nullable, readonly) NSString *href;
@property (nullable, readonly) NSString *requestId;
@property (nullable, readonly) ARTErrorInfo *cause;

+ (ARTErrorInfo *)createWithCode:(NSInteger)code message:(NSString *)message;
+ (ARTErrorInfo *)createWithCode:(NSInteger)code status:(NSInteger)status message:(NSString *)message;
+ (ARTErrorInfo *)createFromNSError:(NSError *)error;
+ (ARTErrorInfo *)createFromNSException:(NSException *)error;
+ (ARTErrorInfo *)createWithCode:(NSInteger)code message:(NSString *)message requestId:(nullable NSString *)requestId;
+ (ARTErrorInfo *)createWithCode:(NSInteger)code status:(NSInteger)status message:(NSString *)message requestId:(nullable NSString *)requestId;
+ (ARTErrorInfo *)createFromNSException:(NSException *)error requestId:(nullable NSString *)requestId;
+ (ARTErrorInfo *)createUnknownError;
+ (ARTErrorInfo *)wrap:(ARTErrorInfo *)error prepend:(NSString *)prepend;

- (NSString *)description;

@end

/**
 Ably client status class
 */
@interface ARTStatus : NSObject

@property (nullable, readonly, strong, nonatomic) ARTErrorInfo *errorInfo;
@property (nonatomic, assign) BOOL storeErrorInfo;
@property (nonatomic, assign) ARTState state;

+ (ARTStatus *)state:(ARTState) state;
+ (ARTStatus *)state:(ARTState) state info:(nullable ARTErrorInfo *) info;

- (NSString *)description;

@end

@interface ARTException : NSException
@end

/**
 Support of ARTErrorInfo's properties for NSError
 */
@interface NSError (ARTErrorInfo)

- (NSInteger)artStatusCode;

@end

NS_ASSUME_NONNULL_END
