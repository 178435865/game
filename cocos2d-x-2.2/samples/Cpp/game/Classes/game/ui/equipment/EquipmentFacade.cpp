#include "game/ui/equipment/EquipmentFacade.h"
#include "game/ui/equipment/EquipmentCommand.h"
#include "game/ui/equipment/EquipmentProxy.h"
#include "game/ui/equipment/EquipmentMediator.h"
#include "framework/BaseMacros.h"
#include "framework/GameScene.h"


EquipmentFacade* EquipmentFacade::instance=NULL;

// const string EquipmentFacade::COMMAND_LOGIN="LOGIN_FACADE_LOGIN";
 const string EquipmentFacade::COMMAND_SWITCH_SEARCHPAGE="COMMAND_SWITCH_SEARCHPAGE";
 const string EquipmentFacade::COMMAND_SWITCH_ARSENALPAGE="COMMAND_SWITCH_ARSENALPAGE";
 //const string EquipmentFacade::COMMAND_EXIT="LOGIN_FACADE_EXIT";
 //const string EquipmentFacade::PROXY_LOGIN="PROXY_LOGIN";
 const string EquipmentFacade::MEDIATOR_EQUIPMENT="MEDIATOR_EQUIPMENT";

//const string EquipmentFacade::NOTIFICATION_LOGIN_SUCESS="NOTIFICATION_LOGIN_SUCESS";
const string EquipmentFacade::NOTIFICATION_SWITCH_SRH_SUCCESS="NOTIFICATION_SWITCH_SRH_SUCCESS";
const string EquipmentFacade::NOTIFICATION_SWITCH_ARL_SUCCESS="NOTIFICATION_SWITCH_ARL_SUCCESS";
//const string EquipmentFacade::NOTIFICATION_LOGIN_FAIL="NOTIFICATION_LOGIN_FAIL";
//const string EquipmentFacade::NOTIFICATION_CLOSE="NOTIFICATION_CLOSE";


void EquipmentFacade::initModel()
{
	
	Facade::initModel();
	/**
	IProxy* proxy=new EquipmentProxy(PROXY_LOGIN);
	registerProxy(proxy);
	*/

}
void EquipmentFacade::initController()
{
	Facade::initController();
	registerCommand(COMMAND_SWITCH_SEARCHPAGE,EquipmentCommand::create());
	registerCommand(COMMAND_SWITCH_ARSENALPAGE,EquipmentCommand::create());
	//registerCommand(COMMAND_EXIT,EquipmentCommand::create());
}
EquipmentFacade* EquipmentFacade::getInstance()
{
	if(instance==NULL)
	{
		instance=new EquipmentFacade();
	}
	return instance;
}
EquipmentFacade::EquipmentFacade():Facade()
{
	initFacade();
}
EquipmentFacade::~EquipmentFacade()
{
	
}
