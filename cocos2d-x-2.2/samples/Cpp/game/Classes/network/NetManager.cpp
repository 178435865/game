#include "network/NetManager.h"
#include "network/MessageQueue.h"
#include "network/Thread.h"

NetManager* NetManager::instance=NULL;
NetManager::NetManager()
{
	m_iState=eSocketNormal;
	m_pMessageQueue=new MessageQueue();
	m_pThread=NULL;
}
NetManager::~NetManager()
{
	
}
NetManager* NetManager::getInstance()
{
	if(instance==NULL)
	{
		instance=new NetManager();
	}
	return instance;
}
void NetManager::sendData(const string& key,const string& data)
{
	m_pMessageQueue->pushSendQueue(key,data);
}
void NetManager::receiveData(const string& key,const string& data)
{
	m_pMessageQueue->pushRecieveQueue(key,data);
}
void NetManager::mainloop()
{
	switch (m_iState)
	{
		case eSocketConnecting:
		{
			switch (conn.getConnectState())
			{
				case eSocketConnected:
				{

					break;
				}
				case eSocketConnectFailed:
				{
					break;
				}
				default:
					break;
			}
			
		}
		case eSocketConnected:
		{
			if(conn.isReadable())
			{
				//读取 需要按协议来读取
				runReceive();
			}
			if(conn.isWriteable())
			{
				//写 需要按协议来输出
				runSend();
			}

			break;
		}
	}
}
void NetManager::connect(const string& ip,int port)
{
	m_strIp=ip;
	m_iPort=port;
	conn.Init();
	if(conn.Connect(ip.c_str(),port))
	{
		m_iState=eSocketConnecting;
		if(m_pThread)
		{
			m_pThread=new Thread(this);
			m_pThread->start();
		}
	}
	else
	{
		m_iState=eSocketConnectFailed;
	}
	
}
void NetManager::reconnect()
{
	conn.Init();
	if(conn.Connect(m_strIp.c_str(),m_iPort))
	{
		m_iState=eSocketConnecting;
	}
	else
	{
		m_iState=eSocketConnectFailed;
	}
	
}
void NetManager::runReceive()
{
	char* chars={0};
	int nRet = conn.Recv(chars,20);
	if( nRet == eSocketIoError || nRet == eSocketIoClosed )
	{
		conn.Close();
		m_iState=eSocketIoClosed;
		//网络异常
	}
}
void NetManager::runSend()
{
	char* chars={0};
	int nRet = conn.Send(chars,20);
	if( nRet == eSocketIoError || nRet == eSocketIoClosed )
	{
		conn.Close();
		m_iState=eSocketIoClosed;
		//网络异常
	}
}