//
//  Web3jsService.h
//  ObjCWeb3js
//
//  Created by Ned on 11/4/2017.
//  Copyright © 2017 ju. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "Web3jsTypes.h"
#import "CommonResponse.h"
#import "RawTransaction.h"
#import "JUContractInfo.h"

@protocol Web3jsServiceDelegate <NSObject>


/**
 服务初始化完成
 */
- (void)didServiceInitDone;

@end

@interface Web3jsService : NSObject

@property (nonatomic, assign)id<Web3jsServiceDelegate> delegate;

/**
 设置交易证书类型
 */
@property (nonatomic, assign)KCertificationType type;

/**
 设置https证书,DER格式 pem转der https://stackoverflow.com/questions/10579985/how-can-i-get-seckeyref-from-der-pem-file
 */
@property (nonatomic, strong)NSData *certData;

/**
 开启打印，默认不开启
 */
@property (nonatomic, assign)BOOL enableLog;

/**
 日志级别
 */
@property (nonatomic, assign)LogLevel logLevel;

/**
 版本号
 */
@property (nonatomic, copy, readonly)NSString * version;

/**
 ### 2.1 共享单例
 **返回值** 实例对象
 **说明**  无
 */
+ (instancetype)sharedInstance;

/**
 ### 2.2 Service共享初始化

 @param provider JSON RPC server地址
 @param contractInfos 合约模块信息
 */
- (void)initWeb3jsServiceWithProvicer:(NSString *)provider contractInfos:(NSArray <JUContractInfo *>*)contractInfos;


/**
 设置接口调用的超时时间
 @param timeout 默认10second.
 */
- (void)setGloableTimeOut:(NSTimeInterval)timeout;

/**
 异步调用合约

 @param contract 合约名
 @param methodName 方法名
 @param arguments 合约方法参数列表
 @param completion 回调结果
 @return 调用返回状态
 */
- (int)asyncCall:(NSString *)contract methodName:(NSString *)methodName arguments:(NSArray *)arguments completion:(ObjCWeb3jCompletion)completion;


/**
  异步调用合约（带fromAddress）

 @param contract 合约名
 @param methodName 方法名
 @param arguments 合约参数列表
 @param from 调用者地址
 @param completion 回调
 @return 状态
 */
- (int)asyncCall:(NSString *)contract methodName:(NSString *)methodName arguments:(NSArray *)arguments fromAddress:(NSString *)from completion:(ObjCWeb3jCompletion)completion;


/**
 向合约发送交易并轮询获取交易回执
 
 提示：为保证回执能够正常解析，Solidity编写的合约对应的event必须按照以下格式定义才能读取到对应回执，否则会以超时的结果返回
 event Notify(uint _errno, string _info,string _data);
 
 如果要读取
 
 @param contract 合约名
 @param methodName 方法名
 @param arguments 合约参数列表
 @param completion 回调，回调参数见定义
 @return 调用返回状态
 */
- (int)sendRawTrasaction:(NSString *)contract methodName:(NSString *)methodName arguments:(NSArray *)arguments  completion:(ObjCWeb3jCompletion)completion;


/**
 向合约发送交易
 
 @param contract 合约名
 @param methodName 方法名
 @param arguments 合约参数列表
 @param eventName 自定义eventName
 @param completion 回调，回调参数见定义
 @return 调用返回状态
 */
- (int)sendRawTrasaction:(NSString *)contract methodName:(NSString *)methodName arguments:(NSArray *)arguments eventName:(NSString *)eventName completion:(ObjCWeb3jCompletion)completion;


/**
 用户注册

 @param userID 用户账号
 @param password 用户密码
 @param email 用户邮箱
 @param mobile 用户手机
 @param userName 用户姓名
 @param completion commonSuccess:成功 commonFail:失败 userExist:用户已存在
 @return 调用返回状态
 */
- (int)userRegister:(NSString *)userID password:(NSString *)password email:(NSString *)email mobile:(NSString *)mobile userName:(NSString *)userName completion:(void (^)(commonErrorCode ret,NSString * address,NSString * cipher))completion;



/**
 用户登录

 @param userID 用户ID 或者 钱包地址
 @param password 用户密码
 @param completion commonSuccess:成功 commonFail:失败
 @return 调用返回状态
 */
- (int)userLogin:(NSString *)userID password:(NSString *)password completion:(void (^)(commonErrorCode ret,NSString * address,NSString * cipher))completion;


/**
 根据ECC私钥获取公钥

 @param privateKey 私钥
 @param completion 完成回调
 @return 完成回调
 */
- (int)getPublicKeyWithPrivateKey:(NSString *)privateKey completion:(void (^)(commonErrorCode ret,NSString * publicKey))completion;


/**
 用户登出

 @param userID 用户I
 @param password 用户密码
 @param completion  commonSuccess:成功 commonFail:失败 passwordErr:密码错误
 @return 调用返回状态
 */
- (int)userLogout:(NSString *)userID password:(NSString *)password completion:(void (^)(commonErrorCode ret))completion;

/**
 导入钱包

 @param walletJSON 钱包文件的json格式
 @param completion commonSuccess:成功 commonFail:失败 walletFileErr:钱包格式错误
 @return 调用返回状态
 */
- (int)importwalletJSON:(NSString *)walletJSON completion:(void (^)(commonErrorCode ret))completion;


/**
 判断钱包文件是否存在

 @param address 钱包文件地址
 @return 0存在 1不存在 2文件信息未加载到内存
 */
- (int)walletExist:(NSString *)address;

/**
  删除

 @param userId 钱包文件名
 @return 0成功 1钱包文件不存在
 */
- (int)deleteWallet:(NSString *)userId;


/**
 根据钱包文件名获取钱包文件路径

 @param userId 用户id（即钱包名）
 @return 钱包文件路径
 */
- (NSString *)getWalletPathForUserId:(NSString *)userId;


/**
 修改钱包密码

 @param userID 钱包地址
 @param oldPassword 旧密码
 @param newPassword 新密码
 @param aotoLogin 是否自动登录，如果自动登录，则交易以此次修改userID对应的密钥进行签名发起
 @param completion 完成回调
 @return 返回调用状态
 */
- (int)modifyWalletPassWordWithUserId:(NSString *)userID oldPassword:(NSString *)oldPassword newPassword:(NSString *)newPassword aotoLogin:(BOOL)aotoLogin completion:(void (^)(commonErrorCode ret))completion;


/**
 修改钱包文件-手机号

 @param userID 钱包名
 @param oldMobile 旧手机号
 @param newMobile 新手机号
 @return 0
 */
- (int)modifyWalletMobileWithUserId:(NSString *)userID oldMobile:(NSString *)oldMobile newMobile:(NSString *)newMobile;


/**
 修改钱包文件-邮箱号

 @param userID 钱包名
 @param email 旧邮箱号
 @param newEmail 新邮箱号
 @return 0
 */
-(int)modifyWalletEmailWithUserId:(NSString *)userID oldEmail:(NSString *)email newEmail:(NSString *)newEmail;

/**
 获取钱包用户列表
 
 @return 列表
 */
- (NSArray<NSString *> *)getWalletUserIdList;

/**
 根据合约名，方法名，参数列表获取对应的RLP

 @param contract 合约名
 @param methodName 方法名
 @param arguments 参数列表
 @param completion 完成回调
 */
- (void)getSignedTransactionData:(NSString *)contract methodName:(NSString *)methodName arguments:(NSArray *)arguments completion:(void (^)(commonErrorCode error,NSString * errMsg, NSString * RLP,NSString * address))completion;


/**
 验证外部导入钱包文件密码是否正确

 @param walletJson 钱包文件
 @param account 账户
 @param password 密码
 */
-(int)verifyWalletPasswordWithWallet:(NSString *)walletJson account:(NSString *)account password:(NSString *)password completion:(void (^)(commonErrorCode ret))completion;

/**
 发送签好名的RLP数据，此接口会返回合约中定义的名为Notify事件消息

 @param RLP RLP数据
 @param completion 完成回调
 */
- (void)sendRawRLP:(NSString *)RLP completion:(ObjCWeb3jCompletion)completion;


/**
 返回函数调用的RLP编码

 @param contract 合约名
 @param methodName 方法
 @param arguments 参数
 @param completion 完成回调 data：函数调用的RLP编码  address：合约地址
 */
- (void)getData:(NSString *)contract methodName:(NSString *)methodName arguments:(NSArray *)arguments completion:(void (^)(commonErrorCode ret,NSString * errMsg, NSString * data, NSString *address))completion;

/**
 根据合约调用参数返回待签数据

 @param contract 合约名
 @param methodName 合约方法
 @param arguments 合约参数
 @param completion 完成回调 待签RLP十六进制数据， 通过CommonResponse对象dataObj获取，类型为 <NSString *>，以0x开头
 */
- (void)getRLP4ECCSign:(NSString *)contract methodName:(NSString *)methodName arguments:(NSArray *)arguments completion:(ObjCWeb3jCompletion)completion;

/**
 对RawTransaction对象进行签名， nonceHex需要通过接口
    - (void)ethNonceWithCompletion:(void (^)(commonErrorCode ret,NSString * nonce))completion;
 接口获取，并且需要调用接口
    - (int)userLogin:(NSString *)userID password:(NSString *)password completion:(void (^)(commonErrorCode ret,NSString * cipher))completion;
 加载私钥才能对RawTransaction对象进行签名。
 
    以下是一个RawTransaction的初始师范
    RawTransaction * r = [[RawTransaction alloc] init];
    r.nonceHex = @"0x000001608c48156ea1c8b15e2a9fcd914b26265bb40f10c893d8612b7a5ce5eb";
    r.gasPrice = @"21000000000";
    r.gasLimit = @"9999999999999";
    r.to = @"0x60980196be4c8e2d958c7be1158b30f506a8cece";
    r.value = @"0";
    r.data = @"0xffffffffffffffffffff";

 @param transaction 交易对象
 @param completion 完成回调 返回的签名数据字段是 CommonResponse对象的dataObj字段，类型为NSString *
 */
- (void)signRawTransaction:(RawTransaction *)transaction completion:(ObjCWeb3jCompletion)completion;

/**
 解码Solidity event事件对于的编码
 @param params 类型数组 目前支持数据类型见http://solidity.readthedocs.io/en/develop/types.html 例子：@['address','int256','uint256']
 @param data event返回的logs数组下的data字段
 @param completion 完成回调
 */
- (void)decodeParams:(NSArray <NSString *> *)params data:(NSString *)data completion:(void (^)(commonErrorCode errorCode,NSString * errorMsg,NSString * data))completion;

#pragma mark - web3.js APIS

/**
 web3.js接口封装，返回web3.js原始数据

 @param txHash 交易hash
 @param completion 完成回调，data：交易hash对应的区块信息
 */
- (void)ethGetTransactionReceipt:(NSString *)txHash completion:(void (^)(commonErrorCode ret,NSString * errMsg, NSString * data))completion;


/**
 获取某个账户对应的交易数，作为nonce

 @param address 地址
 @param completion 完成回调
 */
- (void)ethGetTransactionCount:(NSString *)address completion:(void (^)(commonErrorCode ret,NSString * errMsg, NSString * count))completion DEPRECATED_MSG_ATTRIBUTE("nonce改造后，不再用此接口返回的count作为nonce");

/**
 发送交易

 @param signedTransactionData 签名好的数据
 @param completion 完成huidiao txHash：交易hash
 */
- (void)ethSendRawTransaction:(NSString *)signedTransactionData completion:(void (^)(commonErrorCode ret,NSString * txHash))completion;

/**
 获取改造后的交易的nonce

 @param completion 完成回调 nonce：十六进制字符串的nonce
 */
- (void)ethNonceWithCompletion:(void (^)(commonErrorCode ret,NSString * nonce))completion;

#pragma mark - Private Transaction

/**
 获取群私钥

 @param completion 完成回调 groupPriKey：群私钥s
 */
- (void)ethJoin:(void (^)(commonErrorCode ret,NSString * errMsg, NSString * groupPriKey))completion;

/**
 获取群公钥

 @param completion 完成回调 groupPbuKey：群公钥
 */
- (void)ethGetGroupPubKey:(void (^)(commonErrorCode ret,NSString * errMsg, NSString * groupPbuKey))completion;

/**
 获取广播加密列表

 @param completion pubKeyList：公钥列表
 */
- (void)ethGetBroadPubKeyList:(void (^)(commonErrorCode ret,NSString * errMsg, NSArray<NSString *> * pubKeyList))completion;

/**
 将data进行RLP编码，返回待签的RLP数据

 @param nonceStr nonce值
 @param nonceType nonce类型
 @param to 合约地址
 @param data 函数调用的data
 @param completion 完成回调
 */
- (void)encodeRLP4ECCSign:(NSString *)nonceStr nonceType:(NonceType)nonceType to:(NSString *)to data:(NSString *)data completion:(void (^) (commonErrorCode ret,NSString * RLP))completion;
@end
