//
//  JuWeb3jsUtilies.h
//  ObjCWeb3js
//
//  Created by Ned on 4/6/2017.
//  Copyright © 2017 ju. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Web3jsTypes.h"


typedef void(^onSignComplete)(NSDictionary * signature);

@interface JuWeb3jsUtilies : NSObject

+ (instancetype)sharedInstance;

+ (void)ECDSAsign:(NSString *)digest privateKey:(NSString *)privateKey completion:(onSignComplete)completion;

+ (NSData *)dataFromHexString:(NSString *)hexString;

+ (NSString *)stringFromHexString:(NSString *)hexString;

- (int)getPublicKeyWithPrivateKey:(NSString *)privateKey completion:(void (^)(commonErrorCode ret,NSString * publicKey))completion;

@end
