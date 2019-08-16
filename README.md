#TrQuote
国内商品期货CTP接口独立行情封装
简化了订阅过程

基于QT封装，版本5.11.3

采用最新的穿透式监管API 版本 6.3.15_20190220_tradeapi64_se_windows

##使用步骤：
###1. 新建一个用于接收行情的类，继承于 TrMdGlobal.h 里的 CTrMdReceiver
#```
#include "TrMdGlobal.h"

class CMdTest : public CTrMdReceiver
{
public:
    CMdTest();
    virtual void OnReceiveMdData(TrMdResponseId rId, void* wParam, void* lParam) override;
};
#```
###2. 重新实现虚函数
`
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
`