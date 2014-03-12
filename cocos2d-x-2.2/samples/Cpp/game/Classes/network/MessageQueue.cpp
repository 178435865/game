#include "network/MessageQueue.h"
#include "network/Message.h"

MessageQueue::MessageQueue()
{

}

MessageQueue::~MessageQueue()
{

}

void MessageQueue::pushSendQueue(const string& key,const string& data)
{
	CMyLock lock(sendLock);
	Message mes(key,data);
	sendQueue.push_back(mes);
}
void MessageQueue::pushRecieveQueue(const string& key,const string& data)
{
	CMyLock lock(recievelock);
	Message mes(key,data);
	recieveQueue.push_back(mes);
}
Message MessageQueue::popSendQueue()
{
	CMyLock lock(sendLock);
	Message mes=sendQueue.back();
	sendQueue.pop_back();
	return mes;
}
Message MessageQueue::popRecieveQueue()
{
	CMyLock lock(recievelock);
	Message mes=recieveQueue.back();
	recieveQueue.pop_back();
	return mes;

}
bool MessageQueue::isEmptySendQueue()
{
	return sendQueue.size()>0;
}
bool MessageQueue::isEmptyRecieveQueue()
{
	return recieveQueue.size()>0;
}