##Pod 集成ObjCWeb3js_source

ObjCWeb3js是使用于与公司链封装的与合约交互在iOS平台上framework。

###版本说明

0.1.6 版本 支持开放服务平台web端调用原生的交易签名，获取钱包列表等功能；新增SDK对应节点版本号接口；支持控制台日志开关以及按级别打印；

0.1.1版本 支持HTTPS (由于WebKit XMLHttpRequest在iOS上的bug，并且不支持自签证书，所以0.1.1版本实现了JSON RPC由native实现的逻辑)。

0.1.0版本 合约查询接口增加ModuleService,修复因iOS设备修改时间而不能发交易的bug。

0.0.9版本 改版本适用于公司新链nonce改造后的版本。

0.0.8版本 该版本适用于公司nonce改造前版本。

使用Pod集成。 

```shell
pod 'ObjCWeb3jsLib', '0.1.6'
```


