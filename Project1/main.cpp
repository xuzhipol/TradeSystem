#include<Database.h>  
#include<SpiClass.h>  

using namespace std;  
int nRequestID = 0;//ȫ�ֱ�������¼����ID

int main()
{
    system("COLOR 0a");
    CThostFtdcTraderApi* pApi = CThostFtdcTraderApi::CreateFtdcTraderApi();
    SpiClass spi(pApi);
    pApi->RegisterSpi(&spi);
    printf("\napi�汾: \n%s", pApi->GetApiVersion());
    pApi->RegisterFront("tcp://172.16.31.10:10010");
}