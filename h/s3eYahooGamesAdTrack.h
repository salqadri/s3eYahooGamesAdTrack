/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_YAHOOGAMESADTRACK_H
#define S3E_EXT_YAHOOGAMESADTRACK_H

// YahooGamesAdTrack
// https://gamesnet.yahoo.net/

/**
 * General error codes.
 *
 * @par Required Header Files
 * s3eAmazonAds.h
 */
typedef enum ygnInstallSource
{
    YGN_ADTRACK_UNKNOWN             = 0,    ///< The install source is unrecognised
    YGN_ADTRACK_YAHOO               = 1,    ///< Yahoo was the source of this install
    YGN_ADTRACK_UNDETERMINED        = 2,    ///< Still determining the install source
} ygnInstallSource;

/**
 * This extension allows the application to utilize the Yahoo Games Network's AdTrack API
 *
 */
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Returns S3E_TRUE if the YahooGamesAdTrack extension is available.
 */
s3eBool s3eYahooGamesAdTrackAvailable();

/**
 * Call this when your application starts or enters the foreground
 *
 * @param gameId        The YGN gameId of your game.
 * @param playerInsightSegmentsArray        A '|' separated string of segments for PlayerInsight.
 */
void ygnAdTrackStart(const char* gameId, const char* playerInsightSegmentsArray);

/**
 * Call this when your application is ending or going into the background
 */
void ygnAdTrackStop();

/**
 * Call this when your application starts or enters the foreground
 *
 * @param currency      The currency the payment was made in, as an ISO currency code, i.e. "usd" for U.S. Dollars.
 * @param amount        The amount of the payment in the given currency, in minor units, i.e. cents if the currency was dollars.
 */
void ygnAdTrackTrackExternalPayment(const char* currency, int amount);

/**
 * Call this when your application starts or enters the foreground
 *
 * @return An enumeration identifying the source of the installation
 */
int ygnAdTrackTrackGetInstalledSource();

S3E_END_C_DECL

#endif /* !S3E_EXT_YAHOOGAMESADTRACK_H */
