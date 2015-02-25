/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "s3eYahooGamesAdTrack.h"


#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
// For MIPs (and WP8) platform we do not have asm code for stack switching
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL_LOCK
#endif
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*ygnAdTrackStart_t)(const char* gameId, const char* playerInsightSegmentsArray);
typedef       void(*ygnAdTrackStop_t)();
typedef       void(*ygnAdTrackTrackExternalPayment_t)(const char* currency, int amount);
typedef        int(*ygnAdTrackTrackGetInstalledSource_t)();

/**
 * struct that gets filled in by s3eYahooGamesAdTrackRegister
 */
typedef struct s3eYahooGamesAdTrackFuncs
{
    ygnAdTrackStart_t m_ygnAdTrackStart;
    ygnAdTrackStop_t m_ygnAdTrackStop;
    ygnAdTrackTrackExternalPayment_t m_ygnAdTrackTrackExternalPayment;
    ygnAdTrackTrackGetInstalledSource_t m_ygnAdTrackTrackGetInstalledSource;
} s3eYahooGamesAdTrackFuncs;

static s3eYahooGamesAdTrackFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x24957097, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3eYahooGamesAdTrackAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void ygnAdTrackStart(const char* gameId, const char* playerInsightSegmentsArray)
{
    IwTrace(YAHOOGAMESADTRACK_VERBOSE, ("calling s3eYahooGamesAdTrack[0] func: ygnAdTrackStart"));

    if (!_extLoadNoMsg())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_ygnAdTrackStart(gameId, playerInsightSegmentsArray);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void ygnAdTrackStop()
{
    IwTrace(YAHOOGAMESADTRACK_VERBOSE, ("calling s3eYahooGamesAdTrack[1] func: ygnAdTrackStop"));

    if (!_extLoadNoMsg())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_ygnAdTrackStop();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void ygnAdTrackTrackExternalPayment(const char* currency, int amount)
{
    IwTrace(YAHOOGAMESADTRACK_VERBOSE, ("calling s3eYahooGamesAdTrack[2] func: ygnAdTrackTrackExternalPayment"));

    if (!_extLoadNoMsg())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_ygnAdTrackTrackExternalPayment(currency, amount);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

int ygnAdTrackTrackGetInstalledSource()
{
    IwTrace(YAHOOGAMESADTRACK_VERBOSE, ("calling s3eYahooGamesAdTrack[3] func: ygnAdTrackTrackGetInstalledSource"));

    if (!_extLoadNoMsg())
        return YGN_ADTRACK_UNKNOWN;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int ret = g_Ext.m_ygnAdTrackTrackGetInstalledSource();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}