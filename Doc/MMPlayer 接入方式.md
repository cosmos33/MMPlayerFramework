# MMPlayer 接入方式说明

## SDK 部分接入

MMPlayer提供两种方式供iOS开发者选择。

通过cocoaspods (推荐)
手动接入


通过cocoapods接入
在工程的Podfile添加以下代码:

 source  'https://github.com/cosmos33/MMSpecs.git'
 pod 'MMPlayer'

保存并执行pod install





* 将`Frameworks`文件夹考入工程根目录
* 在Podfile中写入

```ruby
   pod 'IJKVodMediaPlayer', :path => './Frameworks/IJKVodMediaPlayer'
   pod 'MMFileService', :path => './Frameworks/MMFileService-framework'
   pod 'MMPlayer', :path => './Frameworks/MMPlayer-framework'
   pod 'MMFrameworks', :path => './Frameworks/MMFramework', :subspecs => ['MMFoundation']
   pod 'openssl-lib', :path => './Frameworks/openssl-ios'
   pod 'ffmpeg-lib', :path => './Frameworks/ffmpeg-ios'
   pod 'MMCrypt', :path => './Frameworks/MMCrypt'
   pod 'MDLog', :path => './Frameworks/MDLog-0.2.3'
   pod 'MMAppBus', :path => './Frameworks/MMAppBus-0.5.3'
   pod 'MMMediaProxyOnly', :path => './Frameworks/MMMediaProxy-0.5.7'
```

执行 `pod install` 即可。

**注意**: 需要关闭工程 `build setting`-> `bitcode`

## UI 部分接入

* 增加权限

```
Privacy - Photo Library Usage Description
```

* 将`MMPlayerDemo/PlayerSDKUI` 目录 以及 `MMPlayerDemo/Pulic` 目录添加到工程中.
* 在`Podfile`中添加

```ruby
  pod 'pop'
  pod 'SDWebImage'
  pod 'SDWebImage/WebP'
  pod 'Toast', '~> 4.0.0'
  pod 'ReactiveCocoa', '2.5'
```

执行`pod install`即可。

## SDK 调用

请参考 `MMPlayer 接入文档`

## UI部分调用

```c
    MDPlayerSettingViewController *vc = [[MDPlayerSettingViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
```

## MMPlayer 主要模块介绍

* 源码地址

`https://git.wemomo.com/module/MomoVideoSDK.git`

分支 : `iOS/sunfei_player`

* 主要模块

> Core模块: SDK相关信息, 以及核心播放器, 预加载相关代码。主要相关类有 `MMPlayerManager`, `MMPlayer`, `MMPlayerPreloader`
> UI模块: 对播放器进行的一次封装，简化用户对于封面图相关控制的逻辑。核心类有`MMPlayerView`

相关类接口可以参考 `MMPlayer SDK 接口文档`

* 主要联系人

姓名 | 联系方式 | 负责
--- | --- | ---
孙飞 | sun.fei@immomo.com | 播放器SDK业务层开发
张哲 | zhang.zhe@immomo.com | 播放器负责人
邹国伟 | zou.guowei@immomo.com | 播放器底层开发
刘焱 | liu.yan@immomo.com | 播放器测试
