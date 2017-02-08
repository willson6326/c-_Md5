#include "stdafx.h"
#include "CheckCodeGenerator.h"
#include "md5.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

unsigned char* CheckCodeGenerator::makeBetDetail(string stationId,string gameRule,string issueNumber,string runCode,string sellDate,string betNumber)
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

string CheckCodeGenerator::getOdd(string src) 
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

string CheckCodeGenerator::generateCheckCode(string stationId,string gameRule,string issueNumber,string runCode,string sellDate,string betNumber)
{
	MD5 iMD5;
	
	unsigned char * betDetail = makeBetDetail(stationId, gameRule, issueNumber, runCode, sellDate, betNumber);
    iMD5.GenerateMD5(betDetail, 178);
	free(betDetail);

    string result = iMD5.ToString();

	transform(result.begin(), result.end(), result.begin(), ::toupper);  

	return getOdd(result);
}

CheckCodeGenerator::CheckCodeGenerator()
{

}

CheckCodeGenerator::~CheckCodeGenerator()
{

}