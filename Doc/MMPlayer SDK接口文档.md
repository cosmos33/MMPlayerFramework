# MMVideoPlayer 接口文档

## 配置相关

* 初始化SDK

```c
+ (void)initSDKWithAppId:(NSString *)appId;
+ (NSString *)appId;
```

* 设置User-Agent

```c
+ (void)configUserAgent:(NSString *)userAgent;
+ (NSString *)userAgent;
```

* 设置视频缓存路径

```c
+ (void)configCachePath:(NSString *)cachePath;
+ (NSString *)cachePath;
```

* 设置缓存空间大小

```c
+ (void)configCacheSpaceLimit:(int)size;
+ (int)cacheSpaceLimit;
```

* 清除视频缓存

```c
+ (void)clearAllCache;
```

* 获取SDK版本号

```c
- (NSString *)version;
```

## 日志

* 打开调试日志

```c
- (void)openDebugLog:(BOOL)console dir:(NSString)path;
```

* 打点日志开启

```c
- (void)openLogAnalyze:(BOOL)toggle;
```

## 预加载

* 添加预加载任务

```c
- (void)preloadVideoWithURL:(NSURL *)videoURL completion:(void(^)(BOOL success, NSError *error))completion;

- (void)preloadVideoWithURL:(NSURL *)videoURL preloadSize:(int)size preloadTime:(int)time completion:(void (^)(BOOL, NSError * _Nonnull))completion;

```

* 批量下载

```c
- (void)preloadVideos:(NSArray<NSURL *> *)videoURLs;
```

* 取消某个预加载任务

```c
- (void)clearTask:(NSURL *)url;
```

* 清空预加载任务

```c
- (void)cleanAllTask;
```

* 清空缓存

```c
- (void)clearAllCache;
```

## 播放控制

* 设置代理

```c
@property (nonatomic, weak) id<MMPlayerDelegate> delegate;
```

* 准备播放

```c
- (void)prepareToPlay:(NSURL *)url;
```

* 是否已经准备好播放

```c
@property (nonatomic, assign) BOOL isPreparedToPlay;
```

* 播放当前视频

```c
- (void)play;
```

* 暂停播放当前视频

```c
- (void)pause;
```

* 销毁当前播放器

```c
- (void)stop;
```

* 是否自动播放

```c
@property (nonatomic, strong) BOOL autoPlay;
```

* 调整视频音量

```c
@property (nonatomic, assign) CGFloat volume;
```

* 是否需要进度控制

```c
@property (nonatomic, assign) BOOL needProgress;
```

* 是否正在播放

```c
- (BOOL)isPlaying;
```

* 跳转到播放位置

```c
- (void)seekTo:(NSTimeInterval)time;
```

* 获取当前视频播放位置

```c
- (NSTimeInterval)currentPosition;
```

* 获取视频时长

```c
- (NSTimeInterval)duration;
```

* 可播放时长

```c
- (NSTimeInterval)playableDuration;
```

* 循环播放控制

```c
- (void)enableLoop:(BOOL)enable;
```

* 设置静音

```c
- (void)setMute:(BOOL)mute;
```

* 启用硬解码

```c
- (void)enableHardDecode:(BOOL)isEnable;
```

* 获取视频size

```c
- (CGSize)videoSize;
```

* 获取视频元信息

```c
@property (nonatomic, copy) NSDictionary *mediaMetadata;
```

* 设置播放区域大小

```c
- (void)setDisplaySize:(CGSize)size;
```

* 设置视频渲染缩放模式

```c
- (void)setPlayerScalingMode:(MPMovieScalingMode)mode;
```

* 获取视频view

```c
- (UIView *)renderView;
```

* 截屏

```c
- (UIImage *)snapshot;
```

* 获取播放器状态

```c
@property(nonatomic, readonly)  MPMoviePlaybackState playbackState;
```

* 视频加载状态

```c
@property(nonatomic, readonly)  MPMovieLoadState loadState;
```

## 播放器代理

```c
// 加载准备好可以播放了
- (void)player:(MMPlayer *)player isReadyToPlayWithDuration:(NSTimeInterval)duration;

// 播放器首帧渲染
- (void)player:(MMPlayer *)player startRenderingWithVideoSize:(CGSize)videoSize;

// 视频加载失败
- (void)player:(MMPlayer *)player isFailedLoadWithError:(NSError *)error;

// 播放进度(回调频率30Hz)
- (void)player:(MMPlayer *)player playToSeconds:(NSTimeInterval)seconds;

// 播放卡顿开始
- (void)playerStartStalling:(MMPlayer *)player;

// 播放卡顿结束
- (void)playerEndStalling:(MMPlayer *)player;

// 播放结束
- (void)playerIsPlayToEnd:(MMPlayer *)player;

// 即将开始循环播放
- (void)playerWillStartLoop:(MMPlayer *)player;

// 视频尺寸改变
- (void)player:(MMPlayer *)player playerDidVideoSizeChanged:(CGSize)videoSize;

// 视频分辨率
- (void)player:(MMPlayer *)player playerDidGetVideoResolution:(CGSize)videoResolution;

// 视频窗口尺寸改变
- (void)player:(MMPlayer *)player playerDidVideoWindowSizeChanged:(CGSize)videoSize;
```