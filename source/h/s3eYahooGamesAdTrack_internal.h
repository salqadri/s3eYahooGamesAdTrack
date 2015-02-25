/*
 * Internal header for the s3eYahooGamesAdTrack extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef S3EYAHOOGAMESADTRACK_INTERNAL_H
#define S3EYAHOOGAMESADTRACK_INTERNAL_H

#include "s3eTypes.h"
#include "s3eYahooGamesAdTrack.h"
#include "s3eYahooGamesAdTrack_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult s3eYahooGamesAdTrackInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult s3eYahooGamesAdTrackInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void s3eYahooGamesAdTrackTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void s3eYahooGamesAdTrackTerminate_platform();
void ygnAdTrackStart_platform(const char* gameId, const char* playerInsightSegmentsArray);

void ygnAdTrackStop_platform();

void ygnAdTrackTrackExternalPayment_platform(const char* currency, int amount);

int ygnAdTrackTrackGetInstalledSource_platform();


#endif /* !S3EYAHOOGAMESADTRACK_INTERNAL_H */