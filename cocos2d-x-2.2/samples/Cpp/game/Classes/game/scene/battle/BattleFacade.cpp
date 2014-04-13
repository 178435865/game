#include "game/scene/battle/BattleFacade.h"

const string BattleFacade::NOTIFICATION_ROCKER_TOUCH_MOVE="NOTIFICATION_ROCKER_TOUCH_MOVE";
const string BattleFacade::NOTIFICATION_ROCKER_TOUCH_BEGIN="NOTIFICATION_ROCKER_TOUCH_BEGIN";
const string BattleFacade::NOTIFICATION_ROCKER_TOUCH_END="NOTIFICATION_ROCKER_TOUCH_END";


void BattleFacade::initModel()
{
	Facade::initModel();
}
void BattleFacade::initController()
{
	Facade::initController();
}
BattleFacade* BattleFacade::getInstance()
{
	static BattleFacade* instance=NULL;
	if(instance==NULL)
	{
		instance=new BattleFacade();
	}
	return instance;
}
BattleFacade::BattleFacade():Facade()
{
	initFacade();
}
BattleFacade::~BattleFacade()
{
	
}
