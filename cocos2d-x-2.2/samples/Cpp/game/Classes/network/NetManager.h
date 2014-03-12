#ifndef _NET_MANAGER_
#define _NET_MANAGER_
#include "cocos2d.h"
#include "network/odsocket.h"
#include "network/Runnable.h"

using namespace std;
class MessageQueue;
class Thread;

class NetManager: public Runnable
{
	public:
		static NetManager* getInstance();
		void sendData(const string& key,const string& data);
		void receiveData(const string& key,const string& data);
		void connect(const string& ip,int port);
		void reconnect();
		void closeAll();
		void mainloop();
	private:
		NetManager();
		virtual ~NetManager();
		void runReceive();
		void runSend();

	private:
		ODSocket conn;
		MessageQueue* m_pMessageQueue;
		static NetManager* instance;
		int m_iState;
		Thread* m_pThread;
		string m_strIp;
		int m_iPort;
};

#endif