
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define YGN_ADID ((SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"6.0")) ? [[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString] : @"")

#import <Foundation/Foundation.h>

typedef enum {
    kYGN_INSTALL_SOURCE_UNDETERMINED,
    kYGN_INSTALL_SOURCE_YAHOO,
    kYGN_INSTALL_SOURCE_UNKNOWN
} InstallSourceType;

/**
 The Player.IO AdTrack service.
 
 To use the AdTrack service successfully, you need to do the following:
 
 * Implement PlayLinks by completing the necessary setup in the Control Panel, and adding your custom url scheme to the "URL Types" of your app or your app's Info.plist file.
 
 * Call the "- startWithUrl:gameId:playerInsightSegments:options:" method from within your UIAppDelegate's "- application:didFinishLaunchingWithOptions:"
 
 * Call the "- startWithLaunchOptions:gameId:playerInsightSegments:options:"; method from within your your UIAppDelegate's "- application:openURL:sourceApplication:annotation:"
 
 * Track the payments made from within your app by calling "- trackExternalPaymentWithCurrency:amount:"
 */
@interface PIOAdTrack : NSObject

/**
 * Starts the AdTrack service. This method should be called from within the "- application:openURL:sourceApplication:annotation:" method.
 * @param url The url passed in
 * @param gameId The gameId of tghe game to connect to.
 * @param segments Optional segments that you may wish to pass in.
 * @param options A dictionary of key value pairs that can be passed in
 */
- (void)startWithUrl:(NSURL*)url
              gameId:(NSString *)gameId
playerInsightSegments:(NSArray *)segments
             options:(NSDictionary*)options;

/**
 * Starts the AdTrack service. Should be called from within the "- application:didFinishLaunchingWithOptions:" method.
 * @param launchOptions The launchOptions passed in.
 * @param gameId The gameId of tghe game to connect to.
 * @param segments Optional segments that you may wish to pass in.
 * @param options A dictionary of key value pairs that can be passed in
 */
- (void)startWithLaunchOptions:(NSDictionary *)launchOptions
                        gameId:(NSString *)gameId
         playerInsightSegments:(NSArray *)segments
                       options:(NSDictionary*)options;


/**
 * Track a completed payment in AdTrack from an external non-PayVault payment method.
 * @param currency The currency the payment was made in.
 * @param amount The amount of the payment in minor units (i.e. cents) in the given currency.
 */
- (void)trackExternalPaymentWithCurrency:(NSString*)currency amount:(int)amount;



/**
 * Returns a value indicating the campaign from which this app was installed from.
 * The possible values are: kYGN_INSTALL_SOURCE_UNDETERMINED, kYGN_INSTALL_SOURCE_YAHOO, and kYGN_INSTALL_SOURCE_UNKNOWN
 */
- (InstallSourceType)installSource;


@end
