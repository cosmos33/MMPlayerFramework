//
//  MMIPlayerLogger.h
//  CXBeautyKit
//
//  Created by sunfei on 2019/5/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MMIPlayerLogger <NSObject>

- (void)writeBody:(NSString *)body;
- (void)forceUploadMMFile;

- (void)enableLogger:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
