//
//  MMCommonTaskAgent.h
//  MMMediaProxy
//
//  Created by chenyong on 2018/12/6.
//  Copyright © 2018年 shuyj. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MMCommonTaskAgentDelegate<NSObject>
@optional
//-(void)onTaskReceiveData:(int)taskid buffer:(void*)buffer len:(size_t)len;
-(void)onTaskComplete:(NSString*)result ;
@end

@interface MMCommonTaskAgent : NSObject

+ (instancetype)instance;

- (instancetype)init NS_UNAVAILABLE;

- (void)startTaskWithDelegate:(id<MMCommonTaskAgentDelegate>)delegate json:(NSString *)json;
- (void)stopTask;
//-(int) clearAllTask;
//-(int) removeCommonTaskWithId:(NSInteger) taskId;
@property(weak, nonatomic) id<MMCommonTaskAgentDelegate> delegate;
@end
