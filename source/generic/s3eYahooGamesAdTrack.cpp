/*
Generic implementation of the s3eYahooGamesAdTrack extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eYahooGamesAdTrack_internal.h"
s3eResult s3eYahooGamesAdTrackInit()
{
    //Add any generic initialisation code here
    return s3eYahooGamesAdTrackInit_platform();
}

void s3eYahooGamesAdTrackTerminate()
{
    //Add any generic termination code here
    s3eYahooGamesAdTrackTerminate_platform();
}

void ygnAdTrackStart(const char* gameId, const char* playerInsightSegmentsArray)
{
	ygnAdTrackStart_platform(gameId, playerInsightSegmentsArray);
}

void ygnAdTrackStop()
{
	ygnAdTrackStop_platform();
}

void ygnAdTrackTrackExternalPayment(const char* currency, int amount)
{
	ygnAdTrackTrackExternalPayment_platform(currency, amount);
}

int ygnAdTrackTrackGetInstalledSource()
{
	return ygnAdTrackTrackGetInstalledSource_platform();
}
