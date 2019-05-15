#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "MMIPlayerLogger.h"
#import "MMPlatformUtils.h"
#import "MMPlayer.h"
#import "MMPlayerConfigFetcher.h"
#import "MMPlayerLoggerKey.h"
#import "MMPlayerManager.h"
#import "MMPlayerPreloader.h"
#import "MMPlayerProxy.h"
#import "MMSimpleHttpFetcher.h"
#import "MMPRecordReachability.h"
#import "MMMeidaLogger.h"
#import "MMPlayerView.h"
#import "MMPlayerGeometryUtilities.h"
#import "MMPlayerScaleAspectFill.h"
#import "MMPlayerScaleAspectFit.h"
#import "MMPlayerScaleCenter.h"
#import "MMplayerScaleStretch.h"
#import "MMPlayerScalingModeProtocol.h"

FOUNDATION_EXPORT double MMPlayerVersionNumber;
FOUNDATION_EXPORT const unsigned char MMPlayerVersionString[];

