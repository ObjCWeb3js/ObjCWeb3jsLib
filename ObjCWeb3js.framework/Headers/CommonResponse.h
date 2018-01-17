//
//  CommonResponse.h
//  ObjCWeb3js
//
//  Created by Ned on 19/12/2017.
//  Copyright © 2017 ju. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Web3jsTypes.h"

@interface CommonResponse : NSObject


/**
 框架错误码
 */
@property (nonatomic, assign)contractStatus status;

/**
 业务状态码
 */
@property (nonatomic, assign)int errorno;

/**
 错误信息
 */
@property (nonatomic, copy)NSString * errorMsg;

/**
 业务数据
 */
@property (nonatomic, copy)id dataObj;

/**
 原始返回流
 */
@property (nonatomic, strong)NSData * data;




@end
