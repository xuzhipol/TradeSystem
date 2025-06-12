#include "SpiClass.h"  

void SpiClass::OnFrontConnected() {  
	printf("<OnFrontConnected>\n");
    SetEvent(g_hEvent);
    printf("<OnFrontConnected>\n");
}

void SpiClass::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo,
	int nRequestID, bool bIsLast)
{
	printf("<OnRspAuthenticate>\n");
	if (pRspAuthenticateField)
	{
		printf("\tBrokerID [%s]\n", pRspAuthenticateField->BrokerID);
		printf("\tUserID [%s]\n", pRspAuthenticateField->UserID);
		printf("\tUserProductInfo [%s]\n", pRspAuthenticateField->UserProductInfo);
		printf("\tAppID [%s]\n", pRspAuthenticateField->AppID);
		printf("\tAppType [%c]\n", pRspAuthenticateField->AppType);
	}
	if (pRspInfo)
	{
		printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
		printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
	}
	printf("\tnRequestID [%d]\n", nRequestID);
	printf("\tbIsLast [%d]\n", bIsLast);
	printf("</OnRspAuthenticate>\n");
	SetEvent(g_hEvent);
}

void SpiClass::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	printf("<OnRspUserLogin>\n");
	if (pRspUserLogin)
	{
		printf("\tTradingDay [%s]\n", pRspUserLogin->TradingDay);
		printf("\tLoginTime [%s]\n", pRspUserLogin->LoginTime);
		printf("\tBrokerID [%s]\n", pRspUserLogin->BrokerID);
		printf("\tUserID [%s]\n", pRspUserLogin->UserID);
		printf("\tSystemName [%s]\n", pRspUserLogin->SystemName);
		printf("\tMaxOrderRef [%s]\n", pRspUserLogin->MaxOrderRef);
		printf("\tSHFETime [%s]\n", pRspUserLogin->SHFETime);
		printf("\tDCETime [%s]\n", pRspUserLogin->DCETime);
		printf("\tCZCETime [%s]\n", pRspUserLogin->CZCETime);
		printf("\tFFEXTime [%s]\n", pRspUserLogin->FFEXTime);
		printf("\tINETime [%s]\n", pRspUserLogin->INETime);
		printf("\tSysVersion [%s]\n", pRspUserLogin->SysVersion);
		printf("\tGFEXTime [%s]\n", pRspUserLogin->GFEXTime);
		printf("\tFrontID [%d]\n", pRspUserLogin->FrontID);
		printf("\tSessionID [%d]\n", pRspUserLogin->SessionID);
	}
	if (pRspInfo)
	{
		printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
		printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
	}
	printf("\tnRequestID [%d]\n", nRequestID);
	printf("\tbIsLast [%d]\n", bIsLast);
	printf("</OnRspUserLogin>\n");
	SetEvent(g_hEvent);
};

void SpiClass::OnFrontDisconnected(int nReason)
{
    printf("OnFrontDisconnected [%d]\n", nReason);
}

///登出请求响应
void SpiClass::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    printf("<OnRspUserLogout>\n");
	if (pUserLogout)
	{
		printf("\tBrokerID [%s]\n", pUserLogout->BrokerID);
		printf("\tUserID [%s]\n", pUserLogout->UserID);
	}
	if (pRspInfo)
	{
		printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
		printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
	}
	printf("\tnRequestID [%d]\n", nRequestID);
	printf("\tbIsLast [%d]\n", bIsLast);
	printf("</OnRspUserLogout>\n");
}

///错误应答
void SpiClass::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    printf("<OnRspError>\n");
	if (pRspInfo)
	{
		printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
		printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
	}
	printf("\tnRequestID [%d]\n", nRequestID);
	printf("\tbIsLast [%d]\n", bIsLast);
	printf("</OnRspError>\n");
}

///订阅行情应答
void SpiClass::OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	printf("<OnRspSubMarketData>\n");
    if (pSpecificInstrument)
    {
        printf("\tInstrumentID [%s]\n", pSpecificInstrument->InstrumentID);
    }
    if (pRspInfo)
    {
        printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
        printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
    }
    printf("\tnRequestID [%d]\n", nRequestID);
    printf("\tbIsLast [%d]\n", bIsLast);
    printf("</OnRspSubMarketData>\n");
}

///请求查询投资者持仓明细响应
void SpiClass::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	printf("<OnRspQryInvestorPositionDetail>\n");
	if (pInvestorPositionDetail)
	{
		printf("\treserve1 [%s]\n", pInvestorPositionDetail->reserve1);
		printf("\tBrokerID [%s]\n", pInvestorPositionDetail->BrokerID);
		printf("\tInvestorID [%s]\n", pInvestorPositionDetail->InvestorID);
		printf("\tOpenDate [%s]\n", pInvestorPositionDetail->OpenDate);
		printf("\tTradeID [%s]\n", pInvestorPositionDetail->TradeID);
		printf("\tTradingDay [%s]\n", pInvestorPositionDetail->TradingDay);
		printf("\treserve2 [%s]\n", pInvestorPositionDetail->reserve2);
		printf("\tExchangeID [%s]\n", pInvestorPositionDetail->ExchangeID);
		printf("\tInvestUnitID [%s]\n", pInvestorPositionDetail->InvestUnitID);
		printf("\tInstrumentID [%s]\n", pInvestorPositionDetail->InstrumentID);
		printf("\tCombInstrumentID [%s]\n", pInvestorPositionDetail->CombInstrumentID);
		printf("\tVolume [%d]\n", pInvestorPositionDetail->Volume);
		printf("\tSettlementID [%d]\n", pInvestorPositionDetail->SettlementID);
		printf("\tCloseVolume [%d]\n", pInvestorPositionDetail->CloseVolume);
		printf("\tTimeFirstVolume [%d]\n", pInvestorPositionDetail->TimeFirstVolume);
		printf("\tHedgeFlag [%c]\n", pInvestorPositionDetail->HedgeFlag);
		printf("\tDirection [%c]\n", pInvestorPositionDetail->Direction);
		printf("\tTradeType [%c]\n", pInvestorPositionDetail->TradeType);
		printf("\tSpecPosiType [%c]\n", pInvestorPositionDetail->SpecPosiType);
		printf("\tOpenPrice [%.8lf]\n", pInvestorPositionDetail->OpenPrice);
		printf("\tCloseProfitByDate [%.8lf]\n", pInvestorPositionDetail->CloseProfitByDate);
		printf("\tCloseProfitByTrade [%.8lf]\n", pInvestorPositionDetail->CloseProfitByTrade);
		printf("\tPositionProfitByDate [%.8lf]\n", pInvestorPositionDetail->PositionProfitByDate);
		printf("\tPositionProfitByTrade [%.8lf]\n", pInvestorPositionDetail->PositionProfitByTrade);
		printf("\tMargin [%.8lf]\n", pInvestorPositionDetail->Margin);
		printf("\tExchMargin [%.8lf]\n", pInvestorPositionDetail->ExchMargin);
		printf("\tMarginRateByMoney [%.8lf]\n", pInvestorPositionDetail->MarginRateByMoney);
		printf("\tMarginRateByVolume [%.8lf]\n", pInvestorPositionDetail->MarginRateByVolume);
		printf("\tLastSettlementPrice [%.8lf]\n", pInvestorPositionDetail->LastSettlementPrice);
		printf("\tSettlementPrice [%.8lf]\n", pInvestorPositionDetail->SettlementPrice);
		printf("\tCloseAmount [%.8lf]\n", pInvestorPositionDetail->CloseAmount);
		//std::cout << "OnRspQryInvestorPositionDetail" << pInvestorPositionDetail->Volume << std::endl;
	}
	if (pRspInfo)
	{
		printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
		printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
	}
	printf("\tnRequestID [%d]\n", nRequestID);
	printf("\tbIsLast [%d]\n", bIsLast);
	printf("</OnRspQryInvestorPositionDetail>\n");
    SetEvent(g_hEvent);
};

///请求查询资金账户响应
void SpiClass::OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	printf("<OnRspQryTradingAccount>\n");
	if (pTradingAccount)
	{
		printf("\tBrokerID [%s]\n", pTradingAccount->BrokerID);
		printf("\tAccountID [%s]\n", pTradingAccount->AccountID);
		printf("\tTradingDay [%s]\n", pTradingAccount->TradingDay);
		printf("\tCurrencyID [%s]\n", pTradingAccount->CurrencyID);
		printf("\tSettlementID [%d]\n", pTradingAccount->SettlementID);
		printf("\tBizType [%c]\n", pTradingAccount->BizType);
		printf("\tPreMortgage [%.8lf]\n", pTradingAccount->PreMortgage);
		printf("\tPreCredit [%.8lf]\n", pTradingAccount->PreCredit);
		printf("\tPreDeposit [%.8lf]\n", pTradingAccount->PreDeposit);
		printf("\tPreBalance [%.8lf]\n", pTradingAccount->PreBalance);
		printf("\tPreMargin [%.8lf]\n", pTradingAccount->PreMargin);
		printf("\tInterestBase [%.8lf]\n", pTradingAccount->InterestBase);
		printf("\tInterest [%.8lf]\n", pTradingAccount->Interest);
		printf("\tDeposit [%.8lf]\n", pTradingAccount->Deposit);
		printf("\tWithdraw [%.8lf]\n", pTradingAccount->Withdraw);
		printf("\tFrozenMargin [%.8lf]\n", pTradingAccount->FrozenMargin);
		printf("\tFrozenCash [%.8lf]\n", pTradingAccount->FrozenCash);
		printf("\tFrozenCommission [%.8lf]\n", pTradingAccount->FrozenCommission);
		printf("\tCurrMargin [%.8lf]\n", pTradingAccount->CurrMargin);
		printf("\tCashIn [%.8lf]\n", pTradingAccount->CashIn);
		printf("\tCommission [%.8lf]\n", pTradingAccount->Commission);
		printf("\tCloseProfit [%.8lf]\n", pTradingAccount->CloseProfit);
		printf("\tPositionProfit [%.8lf]\n", pTradingAccount->PositionProfit);
		printf("\tBalance [%.8lf]\n", pTradingAccount->Balance);
		printf("\tAvailable [%.8lf]\n", pTradingAccount->Available);
		printf("\tWithdrawQuota [%.8lf]\n", pTradingAccount->WithdrawQuota);
		printf("\tReserve [%.8lf]\n", pTradingAccount->Reserve);
		printf("\tCredit [%.8lf]\n", pTradingAccount->Credit);
		printf("\tMortgage [%.8lf]\n", pTradingAccount->Mortgage);
		printf("\tExchangeMargin [%.8lf]\n", pTradingAccount->ExchangeMargin);
		printf("\tDeliveryMargin [%.8lf]\n", pTradingAccount->DeliveryMargin);
		printf("\tExchangeDeliveryMargin [%.8lf]\n", pTradingAccount->ExchangeDeliveryMargin);
		printf("\tReserveBalance [%.8lf]\n", pTradingAccount->ReserveBalance);
		printf("\tPreFundMortgageIn [%.8lf]\n", pTradingAccount->PreFundMortgageIn);
		printf("\tPreFundMortgageOut [%.8lf]\n", pTradingAccount->PreFundMortgageOut);
		printf("\tFundMortgageIn [%.8lf]\n", pTradingAccount->FundMortgageIn);
		printf("\tFundMortgageOut [%.8lf]\n", pTradingAccount->FundMortgageOut);
		printf("\tFundMortgageAvailable [%.8lf]\n", pTradingAccount->FundMortgageAvailable);
		printf("\tMortgageableFund [%.8lf]\n", pTradingAccount->MortgageableFund);
		printf("\tSpecProductMargin [%.8lf]\n", pTradingAccount->SpecProductMargin);
		printf("\tSpecProductFrozenMargin [%.8lf]\n", pTradingAccount->SpecProductFrozenMargin);
		printf("\tSpecProductCommission [%.8lf]\n", pTradingAccount->SpecProductCommission);
		printf("\tSpecProductFrozenCommission [%.8lf]\n", pTradingAccount->SpecProductFrozenCommission);
		printf("\tSpecProductPositionProfit [%.8lf]\n", pTradingAccount->SpecProductPositionProfit);
		printf("\tSpecProductCloseProfit [%.8lf]\n", pTradingAccount->SpecProductCloseProfit);
		printf("\tSpecProductPositionProfitByAlg [%.8lf]\n", pTradingAccount->SpecProductPositionProfitByAlg);
		printf("\tSpecProductExchangeMargin [%.8lf]\n", pTradingAccount->SpecProductExchangeMargin);
		printf("\tFrozenSwap [%.8lf]\n", pTradingAccount->FrozenSwap);
		printf("\tRemainSwap [%.8lf]\n", pTradingAccount->RemainSwap);
	}
	if (pRspInfo)
	{
		printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
		printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
	}
	printf("\tnRequestID [%d]\n", nRequestID);
	printf("\tbIsLast [%d]\n", bIsLast);
	printf("</OnRspQryTradingAccount>\n");
};

void SpiClass::ReqQryInvestorPositionDetail()
{
	CThostFtdcQryInvestorPositionDetailField a = { 0 };
	strcpy_s(a.BrokerID, g_chBrokerID);
	strcpy_s(a.InvestorID, g_chInvestorID);
	string instr;
	instr.clear();
	cin.ignore();
	printf("请输入合约代码(不输入则为空)\n");
	getline(cin, instr);
	strcpy_s(a.InstrumentID, instr.c_str());

	//strcpy_s(a.InstrumentID, g_chInstrumentID);
	/*string exch;
	exch.clear();
	cin.ignore();
	LOG("请输入交易所代码(不输入则为空)：\n");
	getline(cin, exch);
	strcpy_s(a.ExchangeID, exch.c_str());*/

	int b = pApi->ReqQryInvestorPositionDetail(&a, nRequestID++);
	printf((b == 0) ? "请求查询投资者持仓明细......发送成功\n" : "请求查询投资者持仓明细......发送失败，错误序号=[%d]\n", b);
}