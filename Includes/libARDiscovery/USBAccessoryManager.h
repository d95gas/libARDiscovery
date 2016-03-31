//
//  USBAccessoryManager.h
//  ARUtils
//
//  Created by Cyril Hervouin on 03/02/16.
//  Copyright © 2016 Parrot SA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <libARDiscovery/ARDISCOVERY_MuxDiscovery.h>
#import <libARDiscovery/ARDISCOVERY_Error.h>

@class USBAccessoryManager;

@protocol USBAccessoryManagerDelegate <NSObject>
@required
- (void)USBAccessoryManager:(USBAccessoryManager*)usbAccessoryManager didAddDeviceWithConnectionId:(NSUInteger)connectionId name:(const char *)name mux:(struct mux_ctx *)mux serial:(const char *)serial productType:(uint32_t)productType;
- (void)USBAccessoryManager:(USBAccessoryManager*)usbAccessoryManager didRemoveDeviceWithConnectionId:(NSUInteger)connectionId;
@end

@interface USBAccessoryManager : NSObject

+ (USBAccessoryManager *)sharedInstance;

- (eARDISCOVERY_ERROR)muxDiscoveryConnect:(NSString*)name model:(NSString*)model deviceId:(NSString*)serial json:(NSString*)jsonStr callback:(void (^)(uint32_t status, const char* json))connectionCbBlock;
- (void)muxDiscoveryCancelConnect;


@property (nonatomic, weak) id<USBAccessoryManagerDelegate> delegate;

@end
