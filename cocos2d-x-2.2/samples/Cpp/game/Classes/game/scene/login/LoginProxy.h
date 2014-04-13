#ifndef _LOGIN_PROXY_
#define _LOGIN_PROXY_
#include "mvc/patterns/Proxy.h"

class LoginVO;

class LoginProxy:public Proxy
{
	public:
		LoginProxy(const string& name);
		virtual ~LoginProxy();
		bool checkLogin(const LoginVO& vo);
	private:
		
};
#endif