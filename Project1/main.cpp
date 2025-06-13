#pragma once
#include<SpiClass.h>
#include<Database.h>

using namespace std;  
int nRequestID = 0; // ȫ�ֱ�������¼����ID

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
int OrderRef_num = 0;//�洢�������
int num = 0;//��¼��ѯ���-�ֲ�����
char direction = '0';//��¼�ֲַ���
int Flag;//��־λ��0��ʾ������ɣ�1��ʾ����ֻ�����ƽ�ֲ��֣�����Ҫ����
HANDLE g_hEvent = CreateEvent(NULL, false, false, NULL);

int main()
{
    system("COLOR 0a");
    CThostFtdcTraderApi* pApi = CThostFtdcTraderApi::CreateFtdcTraderApi();
    SpiClass spi(pApi);
    //printf("\napi�汾: \n%s", pApi->GetApiVersion());
    pApi->RegisterSpi(&spi);
    pApi->SubscribePrivateTopic(THOST_TERT_QUICK);
    pApi->SubscribePublicTopic(THOST_TERT_QUICK);
    //const char* g_chFrontaddr="tcp://180.168.146.187:10201";
    pApi->RegisterFront(const_cast<char*>(g_chFrontaddr));
    pApi->Init();
    WaitForSingleObject(g_hEvent, INFINITE);

    //ʹ��ֱ��ģʽ
    CThostFtdcReqAuthenticateField a = { 0 };
    strcpy_s(a.BrokerID, g_chBrokerID);
    strcpy_s(a.UserID, g_chUserID);
    strcpy_s(a.AuthCode, g_chAuthCode);
    strcpy_s(a.AppID, g_chAppID);
    strcpy_s(a.UserProductInfo, g_chAppID);
    int b = pApi->ReqAuthenticate(&a, nRequestID++);
    //printf("\t�ͻ�����֤ = [%d]\n", b);
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

    //����Ŀ���λ�����в�λ����
    spi.ReqOrderInsert_Ordinary(num,direction);
    _getch();

    if (Flag == 1) {
        while (Flag == 1)//ֻҪƽ�ֲ���û����ɣ���ѭ����ѯ
        {
            spi.ReqQryInvestorPositionDetail();
            WaitForSingleObject(g_hEvent, INFINITE);
        }
        printf("ƽ�����,�뱨�����֣�\n");
        spi.ReqOrderInsert_Ordinary(num, direction);
        _getch();
    }
    system("pause");
    return 1;
}