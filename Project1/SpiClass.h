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

extern int nRequestID;  //ȫ�ֱ�������¼����ID
extern const char* g_chFrontaddr;
extern TThostFtdcBrokerIDType g_chBrokerID;
extern TThostFtdcUserIDType g_chUserID;
extern TThostFtdcPasswordType g_chPassword;
extern TThostFtdcLoginRemarkType	LoginRemark;
extern TThostFtdcAuthCodeType	g_chAuthCode;
extern TThostFtdcAppIDType	g_chAppID;
extern TThostFtdcInstrumentIDType	g_chInstrumentID;
extern TThostFtdcInvestorIDType g_chInvestorID;
extern HANDLE g_hEvent; // ȫ�ֱ������¼���������ڵȴ��첽�������


//  �ص��࣬�̳з����ṩ�ӿڣ���д�����еĲ��ֻص�����
class SpiClass : public CThostFtdcTraderSpi
{
private:
    CThostFtdcTraderApi *pApi;

public:
    SpiClass() {};  //���캯��
    SpiClass(CThostFtdcTraderApi* api) :pApi(api) {};
    virtual ~SpiClass() {};

    // ��ѯ�ֲ�
    void ReqQryInvestorPositionDetail();

    ///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
    virtual void OnFrontConnected();

    ///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
    ///@param nReason ����ԭ��
    ///        0x1001 �����ʧ��
    ///        0x1002 ����дʧ��
    ///        0x2001 ����������ʱ
    ///        0x2002 ��������ʧ��
    ///        0x2003 �յ�������
    virtual void OnFrontDisconnected(int nReason);

    ///�ͻ�����֤��Ӧ
    virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    ///��¼������Ӧ
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);    

    ///�ǳ�������Ӧ
    virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����Ӧ��
    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);    

    ///��������Ӧ��
    virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///�����ѯͶ���ֲ߳���Ӧ
    void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
   
    ///�����ѯ�ʽ��˻���Ӧ
    virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
};

