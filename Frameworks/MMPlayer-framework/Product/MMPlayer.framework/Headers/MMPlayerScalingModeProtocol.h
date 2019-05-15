//
//  MMPlayerScalingModeProtocol.h
//  MMPlayer
//
//  Created by sunfei on 2019/4/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MMPlayerScalingModeProtocol <NSObject>

- (CGRect)makeRectWithAspectRatio:(CGSize)aspectRatio insideRect:(CGRect)boundingRect;

@end

NS_ASSUME_NONNULL_END
