#include "game/scene/login/LoginFacade.h"
#include "game/scene/login/LoginCommand.h"
#include "game/scene/login/LoginProxy.h"
#include "game/scene/login/LoginMediator.h"
#include "framework/BaseMacros.h"
#include "framework/GameScene.h"


LoginFacade* LoginFacade::instance=NULL;

 const string LoginFacade::COMMAND_LOGIN="LOGIN_FACADE_LOGIN";
 const string LoginFacade::COMMAND_EXIT="LOGIN_FACADE_EXIT";
 const string LoginFacade::PROXY_LOGIN="PROXY_LOGIN";
 const string LoginFacade::MEDIATOR_LOGIN="MEDIATOR_LOGIN";

const string LoginFacade::NOTIFICATION_LOGIN_SUCESS="NOTIFICATION_LOGIN_SUCESS";
const string LoginFacade::NOTIFICATION_LOGIN_FAIL="NOTIFICATION_LOGIN_FAIL";
const string LoginFacade::NOTIFICATION_CLOSE="NOTIFICATION_CLOSE";


void LoginFacade::initModel()
{
	Facade::initModel();
	IProxy* proxy=new LoginProxy(PROXY_LOGIN);
	registerProxy(proxy);
}
void LoginFacade::initController()
{
	Facade::initController();
	registerCommand(COMMAND_LOGIN,LoginCommand::create());
	registerCommand(COMMAND_EXIT,LoginCommand::create());
}
LoginFacade* LoginFacade::getInstance()
{
	if(instance==NULL)
	{
		instance=new LoginFacade();
	}
	return instance;
}
LoginFacade::LoginFacade():Facade()
{
	initFacade();
}
LoginFacade::~LoginFacade()
{
	
}
