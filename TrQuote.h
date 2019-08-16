#ifndef TRQUOTE_H
#define TRQUOTE_H

#include "TrMdGlobal.h"


class TRQUOTE_EXPORT CTrQuote
{
public:
    CTrQuote();
    // 服务登录 1.行情自动订阅 2.批量登录
    void TrMarketStart();
    // 服务登出 1.行情自动退订 2.批量登出
    void TrMarketStop();
    // 订阅合约 请在 TrMarketStart() 前添加订阅合约
    void TrAddSubscribe(char* contract);
    // 添加接收器
    void TrAddReceiver(CTrMdReceiver* receiver);
    // 删除接收器
    void TrDelReceiver(CTrMdReceiver* receiver);
};
#endif // TRQUOTE_H
