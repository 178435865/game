#ifndef _MESSAGE_
#define _MESSAGE_
#include "cocos2d.h"
using namespace std;

class Message
{
	public:
		Message(const string& key,const string& data)
		{
			m_strData=data;
			m_strKey=key;
		};
		string m_strKey;
		string m_strData;
};
#endif // !_MESSAGE_QUEUE_
