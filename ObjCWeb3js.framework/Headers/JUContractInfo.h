//
//  JUContractInfo.h
//  ObjCWeb3js
//
//  Created by Ned on 17/1/2018.
//  Copyright © 2018 ju. All rights reserved.
//

#import <Foundation/Foundation.h>

//单个合约的加载情况
typedef enum : NSUInteger {
    KContractAddrStatusNotQuery,
    KContractAddrStatusQuerying,
    KContractAddrStatusCompleteQuery,
} KContractAddrStatus;

@interface JUContractInfo : NSObject

@property (nonatomic, copy)NSString * contractName;

@property (nonatomic, copy)NSString * contractPath;

@property (nonatomic, copy)NSString * ABIInfo;

@property (nonatomic, copy)NSString * address;

@property (nonatomic, copy)NSString * version;

@property (nonatomic, copy)NSString * moduleName;

@property (nonatomic, copy)NSString * moduleVersion;

@property (nonatomic, assign)KContractAddrStatus status;

@end
