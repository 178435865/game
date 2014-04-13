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

vector<string> StringHelper::split(const string& str,const string& delims)
{
	vector<string> ret;
	int start=0,pos=0;
	int length=str.length();
	do 
	{
		pos=str.find(delims,start);
		if(pos<length)
		{
			ret.push_back(str.substr(start,pos-start));
			start=pos+1;
		}
		else if(pos==string::npos)
		{
			ret.push_back(str.substr(start));
		}
	} while (pos!=string::npos);
	return ret;
}