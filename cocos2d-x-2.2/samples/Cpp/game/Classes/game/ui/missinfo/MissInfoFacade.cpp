#include "game/ui/missinfo/MissInfoFacade.h"
//#include "game/ui/missinfo/MissInfoCommand.h"
//#include "game/ui/missinfo/MissInfoProxy.h"
#include "game/ui/missinfo/MissInfoMediator.h"
#include "framework/BaseMacros.h"
#include "framework/GameScene.h"


MissInfoFacade* MissInfoFacade::instance=NULL;

// const string MissInfoFacade::COMMAND_LOGIN="LOGIN_FACADE_LOGIN";
 //const string MissInfoFacade::COMMAND_EXIT="LOGIN_FACADE_EXIT";
 //const string MissInfoFacade::PROXY_LOGIN="PROXY_LOGIN";
 const string MissInfoFacade::MEDIATOR_MISS_INFO="MEDIATOR_MISS_INFO";

//const string MissInfoFacade::NOTIFICATION_LOGIN_SUCESS="NOTIFICATION_LOGIN_SUCESS";
//const string MissInfoFacade::NOTIFICATION_SWITCH_SRH_SUCCESS="NOTIFICATION_SWITCH_SRH_SUCCESS";
//const string MissInfoFacade::NOTIFICATION_LOGIN_FAIL="NOTIFICATION_LOGIN_FAIL";
//const string MissInfoFacade::NOTIFICATION_CLOSE="NOTIFICATION_CLOSE";


void MissInfoFacade::initModel()
{
	
	Facade::initModel();
	/**
	IProxy* proxy=new MissInfoProxy(PROXY_LOGIN);
	registerProxy(proxy);
	*/

}
void MissInfoFacade::initController()
{
	Facade::initController();

}
MissInfoFacade* MissInfoFacade::getInstance()
{
	if(instance==NULL)
	{
		instance=new MissInfoFacade();
	}
	return instance;
}
MissInfoFacade::MissInfoFacade():Facade()
{
	initFacade();
}
MissInfoFacade::~MissInfoFacade()
{
	
}
