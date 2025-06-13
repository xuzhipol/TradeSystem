#pragma once
#include<SpiClass.h>
#include<Database.h>

using namespace std;  
int nRequestID = 0; // 全局变量，记录请求ID

const char* g_chFrontaddr = "tcp://180.168.146.187:10201";
TThostFtdcBrokerIDType g_chBrokerID = "9999";
TThostFtdcUserIDType g_chUserID = "242498";
TThostFtdcPasswordType g_chPassword = "238607xzp*";
TThostFtdcLoginRemarkType	LoginRemark = "test";
TThostFtdcAuthCodeType	g_chAuthCode = "0000000000000000";
TThostFtdcAppIDType	g_chAppID = "test";
TThostFtdcInstrumentIDType	g_chInstrumentID = "ss2508";
TThostFtdcInvestorIDType g_chInvestorID = "242498";
TThostFtdcExchangeIDType g_chExchangeID="SHFE";
int OrderRef_num = 0;//存储订单编号
int num = 0;//记录查询结果-持仓数量
char direction = '0';//记录持仓方向
int Flag;//标志位，0表示报单完成，1表示报单只完成了平仓部分，还需要开仓
HANDLE g_hEvent = CreateEvent(NULL, false, false, NULL);

int main()
{
    system("COLOR 0a");
    CThostFtdcTraderApi* pApi = CThostFtdcTraderApi::CreateFtdcTraderApi();
    SpiClass spi(pApi);
    //printf("\napi版本: \n%s", pApi->GetApiVersion());
    pApi->RegisterSpi(&spi);
    pApi->SubscribePrivateTopic(THOST_TERT_QUICK);
    pApi->SubscribePublicTopic(THOST_TERT_QUICK);
    //const char* g_chFrontaddr="tcp://180.168.146.187:10201";
    pApi->RegisterFront(const_cast<char*>(g_chFrontaddr));
    pApi->Init();
    WaitForSingleObject(g_hEvent, INFINITE);

    //使用直连模式
    CThostFtdcReqAuthenticateField a = { 0 };
    strcpy_s(a.BrokerID, g_chBrokerID);
    strcpy_s(a.UserID, g_chUserID);
    strcpy_s(a.AuthCode, g_chAuthCode);
    strcpy_s(a.AppID, g_chAppID);
    strcpy_s(a.UserProductInfo, g_chAppID);
    int b = pApi->ReqAuthenticate(&a, nRequestID++);
    //printf("\t客户端认证 = [%d]\n", b);
    WaitForSingleObject(g_hEvent, INFINITE);

    CThostFtdcReqUserLoginField reqUserLogin = { 0 };
    strcpy_s(reqUserLogin.BrokerID, g_chBrokerID);
    strcpy_s(reqUserLogin.UserID, g_chUserID);
    strcpy_s(reqUserLogin.Password, g_chPassword);
    strcpy_s(reqUserLogin.LoginRemark, "test");
    pApi->ReqUserLogin(&reqUserLogin, nRequestID++);
    WaitForSingleObject(g_hEvent, INFINITE);

    spi.ReqQryInvestorPositionDetail();
    WaitForSingleObject(g_hEvent, INFINITE);

    //根据目标仓位和现有仓位报单
    spi.ReqOrderInsert_Ordinary(num,direction);
    _getch();

    if (Flag == 1) {
        while (Flag == 1)//只要平仓操作没有完成，就循环查询
        {
            spi.ReqQryInvestorPositionDetail();
            WaitForSingleObject(g_hEvent, INFINITE);
        }
        printf("平仓完成,请报单开仓：\n");
        spi.ReqOrderInsert_Ordinary(num, direction);
        _getch();
    }
    system("pause");
    return 1;
}