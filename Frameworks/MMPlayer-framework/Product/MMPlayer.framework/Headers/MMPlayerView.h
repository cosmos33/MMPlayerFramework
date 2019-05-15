//
//  MMPlayerView.h
//  MMPlayer
//
//  Created by sunfei on 2019/4/17.
//

#import <UIKit/UIKit.h>
#import "MMPlayer.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MMPlayerViewScalingMode) {
    MMPlayerViewScalingModeNone,                // 居中
    MMPlayerViewScalingModeAspectFit,           // 等比适应
    MMPlayerViewScalingModeAspectFill,          // 等比填充
    MMPlayerViewScalingModeFill                 // 填充
};

@class MMPlayerView;

@protocol MMPlayerViewDelegate <NSObject>

@optional
// 加载准备好可以播放了
- (void)playerView:(MMPlayerView *)player isReadyToPlayWithDuration:(NSTimeInterval)duration;

// 播放器开始渲染
- (void)playerView:(MMPlayerView *)player startRenderingWithVideoSize:(CGSize)videoSize;

// 加载失败
- (void)playerView:(MMPlayerView *)player isFailedLoadWithError:(NSError *)error;

// 播放进度(回调频率30Hz)
- (void)playerView:(MMPlayerView *)player playToSeconds:(NSTimeInterval)seconds;

// 播放卡顿开始
- (void)playerViewStartStalling:(MMPlayerView *)player;

// 播放卡顿结束
- (void)playerViewEndStalling:(MMPlayerView *)player;

// 播放结束
- (void)playerViewIsPlayToEnd:(MMPlayerView *)player;

// 即将开始循环播放
- (void)playerViewWillStartLoop:(MMPlayerView *)player;

// 视频尺寸改变
- (void)playerView:(MMPlayerView *)player playerDidVideoSizeChanged:(CGSize)videoSize;

// 视频分辨率
- (void)playerView:(MMPlayerView *)player playerDidGetVideoResolution:(CGSize)videoResolution;

@end

@interface MMPlayerView : UIView

@property (nonatomic, weak) id<MMPlayerViewDelegate> delegate;
@property (nonatomic, assign) MMPlayerViewScalingMode scalingMode;

@property (nonatomic, assign) BOOL autoPlay;

@property (nonatomic, readonly) MMPlayer *player;

- (void)seekTo:(NSTimeInterval)time;

- (void)prepareToPlay:(NSURL *)videoURL;
- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)isPlaying;
- (void)seekTo:(NSTimeInterval)time;

- (void)setMute:(BOOL)mute;
- (void)enableLoop:(BOOL)loop;
- (void)enableHardDecode:(BOOL)enable;

- (void)enableProgress:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
