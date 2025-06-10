#include <conio.h> 
#include "Database.h"

string getattribute(string Instrument_ID, string attribute)
{
	const char* TragetFile = "目标仓位.txt";
	ifstream tragetfile(TragetFile);
	if (!tragetfile.is_open())
	{
		cerr << "Could not open " << TragetFile << endl;
		tragetfile.clear();
		_getch(); 
		exit(-1);
	}
	string strtmp, strtitle, strcfgname, returnValue;
	int flag = 0;
	while (getline(tragetfile, strtmp, '\n'))
	{
		if (strtmp.substr(0, 1) == "#")	continue;	//过滤注释		
		if (flag == 0)
		{
			if (strtmp.find(Instrument_ID) != string::npos)
			{
				if (strtmp.substr(0, 1) == "[")
				{
					if (strtmp.find("]") == string::npos) 	break;	//缺失“]”退出
					strtitle = strtmp.substr(1);
					strtitle = strtitle.erase(strtitle.find("]"));
					if (strtitle == Instrument_ID)		//找到大标题设置标志位为1，这样就不再找下一个大标题了
					{
						flag = 1;
						continue;
					}
				}
			}
		}
		if (flag == 1)
		{
			if (strtmp.substr(0, 1) == "[")	break;	//如果遇到下一个[]号说明当前大标题对应的配置字段搜索完毕，结束搜索。
			if (strtmp.find(attribute) != string::npos)
			{
				if (strtmp.find("=") == string::npos)	break;	//缺失“=”退出
				strcfgname = strtmp;
				strcfgname = strcfgname.erase(strcfgname.find("="));
				if (strcfgname == attribute)		//找到大标题相应的字段后，返回值
				{
					returnValue = strtmp.substr(strtmp.find("=") + 1);
					return returnValue;
				}
				else continue;
			}
		}
	}
	cout << "配置文件错误：没找到" << Instrument_ID << "对应配置项" << attribute << "！" << endl;
	_getch();
	exit(-1);
}

