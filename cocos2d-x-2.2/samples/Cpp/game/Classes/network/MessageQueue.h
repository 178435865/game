#ifndef _MESSAGE_QUEUE_
#define _MESSAGE_QUEUE_
#include "cocos2d.h"
#include "lock/Lock.h"
using namespace std;
class Message;

class MessageQueue
{
	public:
		MessageQueue();
		virtual ~MessageQueue();
		void pushSendQueue(const string& key,const string& data);
		void pushRecieveQueue(const string& key,const string& data);
		Message popSendQueue();
		Message popRecieveQueue();
		bool isEmptySendQueue();
		bool isEmptyRecieveQueue();
	private:
		list<Message> sendQueue;
		list<Message> recieveQueue;
		CMutex sendLock;
		CMutex recievelock;
};

#endif