#include "UtilJson.h"

int UtilJson::getInt(Value& v,const char* key)
{
	if(v.isMember(key))
	{
		return v[key].asInt();
	}
	return -1;
}
double UtilJson::getLong(Value& v,const char* key)
{
	if(v.isMember(key))
	{
		return v[key].asDouble();
	}
	return -1;
}
const char* UtilJson::getStr(Value& v,const char* key)
{
	if(v.isMember(key))
	{
		const char* ch=(v[key]).asCString();
		return ch;
	}
	return "";
}
const CCString* UtilJson::jsonToStr(Value v)
{
	FastWriter fw;
	std::string data=fw.write(v);
	const CCString* str=CCString::create(data);
	//delete[] data;
	return str;
	//return data.c_str();
}
Value UtilJson::getArr(Value& v,const char* key)
{
	if(v.isMember(key))
	{
		return v[key];
	}
	return 0;
}
const bool UtilJson::getBool(Value& v,const char* key)
{
	bool ret(false);
	if(v.isMember(key))
	{
		ret=(v[key]).asBool();
	}
	return ret;
}
Value UtilJson::getJsonFromFile(const char* fileName){  
	Reader reader;  

	std::string strPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName);
	CCLog("strPath %s ",strPath.c_str());
	unsigned long size = 0;
	unsigned char *data = NULL;
	data = CCFileUtils::sharedFileUtils()->getFileData(strPath.c_str(),"r",&size);

	char* fileContent=(char*)data;

	std::string jsonfile;
	jsonfile.assign(fileContent, size);  
	
	CCAssert( size > 0, "file is open fail!");  
	Value root;  
	if  (!reader.parse(jsonfile, root, false )) {  
		CCAssert(false, "Reader Parse error!");  
	}  

	delete[] fileContent;
	fileContent=NULL;
	/*delete []data;
	data = NULL;*/

	return root;  
} 
Value UtilJson::getJsonFromFile(const char* fileName,const char* directory)
{  
	Reader reader;  

	std::string strPath = CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(fileName,directory);
	unsigned long size = 0;
	unsigned char *data = NULL;
	data = CCFileUtils::sharedFileUtils()->getFileData(strPath.c_str(),"r",&size);

	char* fileContent=(char*)data;

	std::string jsonfile ;  
	jsonfile.assign(fileContent, size);  


	CCAssert( size > 0, "file is open fail!");  
	Value root;  
	if  (!reader.parse(jsonfile, root, false )) {  
		CCAssert(false, "Reader Parse error!");  
	}  

	//delete[] fileContent;
	//fileContent=NULL;
	delete []data;
	data = NULL;

	return root;  
} 
Value UtilJson::getJsonByString(string data)
{
	Reader reader;  
	Value root;  
	if  (!reader.parse(data, root, false )) {  
		CCAssert(false, "Reader Parse error!");  
	}  

	return root;  
}
Value UtilJson::getJsonByChar(const char* chars)
{
	string data;
	data.append(chars);

	Reader reader;  
	Value root;  
	if  (!reader.parse(data, root, false )) {  
		CCAssert(false, "Reader Parse error!");  
	}  

	return root;  
}
bool UtilJson::isEmpty(Value& v)
{
	if(v!=0&&!v.isNull()&&!v.empty())
	{
		return false;
	}
	return true;
}