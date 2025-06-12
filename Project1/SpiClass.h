#pragma once
#include "ThostFtdcUserApiDataType.h"
#include "ThostFtdcUserApiStruct.h"
#include "ThostFtdcTraderApi.h"
#include<iostream>
#include<Database.h>
#include <cstring> 
#include <string>   
#include <conio.h>
#include <windows.h>

extern int nRequestID;  //全局变量，记录请求ID
extern const char* g_chFrontaddr;
extern TThostFtdcBrokerIDType g_chBrokerID;
extern TThostFtdcUserIDType g_chUserID;
extern TThostFtdcPasswordType g_chPassword;
extern TThostFtdcLoginRemarkType	LoginRemark;
extern TThostFtdcAuthCodeType	g_chAuthCode;
extern TThostFtdcAppIDType	g_chAppID;
extern TThostFtdcInstrumentIDType	g_chInstrumentID;
extern TThostFtdcInvestorIDType g_chInvestorID;
extern HANDLE g_hEvent; // 全局变量，事件句柄，用于等待异步操作完成


//  回调类，继承服务提供接口，重写了其中的部分回调函数
class SpiClass : public CThostFtdcTraderSpi
{
private:
    CThostFtdcTraderApi *pApi;

public:
    SpiClass() {};  //构造函数
    SpiClass(CThostFtdcTraderApi* api) :pApi(api) {};
    virtual ~SpiClass() {};

    // 查询持仓
    void ReqQryInvestorPositionDetail();

    ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
    virtual void OnFrontConnected();

    ///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
    ///@param nReason 错误原因
    ///        0x1001 网络读失败
    ///        0x1002 网络写失败
    ///        0x2001 接收心跳超时
    ///        0x2002 发送心跳失败
    ///        0x2003 收到错误报文
    virtual void OnFrontDisconnected(int nReason);

    ///客户端认证响应
    virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    ///登录请求响应
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);    

    ///登出请求响应
    virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///错误应答
    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);    

    ///订阅行情应答
    virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///请求查询投资者持仓响应
    void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
   
    ///请求查询资金账户响应
    virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
};

