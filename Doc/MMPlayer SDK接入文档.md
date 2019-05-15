# MMPlayer SDK 接入文档

接入方可以通过两种方式进行接入:

## 通过MMPlayer类进行接入

* 初始化MMPlayer

```c
    // 初始化MMPlayer
    self.player = [[MMPlayer alloc] init];
    // 设置MMPlayer代理
    self.player.delegate = self;

    // 获取renderView, 并将renderView加入视图层级中
    UIView *renderView = self.player.renderView;
    [self addSubview:renderView];
    // 设置Player显示方式
    [self.player setScaleMode:MPMovieScalingModeFill];
    // 设置renderView的宽高
    [self.player setDisplaySize:displayRect.size];
```

* 加载播放视频

```c
    [self.player prepareToPlay:videoURL];
```

* 视频播放控制

```c
    // 开始播放视频
    [self.player play];
    // 暂停播放视频
    [self.player pause];
```

* 进度控制

```c
    [self.player seekTo:time];
```

* 循环控制

```c
    [self.player enableLoop:loop];
```

## 通过MMPlayerView类进行接入

* 初始化

```c
    // 初始化PlayerView
    MMPlayerView *playerView = [[MMPlayerView alloc] initWithFrame:self.view.bounds];
    // 设置代理
    playerView.delegate = self;
    // 设置自动播放
    playerView.autoPlay = YES;
    // 开启进度控制
    [playerView enableProgress:YES];
    // 启用硬解码器
    [playerView enableHardDecode:YES];
    // 设置封面
    playerView.coverView.image = [UIImage imageNamed:@"timg.jpeg"];
    // 将playerView加入视图层级中
    [self.view insertSubview:playerView atIndex:0];
    self.playerView = playerView;
    // 设置显示模式
    [self setVideoContentMode:[MDPlayerSettingManager mode]];


    // 准备播放视频
    [self.playerView prepareToPlay:<URL>];
```

* 进度控制

```c
    [self.playerView seekTo:position];
```

* 播放控制

```c
    // 开始播放视频
    [self.playerView play];

    // 停止播放视频
    [self.playerView pause];
```

* 销毁播放器

```c
   [self.playerView stop];
```

**注意** : 一个MMPlayerView仅可以播放一个视频，因此如果需要播放一个新的视频，需要重新创建MMPlayerView实例。

## 视频预加载

```c
[[MMPlayerPreloader sharedInstance] preloadVideoWithURL:[NSURL URLWithString:@"http://img.momocdn.com/feedvideo/AD/2E/AD2E1851-595B-53CA-44E0-606E878966B520181227.mp4"]
                                                         completion:^(BOOL success, NSError * _Nonnull error) {
                                                             NSLog(@"preload success = %d", success);
                                                         }];
```