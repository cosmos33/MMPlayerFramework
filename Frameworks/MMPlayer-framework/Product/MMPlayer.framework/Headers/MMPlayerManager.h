//
//  MMPlayerManager.h
//  MMPlayer
//
//  Created by sunfei on 2019/4/17.
//

#import <Foundation/Foundation.h>

@class MMPlayer;
@class MMPlayerPreloader;
@protocol MMIPlayerLogger;

#define __MMPlayerLogDebug__(fmt, ...)        __MDLogDebugTag(KMMPlayerTag, fmt, ##__VA_ARGS__)

extern NSString * const KMMPlayerTag;

@class MMPlayerConfiguratinonModel;

NS_ASSUME_NONNULL_BEGIN

@interface MMPlayerManager : NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (void)initSDKWithAppId:(NSString *)appId;

+ (void)fetchConfig;

+ (void)configUserAgent:(NSString *)userAgent;
+ (NSString *)userAgent;

+ (void)configCachePath:(NSString *)cachePath;
+ (NSString *)cachePath;

+ (void)configCacheSpaceLimit:(int)size;
+ (int)cacheSpaceLimit;

+ (void)clearAllCache;

+ (NSString *)appId;

+ (NSString *)version;

+ (MMPlayerConfiguratinonModel *)playerConfiguration;

@end

@interface MMPlayerManager (MMPlayerLogger)

+ (void)openDebugLog:(BOOL)console dir:(NSString * _Nullable)dir;

+ (void)openLogAnalyze:(BOOL)toggle;

+ (id<MMIPlayerLogger>)playerLogger;

@end

NS_ASSUME_NONNULL_END
