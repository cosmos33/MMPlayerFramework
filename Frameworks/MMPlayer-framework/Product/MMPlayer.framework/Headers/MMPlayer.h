//
//  MMPlayer.h
//  MMPlayer
//
//  Created by sunfei on 2019/4/17.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <MediaPlayer/MediaPlayer.h>

@class MMPlayer;

NS_ASSUME_NONNULL_BEGIN

@protocol MMPlayerDelegate <NSObject>

@optional
// 加载准备好可以播放了
- (void)player:(MMPlayer *)player isReadyToPlayWithDuration:(NSTimeInterval)duration;

// 播放器开始渲染
- (void)player:(MMPlayer *)player startRenderingWithVideoSize:(CGSize)videoSize;

// 加载失败
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

@end

@interface MMPlayer : NSObject

@property (nonatomic, weak) id<MMPlayerDelegate> delegate;

- (void)prepareToPlay:(NSURL *)url;

@property (nonatomic, readonly) BOOL isPreparedToPlay;

- (void)play;
- (void)pause;
- (void)stop;

@property (nonatomic, assign) BOOL autoPlay;
@property (nonatomic, assign) CGFloat volume;
@property (nonatomic, assign) BOOL needProgress;

- (BOOL)isPlaying;

- (void)seekTo:(NSTimeInterval)time;

- (NSTimeInterval)currentPosition;
- (NSTimeInterval)duration;
- (NSTimeInterval)playableDuration;

- (void)enableLoop:(BOOL)enable;
- (void)setMute:(BOOL)mute;

- (void)enableHardDecode:(BOOL)isEnable;

- (CGSize)videoSize;
- (CGSize)videoResolution;
@property (nonatomic, readonly) NSDictionary *mediaMetadata;

- (void)setDisplaySize:(CGSize)size;
- (void)setScaleMode:(MPMovieScalingMode)mode;
- (UIView *)renderView;

- (UIImage *)snapshot;

@property(nonatomic, readonly)  MPMoviePlaybackState playbackState;
@property(nonatomic, readonly)  MPMovieLoadState loadState;

@end

NS_ASSUME_NONNULL_END
