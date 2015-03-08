//
//  PIOOneScoreValue.h
//  PlayerIOClient
//
//  Created by Arash Rassouli on 10/15/14.
//  Copyright (c) 2014 PlayerScale. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PIOOneScoreValue : NSObject

@property (assign, nonatomic) int32_t score;
@property (assign, nonatomic) float percentile;
@property (assign, nonatomic) int32_t topRank;


- (id)initWithScoreValue:(int32_t)scoreValue
         percentileValue:(float)percentileValue
            topRankValue:(int32_t)topRankValue;

@end
