#include <conio.h> 
#include "Database.h"

string getattribute(string Instrument_ID, string attribute)
{
	const char* TragetFile = "Ŀ���λ.txt";
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
		if (strtmp.substr(0, 1) == "#")	continue;	//����ע��		
		if (flag == 0)
		{
			if (strtmp.find(Instrument_ID) != string::npos)
			{
				if (strtmp.substr(0, 1) == "[")
				{
					if (strtmp.find("]") == string::npos) 	break;	//ȱʧ��]���˳�
					strtitle = strtmp.substr(1);
					strtitle = strtitle.erase(strtitle.find("]"));
					if (strtitle == Instrument_ID)		//�ҵ���������ñ�־λΪ1�������Ͳ�������һ���������
					{
						flag = 1;
						continue;
					}
				}
			}
		}
		if (flag == 1)
		{
			if (strtmp.substr(0, 1) == "[")	break;	//���������һ��[]��˵����ǰ������Ӧ�������ֶ�������ϣ�����������
			if (strtmp.find(attribute) != string::npos)
			{
				if (strtmp.find("=") == string::npos)	break;	//ȱʧ��=���˳�
				strcfgname = strtmp;
				strcfgname = strcfgname.erase(strcfgname.find("="));
				if (strcfgname == attribute)		//�ҵ��������Ӧ���ֶκ󣬷���ֵ
				{
					returnValue = strtmp.substr(strtmp.find("=") + 1);
					return returnValue;
				}
				else continue;
			}
		}
	}
	cout << "�����ļ�����û�ҵ�" << Instrument_ID << "��Ӧ������" << attribute << "��" << endl;
	_getch();
	exit(-1);
}

