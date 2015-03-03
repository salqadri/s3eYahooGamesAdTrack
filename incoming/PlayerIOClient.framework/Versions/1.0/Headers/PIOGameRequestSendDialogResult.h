

#import <Foundation/Foundation.h>

/**
 The object that contains the result of the GameRequestSendDialog
 */
@interface PIOGameRequestSendDialogResult : NSObject

/**
 * The userIds of recipients that are already Yahoo users
 */
@property (readonly) NSArray* recipients;


-(NSArray*)recipients;

@end
