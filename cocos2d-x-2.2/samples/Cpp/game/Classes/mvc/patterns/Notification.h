#ifndef __I_NOTIFICATION__
#define __I_NOTIFICATION__
#include "gameStd.h"

class Notification
{
	public:
		Notification(const string& name,void* data,int type)
		{
			m_strNotiName=name;
			m_pData=data;
			m_iType=type;
		};
		void* m_pData;
		string m_strNotiName;
		int m_iType;
		string toString(){
			stringstream ss; 
			ss<<"name:"<<m_strNotiName << " type:"<<m_iType;
			return ss.str();
		};
};
#endif