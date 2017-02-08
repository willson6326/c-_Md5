#include "stdafx.h"
#include "CheckCodeGenerator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;

void make(string stationId,string gameRule,string issueNumber,string runCode,string sellDate,string betNumber,string file)
{
	CheckCodeGenerator checkCodeGenerator;

	ofstream fout(file.c_str(),ios::app);
	string temp = checkCodeGenerator.generateCheckCode(stationId, gameRule, issueNumber, runCode, sellDate, betNumber);
	fout<<temp<<endl;
	fout.close();
}

void testStationId(string stationId,string gameRule,string issueNumber,string runCode,string sellDate,string betNumber)
{
	int count = 99999999;
	string file = "D:\\cfile\\station.txt";
	while (count > 98999999)
	{
		stringstream stream;  
        stream<<count;  
        stationId=stream.str();

		make(stationId,gameRule,issueNumber,runCode,sellDate,betNumber,file);
		count--;
	}
}

void testGameRule(string stationId,string gameRule,string issueNumber,string runCode,string sellDate,string betNumber)
{
	int count = 999;
	string file = "D:\\cfile\\gameRule.txt";
	while (count > 0)
	{
		stringstream stream;  
        stream<<count;  
        gameRule="B" + stream.str();

		make(stationId,gameRule,issueNumber,runCode,sellDate,betNumber,file);
		count--;
	}
}

void testIssueNumber(string stationId,string gameRule,string issueNumber,string runCode,string sellDate,string betNumber)
{
	int count = 2005001;
	string file = "D:\\cfile\\issueNumber.txt";
	while (count < 2017999)
	{
		stringstream stream;  
        stream<<count;  
        issueNumber=stream.str();

		make(stationId,gameRule,issueNumber,runCode,sellDate,betNumber,file);
		count++;
	}
}

void testRunCode(string stationId,string gameRule,string issueNumber,string runCode,string sellDate,string betNumber)
{
	int count = 99999;
	string file = "D:\\cfile\\runCode.txt";
	while (count > 0)
	{
		stringstream stream;  
        stream<<count;  
        runCode=stream.str();

		make(stationId,gameRule,issueNumber,runCode,sellDate,betNumber,file);
		count--;
	}
}

void showTime()
{
	time_t tt = time(NULL);
	tm* t= localtime(&tt);
	printf("%d-%02d-%02d %02d:%02d:%02d\n", 
		t->tm_year + 1900,
		t->tm_mon + 1,
		t->tm_mday,
		t->tm_hour,
		t->tm_min,
		t->tm_sec);
}

int main()
{
    string stationId = "32010001";
	string gameRule = "B001";
	string issueNumber = "2005001";
	string runCode = "00001";
	string sellDate = "2005-03-09 18:18:18";
	string betNumber = "01020304050607^08091011121314^15161718192021^22232425262728^29303132333435^";

	cout << "begin time:" << endl;
	showTime();
	
	testStationId(stationId,gameRule,issueNumber,runCode,sellDate,betNumber);
	//testGameRule(stationId,gameRule,issueNumber,runCode,sellDate,betNumber);
	//testIssueNumber(stationId,gameRule,issueNumber,runCode,sellDate,betNumber);
	//testRunCode(stationId,gameRule,issueNumber,runCode,sellDate,betNumber);

	cout << "end time:" << endl;
	showTime();

	return 0;
}