//
//  MMMediaProxyAgent.h
//  MMMediaProxyAgent
//
//  Created by shuyj on 2017/8/30.
//  Copyright © 2017年 shuyj. All rights reserved.
//
#import <Foundation/Foundation.h>
/*
 下载任务信息
 */
@interface MDownloadTaskDescription : NSObject

@property (nonatomic, strong)NSString*    url;           // 下载任务url
@property (nonatomic, assign)uint64_t     start_time;    // 开始下载时间   1970 至今  毫秒
@property (nonatomic, assign)uint64_t     end_time;      // 结束下载时间   1970 至今  毫秒
@property (nonatomic, assign)uint64_t     http_range_start;      // 下载内容起始位置
@property (nonatomic, assign)uint64_t     http_range_end;        // 下载内容结束位置
@property (nonatomic, assign)int          task_errno;         // 结束错误码
@property (nonatomic, assign)uint32_t     dns_time;      // dns解析耗时 毫秒
@property (nonatomic, assign)uint32_t     tcp_connect_time;  // tcp连接耗时 ms
@property (nonatomic, assign)uint32_t     http_header_time;         // http收到响应头 时间  ms
@property (nonatomic, assign)uint32_t     http_code;         // http状态码
@property (nonatomic, assign)uint32_t     http_content_time; // http收到消息体时间  ms
@property (nonatomic, strong)NSString*    cdn_ip;            // cdn ip
@property (nonatomic, assign)uint64_t     total_download_bytes;  // 下载任务总下载字节数
    // ========================以上为哈你收集信息=============================================
@property (nonatomic, assign)int          status;                // 任务状态   enum TASK_STATUS
@property (nonatomic, assign)int          priority;              // 优先级     enum TASK_PRIORITY
@property (nonatomic, assign)uint32_t     limit_rate;            // 限速值
@property (nonatomic, assign)uint32_t     rate;                  // 当前速度
@property (nonatomic, assign)uint32_t     wait_time;             // 进入队列到开始下载 等待的时间 ms
@property (nonatomic, strong)NSString*    identity;              // 内容唯一标识 key
@property (nonatomic, assign)int          task_id;               // 任务id

@property (nonatomic, strong)NSString*    documents;

@end

@interface MDownloadLiveHttpTaskResult : NSObject

@property (nonatomic, strong, readonly)NSString*    sessionId;           // 下载任务sessionId
@property (nonatomic, strong, readonly)NSString*    key;           // 下载任务key
@property (nonatomic, assign, readonly)NSInteger    taskId;               // 任务id
@property (nonatomic, assign, readonly)NSInteger    transferType;               // 任务传输类型
@property (nonatomic, assign, readonly)NSInteger    endCode;               // 任务结束码
@property (nonatomic, strong, readonly)NSString*    endReason;           // 任务结束原因说明
@property (nonatomic, assign, readonly)NSInteger    httpStatusCode;      // Http任务返回状态码
@property (nonatomic, strong, readonly)NSString*    url;           // 下载任务url
@property (nonatomic, strong, readonly)NSString*    remoteIp;           // http返回远端Ip
@property (nonatomic, assign, readonly)NSInteger    downloadedBytes;      // Http任务下载数据量

-(NSString*) toJson;
@end

typedef enum : int8_t {
    TASK_EVENT_TYPE_INVALID = -1,
    TASK_EVENT_TYPE_LIVE_P2P_START_RESULT,
    TASK_EVENT_TYPE_LIVE_P2P_STOP_RESULT,
    TASK_EVENT_TYPE_LIVE_P2P_PUNCH_RESULT,
    TASK_EVENT_TYPE_LIVE_HTTP_START_RESULT,
    TASK_EVENT_TYPE_LIVE_HTTP_STOP_RESULT,
    TASK_EVENT_TYPE_LIVE_P2P_SHARED_START_RESULT,
    TASK_EVENT_TYPE_LIVE_P2P_SHARED_STOP_RESULT,
    TASK_EVENT_TYPE_VOD_P2P_RESULT,
    TASK_EVENT_TYPE_VOD_HTTP_RESULT,
    TASK_EVENT_TYPE_LIVE_HTTP_TEST,
    TASK_EVENT_TYPE_LIVE_P2P_TEST,
    TASK_EVENT_TYPE_LIVE_QUIC,
    TASK_EVENT_TYPE_LIVE_QUIC_TEST,
    TASK_EVENT_TYPE_LIVE_QUIC_START_RESULT,
    TASK_EVENT_TYPE_LIVE_QUIC_STOP_RESULT,
    TASK_EVENT_TYPE_LIVE_QUIC_WATCH_INFO,
    TASK_EVENT_TYPE_LIVE_QUIC_SEND_ERROR,
    TASK_EVENT_TYPE_LIVE_QUIC_START_CONN,
    TASK_EVENT_TYPE_LIVE_QUIC_CONN_SUCCESS
}TASK_EVENT_TYPE;

typedef enum : int8_t {
    TASK_TRANSFER_TYPE_INVALID = -1,
    
    // P2P 下载
    TASK_TRANSFER_TYPE_P2P = 0,
    
    // HTTP 下载
    TASK_TRANSFER_TYPE_HTTP = 1,
    
    // 直播
    TASK_TRANSFER_TYPE_HTTP_P2P = 2,
    
    // quic下载
    TASK_TRANSFER_TYPE_QUIC = 3,
    
    // 纯P2P预加载
    TASK_TRANSFER_TYPE_PRELOAD_P2P = 4,
    
    // 先P2P后HTTP
    TASK_TRANSFER_TYPE_PRELOAD_P2P_FIRST = 5,
} TASK_TRANSFER_TYPE;

typedef enum: int8_t
{
    NETWORK_TYPE_UNKNOWN = -1,
    NETWORK_TYPE_WIFI = 1,
    NETWORK_TYPE_3G = 2,
    NETWORK_TYPE_4G = 3
} NETWORK_TYPE;

typedef enum : int {
    TASK_END_REASON_CODE_NO_END = 0,      //初始
    TASK_END_REASON_CODE_NOT_CONNECT,     //connect出错
    TASK_END_REASON_CODE_READ_ERROR,      //read出错
    TASK_END_REASON_CODE_COMPLETE,        //下载完成
    TASK_END_REASON_CODE_GET_FILESIZE_FAILED,//获取文件大小失败
    TASK_END_REASON_CODE_REMOVE,          //被删除
    TASK_END_REASON_CODE_PAUSE,           //被暂停
    TASK_END_REASON_CODE_WRITE_FAILED,    //写磁盘失败
    TASK_END_REASON_CODE_SEEK_ERROR,      //seek错误
    TASK_END_REASON_CODE_MEMORY_ERROR,    //内存错误
} TASK_END_REASON_CODE;

@interface MMMediaProxyAgent: NSObject

typedef void(^TaskEventBlock)(TASK_EVENT_TYPE taskEvent, NSMutableDictionary *taskInfo);

typedef void(^ProxyEventBlock)(NSString* eventInfo);

// 获取实例对象 单例
+ (instancetype)instance;

- (instancetype)init NS_UNAVAILABLE;

-(void) configMDLog;
// 设置代理配置
-(int) setProxyConfig:(NSString*) configJson;
// 设置p2p配置
-(int) setP2pConfig:(NSString*) configJson;

// 转换播放地址为代理地址[playUrl UTF8String], [[[NSURL URLWithString:playUrl] host] UTF8String]
-(NSString*) playUrlToProxyUrl:(NSString*) playUrl key:(NSString*)key header:(NSString*)header isLive:(BOOL)isLive;

// 设置Cache
-(int) setupCacheWithPath:(NSString*) cachePath;

// 设置Preload
-(int) setupPreloadWithThreadNumber:(NSUInteger) threadNumber;
// 设置PeerId, 一般使用momoId
-(void) setPeerId:(NSString*) momoId;
// 登录认证session
-(void) setSession:(NSString*) cryptoSession;
// 指定使用哪一种IM类型
-(void) setSignalClientMethod:(NSUInteger) signalClientMethod;
// 添加点播p2p信令服务器地址
-(void) addVodSignalServer:(NSString*)ipaddress;
// 添加直播p2p信令服务器地址
-(void) addLiveSignalServer:(NSString*)ipaddress;
// 清空当前点播SignalServers列表
-(void) clearVodSignalServers;
// 清空当前直播SignalServers列表
-(void) clearLiveSignalServers;

// 重新登录点播信令服务器
-(void)reLoginVodSignalServer;

// 退出点播信令服务器
-(void)logoutVodSignalServer;

// 重新登录直播信令服务器
-(void) reLoginLiveSignalServer;

// 设置点播p2p的tracker服务器地址
-(void) setTrackerServer:(NSString*)trackerServer;
// 添加p2p穿透使用的stunServer地址
-(void) addStunServer:(NSString*)stunServer;
// 启动点播p2p
-(int) startVodPeerManager;
// 停止点播p2p
-(int) stopVodPeerManager;
// 启动直播p2p
-(int) startLivePeerManager;
// 停止直播p2p
-(int) stopLivePeerManager;
// 进入直播间
-(void) enterLiveRoom:(NSString*) roomId key:(NSString*) k;
// 离开直播间 根据roomId
-(void) leaveLiveRoom:(NSString*) roomId key:(NSString*) k;
// 离开直播间
-(void) leaveLiveRoom;
// 设置推流状态
-(void) setPushState:(int) state;
// 更新定位gps地址， 例: 0,0
-(void) setLocation:(NSString*) loc;
// 设置直播间id
-(void) setRoomId:(NSString*) roomId;
// 设置设备唯一id
-(void) setDeviceId:(NSString*) deviceId;
// 设置设备服务能力
-(void) setAbilityWithCpu:(NSUInteger) cpu mem:(NSUInteger) memory;
// 设置http协议user-Agent
-(void) setUserAgent:(NSString*)userAgent;

// 更新播放器可播放时长，用于直播p2p，由于播放器会删减缓存，直接从播放器获取当前剩余缓冲
-(void) updatePlayerCacheDurationWithSession:(NSString*) sessionId duration:(long) nplayableDuration;

// 获取直播任务当前传输模式
-(int) currentLiveTransferType;

// 设置当前网络类型
-(void) changeNetworkType:(NETWORK_TYPE)networkType;

// 开启debug preload信息输出
- (void) debugPreloadLog:(NSUInteger) intervalMs;

// 开启preload task任务信息日志
-(void) debugPreloadTaskLog:(BOOL) onTaskLog;

// 添加任务事件回调
-(void)addPreloadEventBlock:(TaskEventBlock)block;

// 清除任务所有回调
-(void)clearPreloadEventBlock;

// 添加代理事件回调
-(void)addProxyEventBlock:(ProxyEventBlock)block;

// 清除代理事件回调
-(void)clearProxyEventBlock;
/*  任务相关  */

/*添加下载任务*/
/**
 @param priority 范围 0~2
 */
-(int) addPreloadTaskWithRangeSize:(NSString*)preloadURL
                           fileKey:(NSString*)fileKey
                        rangeStart:(uint64_t)rangeStart
                         rangeSize:(uint64_t) rangeSize
                        httpHeader:(NSString*)httpHeader
                      taskPriority:(int) priority
                         limitRate:(uint64_t) limitRate;
-(int) addPreloadTaskWithRangeSize:(NSString*)preloadURL
                           fileKey:(NSString*)fileKey
                        rangeStart:(uint64_t)rangeStart
                         rangeSize:(uint64_t) rangeSize
                        httpHeader:(NSString*)httpHeader
                      taskPriority:(int) priority
                         limitRate:(uint64_t) limitRate
                      TransferType:(TASK_TRANSFER_TYPE)transferType;
-(int) addPreloadTaskWithPreloadDuration:(NSString*)preloadURL
                                 fileKey:(NSString*)fileKey
                              rangeStart:(uint64_t)rangeStart
                               rangeSize:(uint64_t) rangeSize
                            milliSeconds:(uint64_t) preloadMilliSeconds
                              httpHeader:(NSString*)httpHeader
                            taskPriority:(int) priority
                               limitRate:(uint64_t) limitRate;
-(int) addPreloadTaskWithPreloadDuration:(NSString*)preloadURL
                                 fileKey:(NSString*)fileKey
                              rangeStart:(uint64_t)rangeStart
                               rangeSize:(uint64_t) rangeSize
                            milliSeconds:(uint64_t) preloadMilliSeconds
                              httpHeader:(NSString*)httpHeader
                            taskPriority:(int) priority
                               limitRate:(uint64_t) limitRate
                            TransferType:(TASK_TRANSFER_TYPE)transferType;
/*对已经添加的任务限速*/
-(int) limitRateWithTaskId:(NSInteger) taskId limitRate:(uint64_t) limitRate;
/*删除一个任务*/
-(int) removePreloadTaskWithId:(NSInteger) taskId;
/*删除fileKey对应的所有任务*/
//-(int) removePreloadTaskWithFileKey:(NSString*) fileKey;
/*暂停一个任务*/
-(int) pausePreloadTaskWithId:(NSInteger) taskId;
/*暂停fileKey对应的所有任务*/
//-(int) pausePreloadTaskWithFileKey:(NSString*)fileKey;
/*恢复一个任务*/
-(int) resumePreloadTaskWithId:(NSInteger) taskId;
/*恢复fileKey对应的所有任务*/
//-(int) resumePreloadTaskWithFileKey:(NSString*) fileKey;
/*清除所有任务*/
-(int) clearAllTask;
/*暂停所有任务*/
-(int) pauseAllTask;
/*恢复所有任务*/
-(int) resumeAllTask;

/*清除预加载（T1T2）任务*/
-(int) clearPreloadTask;
/*暂停预加载（T1T2）任务*/
-(int) pausePreloadTask;
/*恢复预加载（T1T2）任务*/
-(int) resumePreloadTask;

/* 缓存是否存在 */
-(BOOL) isCacheExist:(NSString*) fileKey;
/* 缓存是否完整 */
-(BOOL) isCacheComplete:(NSString*) fileKey;

// 清除过期缓存
-(int) clearCache;
// 清除所有缓存
-(void) clearAllCache;
// 清理指定文件的缓存
-(int) clearCacheWithKey:(NSString*) fileKey;

// 关闭代理日志
-(void)shutdownProxyLog;

/*返回list中处于status状态的数量*/
/**
 @param status  任务状态 0 ~ 6 init starting paused delay_remove complete remove server_started
 */
-(int) getTaskCount:(int) status;
/*获取总下载量*/
-(uint64_t) getAllDownloadedBytes;
/*获取总下载速率*/
-(uint64_t) getCurAllDownloadRate;
//quic
-(void) setQuicServer:(NSString*)server
                 port:(int)port;



-(void) setDocuments:(NSString*) documents;

- (void)setDisableIPv6ForFFmpeg:(BOOL)disable;

@end
