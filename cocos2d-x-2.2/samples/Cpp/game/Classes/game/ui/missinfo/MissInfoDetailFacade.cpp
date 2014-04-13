#include "game/ui/missinfo/MissInfoDetailFacade.h"
//#include "game/ui/missinfo/MissInfoDetailCommand.h"
//#include "game/ui/missinfo/MissInfoDetailProxy.h"
#include "game/ui/missinfo/MissInfoDetailMediator.h"
#include "framework/BaseMacros.h"
#include "framework/GameScene.h"


MissInfoDetailFacade* MissInfoDetailFacade::instance=NULL;

// const string MissInfoDetailFacade::COMMAND_LOGIN="LOGIN_FACADE_LOGIN";
// const string MissInfoDetailFacade::COMMAND_SWITCH_SEARCHPAGE="COMMAND_SWITCH_SEARCHPAGE";
 //const string MissInfoDetailFacade::COMMAND_EXIT="LOGIN_FACADE_EXIT";
 //const string MissInfoDetailFacade::PROXY_LOGIN="PROXY_LOGIN";
 const string MissInfoDetailFacade::MEDIATOR_MISS_INFO_DETAIL="MEDIATOR_MISS_INFO_DETAIL";

//const string MissInfoDetailFacade::NOTIFICATION_LOGIN_SUCESS="NOTIFICATION_LOGIN_SUCESS";
//const string MissInfoDetailFacade::NOTIFICATION_SWITCH_SRH_SUCCESS="NOTIFICATION_SWITCH_SRH_SUCCESS";
//const string MissInfoDetailFacade::NOTIFICATION_LOGIN_FAIL="NOTIFICATION_LOGIN_FAIL";
//const string MissInfoDetailFacade::NOTIFICATION_CLOSE="NOTIFICATION_CLOSE";


void MissInfoDetailFacade::initModel()
{
	
	Facade::initModel();
	/**
	IProxy* proxy=new MissInfoDetailProxy(PROXY_LOGIN);
	registerProxy(proxy);
	*/

}
void MissInfoDetailFacade::initController()
{
	Facade::initController();
	//registerCommand(COMMAND_SWITCH_SEARCHPAGE,MissInfoDetailCommand::create());
	//registerCommand(COMMAND_EXIT,MissInfoDetailCommand::create());
}
MissInfoDetailFacade* MissInfoDetailFacade::getInstance()
{
	if(instance==NULL)
	{
		instance=new MissInfoDetailFacade();
	}
	return instance;
}
MissInfoDetailFacade::MissInfoDetailFacade():Facade()
{
	initFacade();
}
MissInfoDetailFacade::~MissInfoDetailFacade()
{
	
}
