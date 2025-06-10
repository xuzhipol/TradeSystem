#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

//读取文本文件中的目标仓位，其中目标仓位以键值对的形式存储，包括多空方向，持仓量和开平价格。
//后续应改写成从MongoDB数据库中读取
string getattribute(string Instrument_ID, string attribute);

