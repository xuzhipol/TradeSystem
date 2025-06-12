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
HANDLE g_hEvent = CreateEvent(NULL, false, false, NULL);

int main()
{
    system("COLOR 0a");
    CThostFtdcTraderApi* pApi = CThostFtdcTraderApi::CreateFtdcTraderApi();
    SpiClass spi(pApi);
    printf("\napi版本: \n%s", pApi->GetApiVersion());
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
    printf("\t客户端认证 = [%d]\n", b);
    WaitForSingleObject(g_hEvent, INFINITE);

    CThostFtdcReqUserLoginField reqUserLogin = { 0 };
    strcpy_s(reqUserLogin.BrokerID, g_chBrokerID);
    strcpy_s(reqUserLogin.UserID, g_chUserID);
    strcpy_s(reqUserLogin.Password, g_chPassword);
    //strcpy_s(reqUserLogin.ClientIPAddress, "::c0a8:0101");
    strcpy_s(reqUserLogin.LoginRemark, "test");
    // 发出登陆请求
    pApi->ReqUserLogin(&reqUserLogin, nRequestID++);
    WaitForSingleObject(g_hEvent, INFINITE);

    _getch();

    printf("日期:");
    printf(pApi->GetTradingDay());
    cout << endl;

    spi.ReqQryInvestorPositionDetail();
    WaitForSingleObject(g_hEvent, INFINITE);

    system("pause");
    return 1;
}