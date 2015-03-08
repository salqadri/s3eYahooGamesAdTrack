//
//  PIOOneScore.h
//  PlayerIOClient
//
//  Created by Arash Rassouli on 10/14/14.
//  Copyright (c) 2014 PlayerScale. All rights reserved.
//


@class PIOError;
@class PIOOneScoreValue;

/** The YGN OneScore service */
@interface PIOOneScore : NSObject

/** OneScore value */
@property (assign, nonatomic) int32_t score;

/** The percentile compared to all other players. A value from 0 -> 100. A value of 30.0 means you are in the bottom 30% of players. A value of 100 means you are in the top 100% with other players. */
@property (assign, nonatomic) float_t percentile;

/** The absolute ranking of this player, if they are one of the top 1000 players.  0 otherwise. */
@property (assign, nonatomic) int32_t topRank;

#pragma mark - refresh

/** Refresh OneScore for the user. */
- (void)refresh;

/**
 Refresh OneScore for the user.
 @param successBlock Callback that will be called when the operation succeeds.
 */
- (void)refreshWithSuccessBlock:(void (^)(PIOOneScoreValue* oneScoreValue))successBlock;

/**
 Refresh OneScore for the user.
 @param successBlock Callback that will be called when the operation succeeds.
 @param errorBlock Callback that will be called instead of successCallback if an error occurs during the operation.
 */
- (void)refreshWithSuccessBlock:(void(^)(PIOOneScoreValue* oneScoreValue))successBlock errorBlock:(void(^)(PIOError* error))errorBlock;

#pragma mark - set

/** 
 Sets OneScore for the user.
 @param scoreValue The score to set for the user.
 */
- (void)setWithScoreValue:(int32_t)scoreValue;

/** 
 Sets OneScore for the user.
 @param scoreValue The score to set for the user.
 @param successBlock Callback that will be called when the operation succeeds.
 */
- (void)setWithScoreValue:(int)scoreValue successBlock:(void (^)(PIOOneScoreValue* oneScoreValue))successBlock;

/**
 Sets OneScore for the user.
 @param scoreValue The score to set for the user.
 @param successBlock Callback that will be called when the operation succeeds.
 @param errorBlock Callback that will be called instead of successCallback if an error occurs during the operation.
 */
- (void)setWithScoreValue:(int)scoreValue successBlock:(void (^)(PIOOneScoreValue* oneScoreValue))successBlock errorBlock:(void (^)(PIOError *error))errorBlock;

#pragma mark - add

/**
 Sets OneScore for the user.
 @param scoreValue The score to add for the user.
 */
- (void)addWithScoreValue:(int32_t)scoreValue;

/**
 Sets OneScore for the user.
 @param scoreValue The score to add for the user.
 @param successBlock Callback that will be called when the operation succeeds.
 */
- (void)addWithScoreValue:(int32_t)scoreValue successBlock:(void (^)(PIOOneScoreValue* oneScoreValue))successBlock;

/**
 Sets OneScore for the user.
 @param scoreValue The score to add for the user.
 @param successBlock Callback that will be called when the operation succeeds.
 @param errorBlock Callback that will be called instead of successCallback if an error occurs during the operation.
 */
- (void)addWithScoreValue:(int32_t)scoreValue successBlock:(void (^)(PIOOneScoreValue* oneScoreValue))successBlock errorBlock:(void(^)(PIOError *error))errorBlock;

#pragma mark - load


/**
 Loads OneScore for multiple users.
 @param userIds Array of user ids (NSString) to load OneScore for
 */
- (NSArray*)loadWithUserIds:(NSArray*)userIds;

/** 
 Loads OneScore for multiple users.
 @param userIds Array of user ids (NSString) to load OneScore for
 @param successBlock Callback that will be called when the operation succeeds.
*/
- (void)loadWithUserIds:(NSArray*)userIds successBlock:(void(^)(NSArray* oneScoreValues))successBlock;


/**
 Loads OneScore for multiple users.
 @param userIds Array of user ids (NSString) to load OneScore for
 @param successBlock Callback that will be called when the operation succeeds.
 @param errorBlock Callback that will be called instead of successCallback if an error occurs during the operation.
 */
- (void)loadWithUserIds:(NSArray*)userIds successBlock:(void(^)(NSArray* oneScoreValues))successBlock errorBlock:(void(^)(PIOError* error))errorBlock;

@end
