//
//  Copyright (c) 2018 Open Whisper Systems. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

extern NSString *const AppIsReadyNotification;

typedef void (^AppReadyBlock)(void);

@interface AppReadiness : NSObject

- (instancetype)init NS_UNAVAILABLE;

// This method can be called on any thread.
+ (BOOL)isAppReady;

// This method should only be called on the main thread.
+ (void)setAppIsReady;

// If the app is ready, the block is called immediately;
// otherwise it is called when the app becomes ready.
//
// This method should only be called on the main thread.
// The block will always be called on the main thread.
+ (void)runNowOrWhenAppIsReady:(AppReadyBlock)block NS_SWIFT_NAME(runNowOrWhenAppIsReady(_:));

@end

NS_ASSUME_NONNULL_END
