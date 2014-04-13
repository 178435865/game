#ifndef __UTILJSON__
#define __UTILJSON__

#include "cocos2d.h"
//#include "CocoStudio\Json\rapidjson/document.h"
//using namespace rapidjson;
#include "json/json.h"
using namespace Json;
using namespace cocos2d;
using namespace std;

class UtilJson
{
public :
	static int getInt(Value& v,const char* key);
	static const char* getStr(Value& v,const char* key);
	static Value getArr(Value& v,const char* key);
	static double getLong(Value& v,const char* key);
	static const bool getBool(Value& v,const char* key);
	static const CCString* jsonToStr(Value v);


	static Value getJsonFromFile(const char* fileName);
	static Value getJsonFromFile(const char* fileName,const char* directory);
	static Value getJsonByString(string data);
	static Value getJsonByChar(const char* chars);

	static bool isEmpty(Value& v);
};

#endif