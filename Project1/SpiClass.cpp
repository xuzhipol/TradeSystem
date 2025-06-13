#include "SpiClass.h"  

void SpiClass::OnFrontConnected() {  
	printf("连接成功\n");
    SetEvent(g_hEvent);
    //printf("<OnFrontConnected>\n");
}

void SpiClass::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo,
	int nRequestID, bool bIsLast)
{
	//printf("<OnRspAuthenticate>\n");
	if (pRspAuthenticateField)
	{
		//printf("\tBrokerID [%s]\n", pRspAuthenticateField->BrokerID);
		printf("认证成功\n");
		//printf("\tUserProductInfo [%s]\n", pRspAuthenticateField->UserProductInfo);
		//printf("\tAppID [%s]\n", pRspAuthenticateField->AppID);
		//printf("\tAppType [%c]\n", pRspAuthenticateField->AppType);
	}
	if (pRspInfo)
	{
		//printf("\t认证失败\n");
		//printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
		//printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
	}
	//printf("\tnRequestID [%d]\n", nRequestID);
	//printf("\tbIsLast [%d]\n", bIsLast);
	//printf("</OnRspAuthenticate>\n");
	SetEvent(g_hEvent);
}

void SpiClass::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	//printf("<OnRspUserLogin>\n");
	if (pRspUserLogin)
	{
		//printf("\tTradingDay [%s]\n", pRspUserLogin->TradingDay);
		//printf("\tLoginTime [%s]\n", pRspUserLogin->LoginTime);
		//printf("\tBrokerID [%s]\n", pRspUserLogin->BrokerID);
		//printf("\tUserID [%s]\n", pRspUserLogin->UserID);
		//printf("\tSystemName [%s]\n", pRspUserLogin->SystemName);
		//printf("\tMaxOrderRef [%s]\n", pRspUserLogin->MaxOrderRef);
		//printf("\tSHFETime [%s]\n", pRspUserLogin->SHFETime);
		//printf("\tDCETime [%s]\n", pRspUserLogin->DCETime);
		//printf("\tCZCETime [%s]\n", pRspUserLogin->CZCETime);
		//printf("\tFFEXTime [%s]\n", pRspUserLogin->FFEXTime);
		//printf("\tINETime [%s]\n", pRspUserLogin->INETime);
		//printf("\tSysVersion [%s]\n", pRspUserLogin->SysVersion);
		//printf("\tGFEXTime [%s]\n", pRspUserLogin->GFEXTime);
		//printf("\tFrontID [%d]\n", pRspUserLogin->FrontID);
		//printf("\tSessionID [%d]\n", pRspUserLogin->SessionID);
		printf("登录成功\n");
		printf("欢迎您 %s\n", pRspUserLogin->UserID);
	}
	if (pRspInfo)
	{
		//printf("\t登录失败\n");
		//printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
		//printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
	}
	//printf("\tnRequestID [%d]\n", nRequestID);
	//printf("\tbIsLast [%d]\n", bIsLast);
	//printf("</OnRspUserLogin>\n");
	SetEvent(g_hEvent);
};

void SpiClass::OnFrontDisconnected(int nReason)
{
    printf("连接断开，断开原因：[%d]\n", nReason);
}

///登出请求响应
void SpiClass::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    //printf("<OnRspUserLogout>\n");
	if (pUserLogout)
	{
		//printf("\tBrokerID [%s]\n", pUserLogout->BrokerID);
		printf("已登出\tUserID [%s]\n", pUserLogout->UserID);
	}
	if (pRspInfo)
	{
		printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
		printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
	}
	//printf("\tnRequestID [%d]\n", nRequestID);
	//printf("\tbIsLast [%d]\n", bIsLast);
	//printf("</OnRspUserLogout>\n");
}

///错误应答
void SpiClass::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    //printf("<OnRspError>\n");
	if (pRspInfo)
	{
		printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
		printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
	}
	//printf("\tnRequestID [%d]\n", nRequestID);
	//printf("\tbIsLast [%d]\n", bIsLast);
	//printf("</OnRspError>\n");
}

///请求查询投资者持仓明细响应
void SpiClass::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	//printf("<OnRspQryInvestorPositionDetail>\n");
	if (pInvestorPositionDetail)
	{
		//printf("\treserve1 [%s]\n", pInvestorPositionDetail->reserve1);
		//printf("\t经纪公司为 [%s]\n", pInvestorPositionDetail->BrokerID);
		printf("\t投资者 [%s]\n", pInvestorPositionDetail->InvestorID);
		printf("\t开仓日期 [%s]\n", pInvestorPositionDetail->OpenDate);
		printf("\t成交编号 [%s]\n", pInvestorPositionDetail->TradeID);
		printf("\t交易日 [%s]\n", pInvestorPositionDetail->TradingDay);
		//printf("\treserve2 [%s]\n", pInvestorPositionDetail->reserve2);
		printf("\t交易所为 [%s]\n", pInvestorPositionDetail->ExchangeID);
		//printf("\tInvestUnitID [%s]\n", pInvestorPositionDetail->InvestUnitID);
		printf("\t合约 [%s]\n", pInvestorPositionDetail->InstrumentID);
		//printf("\tCombInstrumentID [%s]\n", pInvestorPositionDetail->CombInstrumentID);
		printf("\t持仓量 [%d]\n", pInvestorPositionDetail->Volume);
		num=pInvestorPositionDetail->Volume;
		if (num == 0)
			Flag = 0;
		//printf("\tSettlementID [%d]\n", pInvestorPositionDetail->SettlementID);
		printf("\t平仓量 [%d]\n", pInvestorPositionDetail->CloseVolume);
		//printf("\tTimeFirstVolume [%d]\n", pInvestorPositionDetail->TimeFirstVolume);
		//printf("\tHedgeFlag [%c]\n", pInvestorPositionDetail->HedgeFlag);
		printf("\t多空方向 [%s]\n", pInvestorPositionDetail->Direction=='0' ? "多" : "空");
		direction = pInvestorPositionDetail->Direction;
		//printf("\tTradeType [%c]\n", pInvestorPositionDetail->TradeType);
		//printf("\tSpecPosiType [%c]\n", pInvestorPositionDetail->SpecPosiType);
		printf("\t开仓价 [%.8lf]\n", pInvestorPositionDetail->OpenPrice);
		//printf("\tCloseProfitByDate [%.8lf]\n", pInvestorPositionDetail->CloseProfitByDate);
		//printf("\tCloseProfitByTrade [%.8lf]\n", pInvestorPositionDetail->CloseProfitByTrade);
		//printf("\tPositionProfitByDate [%.8lf]\n", pInvestorPositionDetail->PositionProfitByDate);
		printf("\t逐笔对冲持仓盈亏 [%.8lf]\n", pInvestorPositionDetail->PositionProfitByTrade);
		printf("\t保证金 [%.8lf]\n", pInvestorPositionDetail->Margin);
		//printf("\t交易所保证金 [%.8lf]\n", pInvestorPositionDetail->ExchMargin);
		printf("\t保证金率 [%.8lf]\n", pInvestorPositionDetail->MarginRateByMoney);
		//printf("\tMarginRateByVolume [%.8lf]\n", pInvestorPositionDetail->MarginRateByVolume);
		printf("\t昨结算价 [%.8lf]\n", pInvestorPositionDetail->LastSettlementPrice);
		//printf("\t结算价 [%.8lf]\n", pInvestorPositionDetail->SettlementPrice);
		printf("\t平仓金额 [%.8lf]\n", pInvestorPositionDetail->CloseAmount);
		//std::cout << "OnRspQryInvestorPositionDetail" << pInvestorPositionDetail->Volume << std::endl;
	}
	if (pRspInfo)
	{
		printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
		printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
	}
	//printf("\tnRequestID [%d]\n", nRequestID);
	//printf("\tbIsLast [%d]\n", bIsLast);
	//printf("</OnRspQryInvestorPositionDetail>\n");
    SetEvent(g_hEvent);
};

void SpiClass::ReqQryInvestorPositionDetail()
{
	CThostFtdcQryInvestorPositionDetailField a = { 0 };
	strcpy_s(a.BrokerID, g_chBrokerID);
	strcpy_s(a.InvestorID, g_chInvestorID);
	string instr;
	instr.clear();
	//cin.ignore();
	printf("\n请输入要操作的合约代码(不输入则默认为ss2508)\n");
	getline(cin, instr);
	strcpy_s(a.InstrumentID, instr.c_str());
	if(!instr.empty())
	strcpy_s(g_chInstrumentID, a.InstrumentID);//将输入的合约号赋值给全局变量
    else strcpy_s(a.InstrumentID, g_chInstrumentID);
	/*string exch;
	exch.clear();
	cin.ignore();
	LOG("请输入交易所代码(不输入则为空)：\n");
	getline(cin, exch);
	strcpy_s(a.ExchangeID, exch.c_str());*/

	int b = pApi->ReqQryInvestorPositionDetail(&a, nRequestID++);
	printf((b == 0) ? "持仓明细如下：\n" : "请求查询投资者持仓明细......发送失败，错误序号=[%d]\n", b);
}

void SpiClass::ReqOrderInsert_Ordinary(int nums, char directions)
{
	//system("cls");
	string new_limitprice;

	CThostFtdcInputOrderField ord = { 0 };
	ord.RequestID = 1234;
	strcpy_s(ord.BrokerID, g_chBrokerID);
	strcpy_s(ord.InvestorID, g_chInvestorID);
	strcpy_s(ord.InstrumentID, g_chInstrumentID);
	strcpy_s(ord.UserID, g_chUserID);
	OrderRef_num++;
	_itoa_s(OrderRef_num, ord.OrderRef, 10);
	//strcpy_s(ord.OrderRef,"");
	//strcpy_s(ord.OrderRef, itoa(OrderRef_num));
	ord.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
	ord.CombOffsetFlag[0] = THOST_FTDC_OF_Open;

	int num1;
Direction:printf("\n请选择目标多空方向\t1.多\t2.空\n");
	cin >> num1;
	if (num1 != 1 && num1 != 2) {
		printf("输入错误请重新输入\n");
		_getch();
		goto Direction;
	}

	int num3;
	printf("\n请输入目标持仓数量\n");
	cin >> num3;

	//int VolumeNum;
	if (directions - '0' == num1 - 1||nums==0)//当前持仓与目标持仓方向一致
	{
		printf("\n请输入价格：\n");
		cin >> new_limitprice;
		Flag = 0;
		if (num1 == 1)
		{
			if (num3 > nums) {
				ord.Direction = THOST_FTDC_D_Buy;///买入开仓
				ord.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
				ord.VolumeTotalOriginal = num3-nums;

			}
			else if (num3 < nums)
			{
                ord.Direction = THOST_FTDC_D_Sell;///卖出平仓
                ord.CombOffsetFlag[0] = THOST_FTDC_OF_Close;
				ord.VolumeTotalOriginal = nums-num3;
			}
			else
			{
				printf("当前持仓数量与目标持仓数量相同，无需报单\n");
				return;
			}
		}
		if (num1 == 2)
		{
            if (num3 > nums) {
				ord.Direction = THOST_FTDC_D_Sell;///卖出开仓
				ord.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
				ord.VolumeTotalOriginal = num3-nums;
			}
			else if (num3 < nums)
			{
				ord.Direction = THOST_FTDC_D_Buy;///买入平仓
				ord.CombOffsetFlag[0] = THOST_FTDC_OF_Close;
				ord.VolumeTotalOriginal = nums-num3;
			}
			else
			{
				printf("当前持仓数量与目标持仓数量相同，无需报单\n");
				return;
			}
		}
	}
	else//如果当前持仓与目标持仓方向相反，则需先平仓，再开仓，再开仓的操作留在主函数中完成
	{
		printf("\n请输入平仓价格：\n");
		cin >> new_limitprice;
		Flag = 1;
		if (num1 == 1)
		{
			ord.Direction = THOST_FTDC_D_Buy;///买入平仓
			ord.CombOffsetFlag[0] = THOST_FTDC_OF_Close;
			ord.VolumeTotalOriginal = nums;
		}
        else
        {
			ord.Direction = THOST_FTDC_D_Sell;///卖出平仓
			ord.CombOffsetFlag[0] = THOST_FTDC_OF_Close;
			ord.VolumeTotalOriginal = nums;
        }
	}

	printf("%d\n", ord.VolumeTotalOriginal);
	ord.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;
	ord.LimitPrice = atoi(new_limitprice.c_str());
	//ord.LimitPrice = 598;
	//ord.VolumeTotalOriginal = 1;
	ord.TimeCondition = THOST_FTDC_TC_GFD;///当日有效
	ord.VolumeCondition = THOST_FTDC_VC_AV;///任何数量
	ord.MinVolume = 1;
	ord.ContingentCondition = THOST_FTDC_CC_Immediately;
	ord.StopPrice = 0;
	ord.ForceCloseReason = THOST_FTDC_FCC_LackDeposit;
	ord.IsAutoSuspend = 0;
	strcpy_s(ord.ExchangeID, g_chExchangeID);
	int a = pApi->ReqOrderInsert(&ord, 1);
	printf((a == 0) ? "报单录入请求限价单......发送成功\n" : "报单录入请求限价单......发送失败，序号=[%d]\n", a);
	if(a==0&&Flag==0)
		printf("报单完成\n");
}

void SpiClass::OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	//printf("<OnRspOrderInsert>\n");
	if (pInputOrder)
	{
		//printf("\tBrokerID [%s]\n", pInputOrder->BrokerID);
		//printf("\tInvestorID [%s]\n", pInputOrder->InvestorID);
		//printf("\treserve1 [%s]\n", pInputOrder->reserve1);
		printf("\t报单引用 [%s]\n", pInputOrder->OrderRef);
		//printf("\tUserID [%s]\n", pInputOrder->UserID);
		//printf("\tCombOffsetFlag [%s]\n", pInputOrder->CombOffsetFlag);
		//printf("\tCombHedgeFlag [%s]\n", pInputOrder->CombHedgeFlag);
		//printf("\tGTDDate [%s]\n", pInputOrder->GTDDate);
		//printf("\tBusinessUnit [%s]\n", pInputOrder->BusinessUnit);
		//printf("\tExchangeID [%s]\n", pInputOrder->ExchangeID);
		//printf("\tInvestUnitID [%s]\n", pInputOrder->InvestUnitID);
		//printf("\tAccountID [%s]\n", pInputOrder->AccountID);
		//printf("\tCurrencyID [%s]\n", pInputOrder->CurrencyID);
		printf("\t交易编码 [%s]\n", pInputOrder->ClientID);
		//printf("\treserve2 [%s]\n", pInputOrder->reserve2);
		//printf("\tMacAddress [%s]\n", pInputOrder->MacAddress);
		//printf("\tInstrumentID [%s]\n", pInputOrder->InstrumentID);
		//printf("\tIPAddress [%s]\n", pInputOrder->IPAddress);
		//printf("\tVolumeTotalOriginal [%d]\n", pInputOrder->VolumeTotalOriginal);
		//printf("\tMinVolume [%d]\n", pInputOrder->MinVolume);
		//printf("\tIsAutoSuspend [%d]\n", pInputOrder->IsAutoSuspend);
		printf("\t请求编号 [%d]\n", pInputOrder->RequestID);
		printf("\t强平标志 [%d]\n", pInputOrder->UserForceClose);
		//printf("\tIsSwapOrder [%d]\n", pInputOrder->IsSwapOrder);
		//printf("\tOrderPriceType [%c]\n", pInputOrder->OrderPriceType);
		printf("\t买卖方向 [%c]\n", pInputOrder->Direction);
		printf("\t有效期 [%c]\n", pInputOrder->TimeCondition);
		//printf("\tVolumeCondition [%c]\n", pInputOrder->VolumeCondition);
		//printf("\tContingentCondition [%c]\n", pInputOrder->ContingentCondition);
		//printf("\tForceCloseReason [%c]\n", pInputOrder->ForceCloseReason);
		printf("\t价格 [%.8lf]\n", pInputOrder->LimitPrice);
		//printf("\tStopPrice [%.8lf]\n", pInputOrder->StopPrice);
	}
	if (pRspInfo)
	{
		printf("\tErrorMsg [%s]\n", pRspInfo->ErrorMsg);
		printf("\tErrorID [%d]\n", pRspInfo->ErrorID);
	}
	//printf("\tnRequestID [%d]\n", nRequestID);
	//printf("\tbIsLast [%d]\n", bIsLast);
	//printf("</OnRspOrderInsert>\n");
};

void SpiClass::OnRtnOrder(CThostFtdcOrderField* pOrder)
{
	printf("报单回报\n");
	if (pOrder)
	{
		//LOG("\tBrokerID [%s]\n", pOrder->BrokerID);
		//LOG("\tInvestorID [%s]\n", pOrder->InvestorID);
		//LOG("\treserve1 [%s]\n", pOrder->reserve1);
		printf("\t报单引用 [%s]\n", pOrder->OrderRef);
		//LOG("\tUserID [%s]\n", pOrder->UserID);
		//LOG("\tCombOffsetFlag [%s]\n", pOrder->CombOffsetFlag);
		//LOG("\tCombHedgeFlag [%s]\n", pOrder->CombHedgeFlag);
		//LOG("\tGTDDate [%s]\n", pOrder->GTDDate);
		//LOG("\tBusinessUnit [%s]\n", pOrder->BusinessUnit);
		printf("\t本地报单编号 [%s]\n", pOrder->OrderLocalID);
		//LOG("\tExchangeID [%s]\n", pOrder->ExchangeID);
		//LOG("\tParticipantID [%s]\n", pOrder->ParticipantID);
		printf("\t客户代码 [%s]\n", pOrder->ClientID);
		//LOG("\treserve2 [%s]\n", pOrder->reserve2);
		printf("\t交易员代码 [%s]\n", pOrder->TraderID);
		//LOG("\tTradingDay [%s]\n", pOrder->TradingDay);
		//printf("\t报单编号 [%s]\n", pOrder->OrderSysID);
		printf("\t报单日期 [%s]\n", pOrder->InsertDate);
		printf("\t委托时间 [%s]\n", pOrder->InsertTime);
		//LOG("\tActiveTime [%s]\n", pOrder->ActiveTime);
		//LOG("\tSuspendTime [%s]\n", pOrder->SuspendTime);
		//LOG("\tUpdateTime [%s]\n", pOrder->UpdateTime);
		//LOG("\tCancelTime [%s]\n", pOrder->CancelTime);
		//LOG("\tActiveTraderID [%s]\n", pOrder->ActiveTraderID);
		//LOG("\tClearingPartID [%s]\n", pOrder->ClearingPartID);
		//LOG("\tUserProductInfo [%s]\n", pOrder->UserProductInfo);
		//LOG("\tStatusMsg [%s]\n", pOrder->StatusMsg);
		//LOG("\tActiveUserID [%s]\n", pOrder->ActiveUserID);
		//LOG("\tRelativeOrderSysID [%s]\n", pOrder->RelativeOrderSysID);
		//LOG("\tBranchID [%s]\n", pOrder->BranchID);
		//LOG("\tInvestUnitID [%s]\n", pOrder->InvestUnitID);
		//LOG("\tAccountID [%s]\n", pOrder->AccountID);
		//LOG("\tCurrencyID [%s]\n", pOrder->CurrencyID);
		//LOG("\treserve3 [%s]\n", pOrder->reserve3);
		//LOG("\tMacAddress [%s]\n", pOrder->MacAddress);
		//LOG("\tInstrumentID [%s]\n", pOrder->InstrumentID);
		//LOG("\tExchangeInstID [%s]\n", pOrder->ExchangeInstID);
		//LOG("\tIPAddress [%s]\n", pOrder->IPAddress);
		printf("\t数量 [%d]\n", pOrder->VolumeTotalOriginal);
		//LOG("\tMinVolume [%d]\n", pOrder->MinVolume);
		//LOG("\tIsAutoSuspend [%d]\n", pOrder->IsAutoSuspend);
		//LOG("\tRequestID [%d]\n", pOrder->RequestID);
		//LOG("\tInstallID [%d]\n", pOrder->InstallID);
		//LOG("\tNotifySequence [%d]\n", pOrder->NotifySequence);
		//LOG("\tSettlementID [%d]\n", pOrder->SettlementID);
		//LOG("\tVolumeTraded [%d]\n", pOrder->VolumeTraded);
		//LOG("\tVolumeTotal [%d]\n", pOrder->VolumeTotal);
		//LOG("\tSequenceNo [%d]\n", pOrder->SequenceNo);
		//LOG("\tFrontID [%d]\n", pOrder->FrontID);
		//LOG("\tSessionID [%d]\n", pOrder->SessionID);
		//LOG("\tUserForceClose [%d]\n", pOrder->UserForceClose);
		//LOG("\tBrokerOrderSeq [%d]\n", pOrder->BrokerOrderSeq);
		//LOG("\tZCETotalTradedVolume [%d]\n", pOrder->ZCETotalTradedVolume);
		//LOG("\tIsSwapOrder [%d]\n", pOrder->IsSwapOrder);
		//LOG("\tOrderPriceType [%c]\n", pOrder->OrderPriceType);
		//LOG("\tDirection [%c]\n", pOrder->Direction);
		//LOG("\tTimeCondition [%c]\n", pOrder->TimeCondition);
		//LOG("\tVolumeCondition [%c]\n", pOrder->VolumeCondition);
		//LOG("\tContingentCondition [%c]\n", pOrder->ContingentCondition);
		//LOG("\tForceCloseReason [%c]\n", pOrder->ForceCloseReason);
		//LOG("\tOrderSubmitStatus [%c]\n", pOrder->OrderSubmitStatus);
		//LOG("\tOrderSource [%c]\n", pOrder->OrderSource);
		//LOG("\tOrderStatus [%c]\n", pOrder->OrderStatus);
		//LOG("\tOrderType [%c]\n", pOrder->OrderType);
		//LOG("\tLimitPrice [%.8lf]\n", pOrder->LimitPrice);
		//LOG("\tStopPrice [%.8lf]\n", pOrder->StopPrice);
	}
	//printf("</OnRtnOrder>\n");
};

void SpiClass::OnRtnTrade(CThostFtdcTradeField* pTrade)
{
	printf("报单成交\n");
	if (pTrade)
	{
		//LOG("\tBrokerID [%s]\n", pTrade->BrokerID);
		//LOG("\tInvestorID [%s]\n", pTrade->InvestorID);
		//LOG("\treserve1 [%s]\n", pTrade->reserve1);
		//LOG("\tOrderRef [%s]\n", pTrade->OrderRef);
		//LOG("\tUserID [%s]\n", pTrade->UserID);
		//LOG("\tExchangeID [%s]\n", pTrade->ExchangeID);
		//LOG("\tTradeID [%s]\n", pTrade->TradeID);
		//LOG("\tOrderSysID [%s]\n", pTrade->OrderSysID);
		//LOG("\tParticipantID [%s]\n", pTrade->ParticipantID);
		//LOG("\tClientID [%s]\n", pTrade->ClientID);
		//LOG("\treserve2 [%s]\n", pTrade->reserve2);
		printf("\t成交日期 [%s]\n", pTrade->TradeDate);
		printf("\t成交时间 [%s]\n", pTrade->TradeTime);
		//LOG("\tTraderID [%s]\n", pTrade->TraderID);
		//LOG("\tOrderLocalID [%s]\n", pTrade->OrderLocalID);
		//LOG("\tClearingPartID [%s]\n", pTrade->ClearingPartID);
		///LOG("\tBusinessUnit [%s]\n", pTrade->BusinessUnit);
		///LOG("\tTradingDay [%s]\n", pTrade->TradingDay);
		//LOG("\tInvestUnitID [%s]\n", pTrade->InvestUnitID);
		//LOG("\tInstrumentID [%s]\n", pTrade->InstrumentID);
		//LOG("\tExchangeInstID [%s]\n", pTrade->ExchangeInstID);
		//LOG("\tVolume [%d]\n", pTrade->Volume);
		//LOG("\tSequenceNo [%d]\n", pTrade->SequenceNo);
		//LOG("\tSettlementID [%d]\n", pTrade->SettlementID);
		//LOG("\tBrokerOrderSeq [%d]\n", pTrade->BrokerOrderSeq);
		//LOG("\tDirection [%c]\n", pTrade->Direction);
		//LOG("\tTradingRole [%c]\n", pTrade->TradingRole);
		//LOG("\tOffsetFlag [%c]\n", pTrade->OffsetFlag);
		//LOG("\tHedgeFlag [%c]\n", pTrade->HedgeFlag);
		//LOG("\tTradeType [%c]\n", pTrade->TradeType);
		//LOG("\tPriceSource [%c]\n", pTrade->PriceSource);
		//LOG("\tTradeSource [%c]\n", pTrade->TradeSource);
		//LOG("\tPrice [%.8lf]\n", pTrade->Price);
	}
	//printf("</OnRtnTrade>\n");
};

