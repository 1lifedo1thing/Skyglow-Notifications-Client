#import <Foundation/Foundation.h>
#import "SGControlChannelProtocol.h"

NSArray *SGN_AllNativelyRegisteredBundles(void);
BOOL SGN_BundleRegisteredWithNativePush(NSString *bundleId);
BOOL SGN_IsCascadeReEntry(NSString *bundleId);

void SGN_DeregisterAppNativelyWithCompletion(
    NSString *bundleId,
    void (^completion)(SGControlError error, NSString *detail));
    
void SGN_RegisterAppNativelyWithCompletion(
    NSString *bundleId,
    void (^completion)(SGControlError error, NSString *detail));

void SGN_PersistRemoteNotificationClient(NSString *bundleId, id client);
void SGNClassicRegisterApplication(id server, id application,
                                   id environment, int notificationTypes);

void SGN_DeliverSuccess(NSString *bundleId, id application, id environment,
                        int notificationTypes, NSData *token);

/** Prevents a APNS token from overwriting a sgn token. */
void SGN_InstallTokenGuard(void);

BOOL SGNRegistrationConsumePassThrough(void);
void SGNRegistrationBeginPassThrough(void);
void SGNRegistrationEndPassThrough(void);
void SGNRegistrationPresentClassicChoice(id server, id application,
                                         id environment, NSString *bundleId,
                                         int notificationTypes);

void SGNRegistrationPresentModernChoice(id server, NSString *bundleId,
                                        id resultBlock,
                                        SEL requestSelector);
