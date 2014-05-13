#include "game/ui/arsenal/ArsenalFacade.h"
//#include "game/ui/arsenal/ArsenalCommand.h"
//#include "game/ui/arsenal/ArsenalProxy.h"
#include "game/ui/arsenal/ArsenalMediator.h"
#include "framework/BaseMacros.h"
#include "framework/GameScene.h"


ArsenalFacade* ArsenalFacade::instance=NULL;

// const string ArsenalFacade::COMMAND_LOGIN="LOGIN_FACADE_LOGIN";
 //const string ArsenalFacade::COMMAND_EXIT="LOGIN_FACADE_EXIT";
 //const string ArsenalFacade::PROXY_LOGIN="PROXY_LOGIN";
 const string ArsenalFacade::MEDIATOR_MISS_INFO="MEDIATOR_MISS_INFO";

//const string ArsenalFacade::NOTIFICATION_LOGIN_SUCESS="NOTIFICATION_LOGIN_SUCESS";
//const string ArsenalFacade::NOTIFICATION_SWITCH_SRH_SUCCESS="NOTIFICATION_SWITCH_SRH_SUCCESS";
//const string ArsenalFacade::NOTIFICATION_LOGIN_FAIL="NOTIFICATION_LOGIN_FAIL";
//const string ArsenalFacade::NOTIFICATION_CLOSE="NOTIFICATION_CLOSE";


void ArsenalFacade::initModel()
{
	
	Facade::initModel();
	/**
	IProxy* proxy=new ArsenalProxy(PROXY_LOGIN);
	registerProxy(proxy);
	*/

}
void ArsenalFacade::initController()
{
	Facade::initController();

}
ArsenalFacade* ArsenalFacade::getInstance()
{
	if(instance==NULL)
	{
		instance=new ArsenalFacade();
	}
	return instance;
}
ArsenalFacade::ArsenalFacade():Facade()
{
	initFacade();
}
ArsenalFacade::~ArsenalFacade()
{
	
}
