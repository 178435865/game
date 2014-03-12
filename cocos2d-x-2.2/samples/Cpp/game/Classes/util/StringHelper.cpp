#include "util/StringHelper.h"


bool StringHelper::isEmpty(const string& str)
{
	if(str.compare("")==0)
	{
		return true;
	}
	return false;
}
bool StringHelper::isEqual(const string& str1,const string& str2)
{
	if(str1.compare(str2)==0)
	{
		return true;
	}
	return false;
}