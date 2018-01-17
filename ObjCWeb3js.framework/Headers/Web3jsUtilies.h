//
//  Web3jsUtilies.h
//  ObjCWeb3js
//
//  Created by Ned on 11/4/2017.
//  Copyright © 2017 ju. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Web3jsUtilies : NSObject

+ (NSString *)uuidString;

+ (NSString*)createUuid;

+ (time_t)getSystemupTimeInterval;

+ (NSString *)dec2hex:(unsigned long)dec;

+ (int)hex2dec:(NSString *)hex;

+ (NSString *)dictionaryToJSON:(NSDictionary *)dic;

+ (NSData *)dataFromHexString:(NSString *)hexString;


/**
 整形字符串转十六进制字符串，@"9999999999999"返回 "09184E729FFF"，注意高位会补上0
 @param string 字符串数字
 @return 整形对应十六进制字符串
 */
+ (NSString *)stringIntNumberToHexString:(NSString *)string;

@end
