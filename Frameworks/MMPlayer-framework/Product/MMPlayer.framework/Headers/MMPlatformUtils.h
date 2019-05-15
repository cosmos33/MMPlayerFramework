//
//  MDRecordPlatformUtils.h
//  pushsdk-ios
//
//  Created by wangduanqing on 2018/12/4.
//  Copyright © 2018年 momo. All rights reserved.
//

#import <Foundation/Foundation.h>

#define mmp_IFPGA_NAMESTRING                @"iFPGA"

#define mmp_IPHONE_1G_NAMESTRING            @"iPhone 1G"
#define mmp_IPHONE_3G_NAMESTRING            @"iPhone 3G"
#define mmp_IPHONE_3GS_NAMESTRING           @"iPhone 3GS"
#define mmp_IPHONE_4_NAMESTRING             @"iPhone 4"
#define mmp_IPHONE_4S_NAMESTRING            @"iPhone 4S"
#define mmp_IPHONE_5_NAMESTRING             @"iPhone 5"
#define mmp_IPHONE_5C_NAMESTRING            @"iPhone 5C"
#define mmp_IPHONE_5S_NAMESTRING            @"iPhone 5S"
#define mmp_IPHONE_6_NAMESTRING             @"iPhone 6"
#define mmp_IPHONE_6PLUS_NAMESTRING         @"iPhone 6 Plus"
#define mmp_IPHONE_6S_NAMESTRING            @"iPhone 6S"
#define mmp_IPHONE_6SPLUS_NAMESTRING        @"iPhone 6S Plus"
#define mmp_IPHONE_SE_NAMESTRING            @"iPhone SE"
#define mmp_IPHONE_7_NAMESTRING             @"iPhone 7"
#define mmp_IPHONE_7PLUS_NAMESTRING         @"iPhone 7 Plus"
#define mmp_IPHONE_8_NAMESTRING             @"iPhone 8"
#define mmp_IPHONE_8PLUS_NAMESTRING         @"iPhone 8 Plus"
#define mmp_IPHONE_X_NAMESTRING             @"iPhone X"
#define mmp_IPHONE_XS_NAMESTRING            @"iPhone XS"
#define mmp_IPHONE_XSMAX_NAMESTRING         @"iPhone XS Max"
#define mmp_IPHONE_XR_NAMESTRING            @"iPhone XR"
#define mmp_IPHONE_UNKNOWN_NAMESTRING       @"Unknown iPhone"

#define mmp_IPOD_1G_NAMESTRING              @"iPod touch 1G"
#define mmp_IPOD_2G_NAMESTRING              @"iPod touch 2G"
#define mmp_IPOD_3G_NAMESTRING              @"iPod touch 3G"
#define mmp_IPOD_4G_NAMESTRING              @"iPod touch 4G"
#define mmp_IPOD_5G_NAMESTRING              @"iPod touch 5G"
#define mmp_IPOD_6G_NAMESTRING              @"iPod touch 6G"
#define mmp_IPOD_UNKNOWN_NAMESTRING         @"Unknown iPod"

#define mmp_IPAD_1G_NAMESTRING              @"iPad 1G"
#define mmp_IPAD_2G_NAMESTRING              @"iPad 2G"
#define mmp_IPAD_3G_NAMESTRING              @"iPad 3G"
#define mmp_IPAD_4G_NAMESTRING              @"iPad 4G"
#define mmp_IPAD_AIR_NAMESTRING             @"iPad Air"
#define mmp_IPAD_AIR2_NAMESTRING            @"iPad Air 2"
#define mmp_IPAD_PRO9P7INCH_NAMESTRING      @"iPad Pro 9.7-inch"
#define mmp_IPAD_PRO12P9INCH_NAMESTRING     @"iPad Pro 12.9-inch"
#define mmp_IPAD_5G_NAMESTRING              @"iPad 5G"
#define mmp_IPAD_PRO10P5INCH_NAMESTRING     @"iPad Pro 10.5-inch"
#define mmp_IPAD_PRO12P9INCH2G_NAMESTRING   @"iPad Pro 12.9-inch 2G"
#define mmp_IPAD_MINI_NAMESTRING            @"iPad mini"
#define mmp_IPAD_MINI_RETINA_NAMESTRING     @"iPad mini Retina"
#define mmp_IPAD_MINI3_NAMESTRING           @"iPad mini 3"
#define mmp_IPAD_MINI4_NAMESTRING           @"iPad mini 4"
#define mmp_IPAD_UNKNOWN_NAMESTRING         @"Unknown iPad"

#define mmp_APPLETV_2G_NAMESTRING           @"Apple TV 2G"
#define mmp_APPLETV_3G_NAMESTRING           @"Apple TV 3G"
#define mmp_APPLETV_4G_NAMESTRING           @"Apple TV 4G"
#define mmp_APPLETV_4K_NAMESTRING           @"Apple TV 4K"
#define mmp_APPLETV_UNKNOWN_NAMESTRING      @"Unknown Apple TV"

#define mmp_IOS_FAMILY_UNKNOWN_DEVICE       @"Unknown iOS device"

#define mmp_IPHONE_SIMULATOR_NAMESTRING         @"iPhone Simulator"
#define mmp_IPHONE_SIMULATOR_IPHONE_NAMESTRING  @"iPhone Simulator"
#define mmp_IPHONE_SIMULATOR_IPAD_NAMESTRING    @"iPad Simulator"

typedef enum {
    mmp_UIDeviceUnknown,
    
    mmp_UIDeviceiPhoneSimulator,
    mmp_UIDeviceiPhoneSimulatoriPhone, // both regular and iPhone 4 devices
    mmp_UIDeviceiPhoneSimulatoriPad,
    
    mmp_UIDevice1GiPhone,
    mmp_UIDevice3GiPhone,
    mmp_UIDevice3GSiPhone,
    mmp_UIDevice4iPhone,
    mmp_UIDevice4SiPhone,
    mmp_UIDevice5iPhone,
    mmp_UIDevice5CiPhone,
    mmp_UIDevice5SiPhone,
    mmp_UIDevice6iPhone,
    mmp_UIDevice6PlusiPhone,
    mmp_UIDevice6SiPhone,
    mmp_UIDevice6SPlusiPhone,
    mmp_UIDeviceSEiPhone,
    mmp_UIDevice7iPhone,
    mmp_UIDevice7PlusiPhone,
    mmp_UIDevice8iPhone,
    mmp_UIDevice8PlusiPhone,
    mmp_UIDeviceXiPhone,
    mmp_UIDeviceXSiPhone,
    mmp_UIDeviceXSMaxiPhone,
    mmp_UIDeviceXRiPhone,
    
    mmp_UIDevice1GiPod,
    mmp_UIDevice2GiPod,
    mmp_UIDevice3GiPod,
    mmp_UIDevice4GiPod,
    mmp_UIDevice5GiPod,
    mmp_UIDevice6GiPod,
    
    mmp_UIDevice1GiPad,
    mmp_UIDevice2GiPad,
    mmp_UIDevice3GiPad,
    mmp_UIDevice4GiPad,
    mmp_UIDeviceAiriPad,
    mmp_UIDeviceAir2iPad,
    mmp_UIDevicePro9p7InchiPad,
    mmp_UIDevicePro12p9InchiPad,
    mmp_UIDevice5GiPad,
    mmp_UIDevicePro10p5InchiPad,
    mmp_UIDevicePro12p9Inch2GiPad,
    
    mmp_UIDeviceiPadmini,
    mmp_UIDeviceiPadminiRetina,
    mmp_UIDeviceiPadmini3,
    mmp_UIDeviceiPadmini4,
    
    mmp_UIDeviceAppleTV2,
    mmp_UIDeviceAppleTV3,
    mmp_UIDeviceAppleTV4,
    mmp_UIDeviceAppleTV4K,
    mmp_UIDeviceUnknownAppleTV,
    
    mmp_UIDeviceUnknowniPhone,
    mmp_UIDeviceUnknowniPod,
    mmp_UIDeviceUnknowniPad,
    mmp_UIDeviceIFPGA,
    
} mmp_UIDevicePlatform;

NS_ASSUME_NONNULL_BEGIN

@interface MMPlatformUtils : NSObject
+ (NSString *)randomString: (int) len;
+ (NSString *)urlencode: (NSString*) content;
+ (NSString *)userAgentString;
+ (mmp_UIDevicePlatform)platformType;
@end

NS_ASSUME_NONNULL_END
