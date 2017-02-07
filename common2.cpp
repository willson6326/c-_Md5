#include "stdafx.h"
#include "md5.h"
#include <iostream>
#include <string>
#include <algorithm>  

using namespace std;

unsigned char* makeBetDetail(string stationId,string gameRule,string issueNumber,string runCode,string sellDate,string betNumber)
{
	string betDetailStr = stationId + gameRule + issueNumber + runCode + sellDate + betNumber;
	int len = betDetailStr.length();

	if (len < 178)
	{
		betDetailStr.append(178 - len,'\0');
	}

	char* betDetail = (char*)calloc(178, sizeof(char*)); 
	strcpy(betDetail,betDetailStr.c_str());

    return (unsigned char*)betDetail;
}

string getOdd(string src) 
{
	string result = "";
    const char* srcChars = src.c_str();
    for (int i = 0; i < src.length(); i++)
	{
        if (i % 2 == 0) 
		{
            result.append(1,srcChars[i]);
        }
    }
    for (int j = 0; j < src.length(); j++) 
	{
        if (j % 2 != 0) 
		{
            result.append(1,srcChars[j]);
        }
    }
    return result;
}

string generateCheckCode(string stationId,string gameRule,string issueNumber,string runCode,string sellDate,string betNumber)
{
	MD5 iMD5;
	
	unsigned char * betDetail = makeBetDetail(stationId, gameRule, issueNumber, runCode, sellDate, betNumber);
    iMD5.GenerateMD5(betDetail, 178);
	free(betDetail);

    string result = iMD5.ToString();

	transform(result.begin(), result.end(), result.begin(), ::toupper);  

	return getOdd(result);
}

int main()
{
    string stationId = "32010001";
	string gameRule = "B001";
	string issueNumber = "2005001";
	string runCode = "00001";
	string sellDate = "2005-03-09 18:18:18";
	string betNumber = "01020304050607^08091011121314^15161718192021^22232425262728^29303132333435^";

    string temp = generateCheckCode(stationId, gameRule, issueNumber, runCode, sellDate, betNumber);
	
	cout<<temp<<endl;

	cout<<stationId.length() + gameRule.length() + issueNumber.length() + runCode.length() + sellDate.length() + betNumber.length()<<endl;

	unsigned char * betDetail = makeBetDetail(stationId, gameRule, issueNumber, runCode, sellDate, betNumber);
	cout<<betDetail<<endl;
	free(betDetail);

	return 0;
}