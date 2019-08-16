#TrQuote
国内商品期货CTP接口独立行情封装
简化了订阅过程

基于QT封装，版本5.11.3

采用最新的穿透式监管API 版本 6.3.15_20190220_tradeapi64_se_windows

##使用步骤：
###1. 由于是QT的项目，所以需要在 .pro 里进行配置，添加外部库链接
```cpp
win32: LIBS += -L$$PWD/include/ -lTrQuote

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
```

###2. 新建一个用于接收行情的类，继承于 TrMdGlobal.h 里的 CTrMdReceiver
```cpp
#include "TrMdGlobal.h"

class CMdTest : public CTrMdReceiver
{
public:
    CMdTest();
    virtual void OnReceiveMdData(TrMdResponseId rId, void* wParam, void* lParam) override;
};
```
###3. 重新实现虚函数
```cpp
void CMdTest::OnReceiveMdData(TrMdResponseId rId, void* wParam, void* lParam)
{
    qDebug() << __FUNCTION__;
    switch (rId) {
        case TrMdResponseId::TrOnRtnDepthMarketData:
        {
            CThostFtdcDepthMarketDataField *pDepthMarketData = reinterpret_cast<CThostFtdcDepthMarketDataField *>(wParam);
            qDebug() << pDepthMarketData->AskPrice1 << pDepthMarketData->BidPrice1 << pDepthMarketData->InstrumentID << pDepthMarketData->UpdateTime;
            break;
        }
    }
}
```

###4. 在main.cpp里进行订阅
```cpp
    CMdTest* t = new CMdTest;
    CTrQuote* qQuote = new CTrQuote;
    qQuote->TrAddReceiver(t);
    qQuote->TrMarketStart();
```
###5. TrConfigs/FrontConfig.xml 配置文件解释
```xml
<?xml version="1.0" encoding="utf-8" ?>
<Config Operation="public">
	<Subscribe>rb1910</Subscribe>
	<Subscribe>SR909</Subscribe>
	<Broker Operation="public">
		<BrokerName>实盘穿透式API</BrokerName>
		<BrokerID>9070</BrokerID>
		<UserID>可以不填</UserID>
		<Password>可以不填</Password>
		<AppID>可以不填</AppID>
		<AuthCode>可以不填</AuthCode>	
		<MarketFront>tcp://124.74.237.193:41313</MarketFront>		
	</Broker>
</Config>
```
可以配置多组连接信息通过 Operation 属性来配置使用哪一组

穿透式监管的API对行情连接貌似并没有严格要求，所以只是订阅行情的话 AppID 和 AuthCode 不填也能正常获取行情
