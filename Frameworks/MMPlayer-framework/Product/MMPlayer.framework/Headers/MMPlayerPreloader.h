//
//  MMPlayerPreloader.h
//  MMPlayer
//
//  Created by sunfei on 2019/4/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MMPlayerPreloader : NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)sharedInstance;

- (void)preloadVideoWithURL:(NSURL *)videoURL completion:(void(^)(BOOL success, NSError *error))completion;

- (void)preloadVideoWithURL:(NSURL *)videoURL preloadSize:(int)size preloadTime:(int)time completion:(void (^)(BOOL, NSError * _Nonnull))completion;

- (void)preloadVideos:(NSArray<NSURL *> *)videoURLs;

- (void)clearTask:(NSURL *)url;

- (void)cleanAllTask;

- (void)clearAllCache;

@end

NS_ASSUME_NONNULL_END
