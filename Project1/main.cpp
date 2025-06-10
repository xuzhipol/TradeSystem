#include<Database.h>  
#include<SpiClass.h>  

using namespace std;  
int nRequestID = 0;//全局变量，记录请求ID

int main()
{
    system("COLOR 0a");
    CThostFtdcTraderApi* pApi = CThostFtdcTraderApi::CreateFtdcTraderApi();
    SpiClass spi(pApi);
    pApi->RegisterSpi(&spi);
    printf("\napi版本: \n%s", pApi->GetApiVersion());
    pApi->RegisterFront("tcp://172.16.31.10:10010");
}