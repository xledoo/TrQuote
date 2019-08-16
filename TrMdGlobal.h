#ifndef TRMDGLOBAL_H
#define TRMDGLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TRQUOTE_LIBRARY)
#  define TRQUOTE_EXPORT Q_DECL_EXPORT
#else
#  define TRQUOTE_EXPORT Q_DECL_IMPORT
#endif

enum class TrMdResponseId
{
    TrMarketUserLogin			= 100,
    TrOnRspUserLogin            = 101,
    TrOnRspUserLogout           = 102,
    TrOnRtnDepthMarketData		= 103
};


class CTrMdReceiver
{
public:
    virtual void OnReceiveMdData(TrMdResponseId rId, void* wParam, void* lParam) = 0;
};

#endif // TRMDGLOBAL_H
