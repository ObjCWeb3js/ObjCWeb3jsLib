//
//  RawTransaction.h
//  ObjCWeb3js
//
//  Created by Ned on 25/12/2017.
//  Copyright © 2017 ju. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RawTransaction : NSObject

/**
 nonce值 16进制字符串 随机整数，使用此值，可以允许你覆盖你自己的相同nonce的，正在pending中的交易。
 gasPrice:默认是自动确定，交易的gas价格
 */
@property (nonatomic, copy)NSString * nonceHex;

/**
 默认是自动确定，交易的gas价格，默认是网络gas价格的平均值 。
 */
@property (nonatomic, copy)NSString * gasPrice;

/**
 gas限制价格
 */
@property (nonatomic, copy)NSString * gasLimit;

/**
 交易消息的目标地址
 */
@property (nonatomic, copy)NSString * to;

/**
 交易携带的货币量，以wei为单位。如果合约创建交易，则为初始的基金
 */
@property (nonatomic, copy)NSString * value;

/**
 包含相关数据的字节字符串
 */
@property (nonatomic, copy)NSString * data;

@end
