/*
java implementation of the s3eYahooGamesAdTrack extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
// Comment in the following line if you want to use ResourceUtility
// import com.ideaworks3d.marmalade.ResourceUtility;

import com.ideaworks3d.marmalade.LoaderActivity;

class s3eYahooGamesAdTrack
{
    public void ygnAdTrackStart(String gameId, String playerInsightSegmentsArray)
    {
		String[] playerInsightSegments = null;
		if (playerInsightSegmentsArray != null) {
			playerInsightSegmentsArray.split("|");
		}
        com.playerio.PlayerIO.adTrack.start(LoaderActivity.m_Activity.getApplication(), gameId, playerInsightSegments, null);
        com.playerio.PlayerIO.adTrack.onResumeActivity(LoaderActivity.m_Activity);
    }
    public void ygnAdTrackStop()
    {
        com.playerio.PlayerIO.adTrack.onPauseActivity(LoaderActivity.m_Activity);
    }
    public void ygnAdTrackTrackExternalPayment(String currency, int amount)
    {
		try {
			com.playerio.PlayerIO.adTrack.trackExternalPayment(currency, amount);
		} catch (com.playerio.PlayerIOError ignored) {
			// Ignore error
		}
    }
    public int ygnAdTrackTrackGetInstalledSource()
    {
        return com.playerio.PlayerIO.adTrack.getInstallSource(LoaderActivity.m_Activity).ordinal();
    }
}
