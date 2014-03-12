#ifndef _PROXY_
#define _PROXY_
#include "mvc/interface/IProxy.h"
class Proxy:public IProxy
{
public:
	const string& getName()
	{
		return m_strName;
	};
protected:
	Proxy(const string& name)
	{
		m_strName=name;
	};
	virtual ~Proxy(){};
	string m_strName;

};
#endif