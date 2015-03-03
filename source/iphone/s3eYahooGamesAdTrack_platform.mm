/*
 * iphone-specific implementation of the s3eYahooGamesAdTrack extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eYahooGamesAdTrack_internal.h"
 #include "IwDebug.h"
#include "s3eEdk.h"
#include "s3eEdk_iphone.h"
#import "PlayerIO.h"

@interface YGNServices : NSObject
@property (copy) NSString* m_gameId;
@property (copy) NSArray* m_segments;
@property (copy) NSDictionary* m_options;
@end

// Global instance
static YGNServices* g_ygnServices = 0;

@implementation YGNServices
+ (void)initialiseShared
{
    g_ygnServices = [[YGNServices alloc] init];
}

+ (instancetype)sharedInstance
{
    if (g_ygnServices == nil)
    {
        [YGNServices initialiseShared];
    }
    return g_ygnServices;
}

static int32 _handleOpenURL(void* systemData, void* userData)
{
    IwTrace(YAHOOGAMESADTRACK_VERBOSE,("_handleOpenURL CALLBACK %p, %p", systemData, userData));

    YGNServices *session = (YGNServices *)userData;

    if (session == g_ygnServices)
    {
		s3eEventDataHandleOpenUrlExtra* data = (s3eEventDataHandleOpenUrlExtra*)systemData;
		UIApplication* application = (UIApplication*) data->application;
		NSURL* url = (NSURL*) data->url;
		NSString* sourceApplication = (NSString*) data->sourceApplication;
		id annotation = (id) data->annotation;

		[[PlayerIO adTrack] startWithUrl:url gameId:[session m_gameId] playerInsightSegments:[session m_segments] options:[session m_options]];
	}

    return 0;
}

- (YGNServices*) init
{
    self = [super init];

    if (self)
    {
        // Register callback
        s3eEdkCallbacksRegisterInternal (
         S3E_EDK_INTERNAL,
         S3E_EDK_CALLBACK_MAX,
         S3E_EDK_IPHONE_HANDLEOPENURL_EXTRA,
         _handleOpenURL,
         self,
         false
         );
    }
    return self;
}

- (void) dealloc
{
    [self.m_gameId release];
    [self.m_segments release];
    [self.m_options release];
    [super dealloc];
}

+ (void)terminateShared
{
    if (g_ygnServices)
    {
        [g_ygnServices release];
        g_ygnServices = 0;
    }
}

@end

s3eResult s3eYahooGamesAdTrackInit_platform()
{
    if (![YGNServices sharedInstance])
    {
        return S3E_RESULT_ERROR;
    }

    return S3E_RESULT_SUCCESS;
}

void s3eYahooGamesAdTrackTerminate_platform()
{
	[YGNServices terminateShared];
}

void ygnAdTrackStart_platform(const char* gameId, const char* playerInsightSegmentsArray)
{
	NSString* segments = (playerInsightSegmentsArray)?[NSString stringWithUTF8String:playerInsightSegmentsArray]:nil;
	[YGNServices sharedInstance].m_gameId = (gameId)?[NSString stringWithUTF8String:gameId]:nil;
	[YGNServices sharedInstance].m_segments = (segments)?[segments componentsSeparatedByString:@"|"]:nil;
	[YGNServices sharedInstance].m_options = nil;
	[[PlayerIO adTrack] startWithLaunchOptions:nil gameId:[YGNServices sharedInstance].m_gameId playerInsightSegments:[YGNServices sharedInstance].m_segments options:[YGNServices sharedInstance].m_options];
}

void ygnAdTrackStop_platform()
{
	// No need to do anything here for iOS
}

void ygnAdTrackTrackExternalPayment_platform(const char* currency, int amount)
{
	[[PlayerIO adTrack] trackExternalPaymentWithCurrency:[NSString stringWithUTF8String:currency] amount:amount];
}

int ygnAdTrackTrackGetInstalledSource_platform()
{
    return (int) [[PlayerIO adTrack] installSource];
}
