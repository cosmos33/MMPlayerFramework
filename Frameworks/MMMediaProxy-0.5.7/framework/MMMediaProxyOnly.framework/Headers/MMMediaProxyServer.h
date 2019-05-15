//
//  MMMediaProxyServer.h
//  MMMediaProxy
//
//  Created by shuyj on 2017/8/30.
//  Copyright © 2017年 shuyj. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDownTaskTime : NSObject

@property (nonatomic, assign)NSInteger      mTaskId;
@property (nonatomic, assign)NSInteger      mReadDataUsedTime;
@property (nonatomic, assign)NSInteger      mTaskEndUsedTime;

@end

@interface MSessionRequestDescription : NSObject
@property (nonatomic, strong)NSString*                  mSessionId;     // 回话id 用于区分多个请求是否为一次播放
@property (nonatomic, assign)uint64_t                   mReqStartTime;     // 收到请求的时间 ms
@property (nonatomic, strong)NSString*                  mReqUrl;           // 收到请求的url
@property (nonatomic, assign)int64_t                    mReqRangeStart;    // 请求中range start
@property (nonatomic, assign)int64_t                    mReqRangeEnd;      // 请求中range end
@property (nonatomic, strong)NSString*                  mReqKey;           // 请求url中 携带的key  用于唯一标识内容

@property (nonatomic, strong)NSString*                  mDownloadUrl;   // 组合之后的用于下载数据的url
@property (nonatomic, assign)BOOL                       mIsHttps;       // 用于下载数据的url是否为https
@property (nonatomic, strong)NSString*                  mDownloadUrlHeader;     // 用于下载数据的url，请求时使用的header
@property (nonatomic, assign)uint64_t                   mReqContentSize;   // 请求的内容的Size

@property (nonatomic, strong)NSMutableArray*            mReqTaskList;      // 本次请求产生的下载任务id 列表
@property (nonatomic, strong)NSMutableArray<MDownTaskTime*>*            mTaskUsedTime;  // 记录每次下载任务 自添加后 到 读取到下载的数据 用时

@property (nonatomic, assign)NSInteger                  mResHttpCode;       // 请求回复的http code
@property (nonatomic, assign)uint64_t                   mResContentLen;     // 响应的数据长度
@property (nonatomic, strong)NSString*                  mResContentRange;   // 响应的content-range

@property (nonatomic, assign)NSInteger                  mContentSizeRetryCnt;  // 读取ContentSize中 尝试的次数
@property (nonatomic, assign)NSInteger                  mContentDataRetryCnt;   // 读取 内容中 失败时 尝试的次数 取最大值

// 时间统计
@property (nonatomic, assign)uint32_t                   mParseReqUsedTime;      // 解析请求头耗时 包括读取全局配置 解析url 解析range
@property (nonatomic, assign)uint32_t                   mContentSizeUsedTime;   // 获取ContentSize耗时
@property (nonatomic, assign)uint32_t                   mBuildResUsedTime;      // 组装响应头用时
@property (nonatomic, assign)uint32_t                   mFirstPktUsedTime;      // 回复首包用时  自上一统计结束
@property (nonatomic, assign)uint32_t                   mResEOFUesdTime;        // 全部发送完毕并关闭用时

@property (nonatomic, assign)uint64_t                   mSendDataBytes;         // 发送数据总量 不包含响应头
@end

typedef enum: int8_t {
    SESSION_EVENT_TYPE_INVALID = -1,
    SESSION_EVENT_TYPE_LIVE_START_RESULT,
    SESSION_EVENT_TYPE_LIVE_STOP_RESULT,
    SESSION_EVENT_TYPE_VOD_START_RESULT,
    SESSION_EVENT_TYPE_VOD_STOP_RESULT
} SESSION_EVENT_TYPE;


@interface MMMediaProxyServer : NSObject

typedef void(^SessionEventBlock)(SESSION_EVENT_TYPE sessionEvent, NSMutableDictionary *sessionInfo);
// 获取实例对象 单例
+ (instancetype)instance;

- (instancetype)init NS_UNAVAILABLE;

// 设置Proxy
-(int) setupProxyWithConfig:(NSString*) configPath
        address:(NSString*)address
        port:(uint16_t) port
        serverThreadNumber:(NSUInteger)serverThreadNumber;

// 开启app后台ProxyServer控制，在没有background mode的app上使用
-(void) setupProxyGuard;

// app terminate通知
-(void) applicationWillTerminate;

// 开启http server session信息日志
-(void) debugHttpSessionLog:(BOOL) onSessionLog;

// 设置app内部版本号
-(void) setInternalVersion:(NSString*) internalVersion;

// 启动Proxy
-(int)start;

// 停止Proxy
-(int)stop;

-(int)restart;

// 通过HEAD请求验证是否可用，需要少量时间
- (BOOL)isRunning;

// 根据状态位判断是否已启动，快速返回
- (BOOL)isStarted;

// http接口是否在listening状态，较快返回
- (BOOL)isListening;

-(void)addSessionEventBlock:(SessionEventBlock)block;

-(void)clearSessionEventBlock;

-(void)setRelease:(BOOL)release;

@end
