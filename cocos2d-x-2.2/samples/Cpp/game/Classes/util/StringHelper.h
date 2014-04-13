#ifndef _STRING_HELPER_
#define _STRING_HELPER_
#include <vector>
#include <string>
using namespace std;

class StringHelper
{
public:
	static bool isEmpty(const string& str);
	static bool isEqual(const string& str1,const string& str2);
	static vector<string> split(const string& str,const string& delims);
};
#endif