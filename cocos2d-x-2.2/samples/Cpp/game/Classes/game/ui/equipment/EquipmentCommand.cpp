#include "game/ui/equipment/EquipmentCommand.h"
#include "game/ui/equipment/EquipmentFacade.h"
#include "game/ui/equipment/EquipmentVO.h"
#include "game/ui/equipment/EquipmentProxy.h"
#include "mvc/patterns/Notification.h"
#include "util/Util.h"

EquipmentCommand* EquipmentCommand::instance=NULL;

EquipmentCommand* EquipmentCommand::create()
{
	if(instance==NULL)
	{
		instance=new EquipmentCommand();
	}
	return instance;
}
void EquipmentCommand::execute(Notification& noti)
{
	const string& name=noti.m_strNotiName;	
	void* data=noti.m_pData;
	if(StringHelper::isEqual(name,EquipmentFacade::COMMAND_SWITCH_SEARCHPAGE))
	{
		sendNotification(EquipmentFacade::NOTIFICATION_SWITCH_SRH_SUCCESS);
	}
	else if(StringHelper::isEqual(name,EquipmentFacade::COMMAND_SWITCH_ARSENALPAGE))
	{
		sendNotification(EquipmentFacade::NOTIFICATION_SWITCH_ARL_SUCCESS);
	}
	/**
	else if(StringHelper::isEqual(name,EquipmentFacade::COMMAND_LOGIN))
	{
		EquipmentVO vo=*((EquipmentVO*)data);
		IProxy* proxy=getFacade()->getProxy(EquipmentFacade::PROXY_LOGIN);
		EquipmentProxy* lp=dynamic_cast<EquipmentProxy*>(proxy);
		if(lp)
		{
			bool ret=lp->checkEquipment(vo);
			if(ret)
			{
				//±¾µØ¼ì²é
				sendNotification(EquipmentFacade::NOTIFICATION_LOGIN_SUCESS);
			}
			else
			{
				sendNotification(EquipmentFacade::NOTIFICATION_LOGIN_FAIL);
			}

		}
	}
	*/
}