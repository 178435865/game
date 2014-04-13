#include "game/scene/login/LoginCommand.h"
#include "game/scene/login/LoginFacade.h"
#include "game/scene/login/LoginVO.h"
#include "game/scene/login/LoginProxy.h"
#include "mvc/patterns/Notification.h"
#include "util/Util.h"

LoginCommand* LoginCommand::instance=NULL;

LoginCommand* LoginCommand::create()
{
	if(instance==NULL)
	{
		instance=new LoginCommand();
	}
	return instance;
}
void LoginCommand::execute(Notification& noti)
{
	const string& name=noti.m_strNotiName;	
	void* data=noti.m_pData;
	if(StringHelper::isEqual(name,LoginFacade::COMMAND_EXIT))
	{
		sendNotification(LoginFacade::NOTIFICATION_CLOSE);
	}
	else if(StringHelper::isEqual(name,LoginFacade::COMMAND_LOGIN))
	{
		LoginVO vo=*((LoginVO*)data);
		IProxy* proxy=getFacade()->getProxy(LoginFacade::PROXY_LOGIN);
		LoginProxy* lp=dynamic_cast<LoginProxy*>(proxy);
		if(lp)
		{
			bool ret=lp->checkLogin(vo);
			if(ret)
			{
				//±¾µØ¼ì²é
				sendNotification(LoginFacade::NOTIFICATION_LOGIN_SUCESS);
			}
			else
			{
				sendNotification(LoginFacade::NOTIFICATION_LOGIN_FAIL);
			}

		}
	}
}