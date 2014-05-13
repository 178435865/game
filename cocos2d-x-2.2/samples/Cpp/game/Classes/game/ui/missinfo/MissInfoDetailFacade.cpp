#include "game/ui/missinfo/MissInfoDetailFacade.h"
//#include "game/ui/missinfo/MissInfoDetailCommand.h"
//#include "game/ui/missinfo/MissInfoDetailProxy.h"
#include "game/ui/missinfo/MissInfoDetailMediator.h"
#include "framework/BaseMacros.h"
#include "framework/GameScene.h"


MissInfoDetailFacade* MissInfoDetailFacade::instance=NULL;
const string MissInfoDetailFacade::MEDIATOR_MISS_INFO_DETAIL="MEDIATOR_MISS_INFO_DETAIL";

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
