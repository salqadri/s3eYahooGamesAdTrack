/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "s3eYahooGamesAdTrack_autodefs.h"
#include "s3eEdk.h"
#include "s3eYahooGamesAdTrack.h"
//Declarations of Init and Term functions
extern s3eResult s3eYahooGamesAdTrackInit();
extern void s3eYahooGamesAdTrackTerminate();


void s3eYahooGamesAdTrackRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[4];
    funcPtrs[0] = (void*)ygnAdTrackStart;
    funcPtrs[1] = (void*)ygnAdTrackStop;
    funcPtrs[2] = (void*)ygnAdTrackTrackExternalPayment;
    funcPtrs[3] = (void*)ygnAdTrackTrackGetInstalledSource;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[4] = { 0 };

    /*
     * Register the extension
     */
s3eEdkRegister("s3eYahooGamesAdTrack", funcPtrs, sizeof(funcPtrs), flags, s3eYahooGamesAdTrackInit, s3eYahooGamesAdTrackTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int s3eYahooGamesAdTrackStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&s3eYahooGamesAdTrackRegisterExt;
    return 0;
}

int g_s3eYahooGamesAdTrackVal = s3eYahooGamesAdTrackStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    s3eYahooGamesAdTrackRegisterExt();
}
#endif

#endif
