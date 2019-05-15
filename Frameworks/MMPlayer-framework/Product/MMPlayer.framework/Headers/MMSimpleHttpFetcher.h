//
//  MMSimpleHttpFetcher.h
//  MMPlayer
//
//  Created by sunfei on 2019/5/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MMCancellable <NSObject>

- (void)cancel;

@end

@interface NSURLSessionTask (MMResourceLoading) <MMCancellable>

@end

@interface MMRemoteResouce<ObjectType>: NSObject

@property (nonatomic, copy) NSURL *remoteURL;
@property (nonatomic, copy) NSDictionary<NSString *, id> *customParams;
@property (nonatomic, copy) ObjectType(^parser)(id, NSError **error);

@end

@interface MMSimpleHttpFetcher<ObjectType> : NSObject

+ (MMSimpleHttpFetcher *)GET;
+ (MMSimpleHttpFetcher *)POST;

@property (nonatomic, copy) NSDictionary<NSString *, NSString *> *headers;

- (id<MMCancellable>)loadResource:(MMRemoteResouce<ObjectType> *)resouce
                            queue:(dispatch_queue_t _Nullable)queue
                       completion:(void(^)(id data, NSData *rawData, NSError *error))completion;

@end

NS_ASSUME_NONNULL_END
