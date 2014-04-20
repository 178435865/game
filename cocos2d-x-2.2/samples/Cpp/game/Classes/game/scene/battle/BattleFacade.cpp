#include "game/scene/battle/BattleFacade.h"

const string BattleFacade::NOTIFICATION_ROCKER_TOUCH_LEFT_MOVE="NOTIFICATION_ROCKER_TOUCH_LEFT_MOVE";
const string BattleFacade::NOTIFICATION_ROCKER_TOUCH_LEFT_BEGIN="NOTIFICATION_ROCKER_TOUCH_LEFT_BEGIN";
const string BattleFacade::NOTIFICATION_ROCKER_TOUCH_LEFT_END="NOTIFICATION_ROCKER_TOUCH_LEFT_END";
const string BattleFacade::NOTIFICATION_ROCKER_TOUCH_RIGHT_MOVE="NOTIFICATION_ROCKER_TOUCH_RIGHT_MOVE";
const string BattleFacade::NOTIFICATION_ROCKER_TOUCH_RIGHT_BEGIN="NOTIFICATION_ROCKER_TOUCH_RIGHT_BEGIN";
const string BattleFacade::NOTIFICATION_ROCKER_TOUCH_RIGHT_END="NOTIFICATION_ROCKER_TOUCH_RIGHT_END";


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
