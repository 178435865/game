#include "game/login/LoginProxy.h"
#include "game/login/LoginVO.h"
#include "util/Util.h"


LoginProxy::LoginProxy(const string& name):Proxy(name)
{

}
LoginProxy::~LoginProxy()
{
	
}
bool LoginProxy::checkLogin(const LoginVO& vo)
{
	const string name=vo.getUserName();
	const string password=vo.getUserPassword();
	if(!StringHelper::isEmpty(name)&&!StringHelper::isEmpty(password))
	{
		return true;
	}
	return false;
}
