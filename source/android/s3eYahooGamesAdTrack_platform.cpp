/*
 * android-specific implementation of the s3eYahooGamesAdTrack extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eYahooGamesAdTrack_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_ygnAdTrackStart;
static jmethodID g_ygnAdTrackStop;
static jmethodID g_ygnAdTrackTrackExternalPayment;
static jmethodID g_ygnAdTrackTrackGetInstalledSource;

s3eResult s3eYahooGamesAdTrackInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("s3eYahooGamesAdTrack");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_ygnAdTrackStart = env->GetMethodID(cls, "ygnAdTrackStart", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (!g_ygnAdTrackStart)
        goto fail;

    g_ygnAdTrackStop = env->GetMethodID(cls, "ygnAdTrackStop", "()V");
    if (!g_ygnAdTrackStop)
        goto fail;

    g_ygnAdTrackTrackExternalPayment = env->GetMethodID(cls, "ygnAdTrackTrackExternalPayment", "(Ljava/lang/String;I)V");
    if (!g_ygnAdTrackTrackExternalPayment)
        goto fail;

    g_ygnAdTrackTrackGetInstalledSource = env->GetMethodID(cls, "ygnAdTrackTrackGetInstalledSource", "()I");
    if (!g_ygnAdTrackTrackGetInstalledSource)
        goto fail;



    IwTrace(YAHOOGAMESADTRACK, ("YAHOOGAMESADTRACK init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(s3eYahooGamesAdTrack, ("One or more java methods could not be found"));
    }

    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);
    return S3E_RESULT_ERROR;

}

void s3eYahooGamesAdTrackTerminate_platform()
{ 
    // Add any platform-specific termination code here
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->DeleteGlobalRef(g_Obj);
    g_Obj = NULL;
}

void ygnAdTrackStart_platform(const char* gameId, const char* playerInsightSegmentsArray)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring gameId_jstr = env->NewStringUTF(gameId);
    jstring playerInsightSegmentsArray_jstr = env->NewStringUTF(playerInsightSegmentsArray);
    env->CallVoidMethod(g_Obj, g_ygnAdTrackStart, gameId_jstr, playerInsightSegmentsArray_jstr);
}

void ygnAdTrackStop_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_ygnAdTrackStop);
}

void ygnAdTrackTrackExternalPayment_platform(const char* currency, int amount)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring currency_jstr = env->NewStringUTF(currency);
    env->CallVoidMethod(g_Obj, g_ygnAdTrackTrackExternalPayment, currency_jstr, amount);
}

int ygnAdTrackTrackGetInstalledSource_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_ygnAdTrackTrackGetInstalledSource);
}
