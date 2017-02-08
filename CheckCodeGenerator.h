
#include <string>

using namespace std;

class CheckCodeGenerator
{
private:

	unsigned char* makeBetDetail(string stationId,string gameRule,string issueNumber,string runCode,string sellDate,string betNumber);
    string getOdd(string src);

public:

    string generateCheckCode(string stationId,string gameRule,string issueNumber,string runCode,string sellDate,string betNumber);
	CheckCodeGenerator();
	~CheckCodeGenerator();
};
