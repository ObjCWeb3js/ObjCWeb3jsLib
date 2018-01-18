//
//  Web3jsTypes.h
//  ObjCWeb3js
//
//  Created by Ned on 14/4/2017.
//  Copyright © 2017 ju. All rights reserved.
//

#ifndef Web3jsTypes_h
#define Web3jsTypes_h

typedef enum : NSUInteger {
    LogLevelDEBUG,
    LogLevelINFO,
    LogLevelWARN,
    LogLevelERROR,
    LogLevelFATAL,
} LogLevel;

typedef NS_ENUM(NSInteger, contractStatus) {
    con_success,
    con_fail,
    serviceNotInit,//服务未初始化
    contractNotFound, //无对应合约
    contractNotDeployed, //合约没有地址，未部署
    contractVersionMisMatch, //合约版本不一致
    getNonceFail, //nonce获取失败
    walletFileNotInit, //钱包未初始化
    walletInvalid,//当前用户钱包文件未激活
    callTimeout, //超时无响应
    connectToNodeFail, //无法连接节点
    web3jsUnknowError, //未知错误
};

typedef enum : NSUInteger {
    KCertificationTypeFile,
    KCertificationTypeUKEY,
} KCertificationType;

typedef NS_ENUM(NSInteger, commonErrorCode) {
    commonSuccess,
    commonFail,
    userNoExist,
    walletNotExist = 96, //钱包不存在
    passwordErr = 97, //口令错误
    walletFileErr = 98,//钱包文件格式错误
    userExist = 99,//用户已存在
    paramErr = 100,//入参错误
};

typedef enum : NSUInteger {
    /*通过eth_getTransactionCount返回的nonce*/
    NonceTypeTXCountByFrom,
    /*时间戳nonce*/
    NonceTypeTimeStamp,
} NonceType;

typedef void(^commonCallbackWithIntRet)(id result);


@class CommonResponse;
typedef void(^ObjCWeb3jCompletion)(CommonResponse * response);


#endif /* Web3jsTypes_h */
