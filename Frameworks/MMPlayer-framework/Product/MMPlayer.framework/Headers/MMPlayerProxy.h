//
//  MMPlayerProxy.h
//  MMPlayer
//
//  Created by sunfei on 2019/4/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



@interface MMPlayerProxy : NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)sharedInstance;

- (BOOL)isRunning;
- (BOOL)isStarted;
- (BOOL)isListening;

// build proxy url
- (NSString *)buildVodProxyURL:(NSURL *)url key:(NSString *)key header:(NSString *)header;

// preload
- (int)addPreloadTask:(NSURL *)url
                  key:(NSString *)key
          preloadSize:(int)size
     preloadTimeLimit:(int)time
               finish:(void(^)(NSString *key, BOOL success, NSError *error))finish;
- (void)clearPreloadTask:(int)taskID;
- (void)clearAllPreloadTask;
- (void)pauseAllPreloadTask;
- (void)resumeAllPreloadTask;

// cache
- (BOOL)isCacheExist:(NSString *)key;
- (BOOL)isCacheCompleted:(NSString *)key;
- (void)removeAllCache;
- (void)removeCacheWithKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
