//
//  WebThreeRLP.h
//  ObjCWeb3js
//
//  Created by Ned on 31/10/2017.
//  Copyright © 2017 ju. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Web3jsTypes.h"

@interface WebThreeRLP : NSObject

+ (NSData *)encode:(NSArray*)params;

+ (NSArray *)decode:(NSData *)data;

+ (void )decodeHex:(NSString *)dataHex completion:(void (^) (NSString * RLP))completion;

+ (NSString *)simpleDecode:(id)resultObject;

+ (void)privateTXEncode4JSONRPC:(NSString *)nonceStr nonceType:(NonceType)nonceType cipherTextHex:(NSString *)cipherTextHex GSHex:(NSString *)GSHex publicKeyLenStr:(NSString *)publicKeyLenStr completion:(void (^) (commonErrorCode error, NSString * RLP))completion;


@end
