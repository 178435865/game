#include "game/ui/equipment/Equipment.h"
#include "game/scene/login/LoginFacade.h"
#include "game/scene/login/LoginVO.h"
#include "util/Util.h"
#include "mvc/patterns/Notification.h"

Equipment::Equipment():Mediator(LoginFacade::MEDIATOR_LOGIN)
{

}
Equipment::~Equipment()
{
	CCLog("dasd");
}
bool Equipment::init()
{
	Mediator::init();
	
	return true;
}
void Equipment::handleNotification(Notification& noti)
{
	CCLog("handle notification %s",noti.toString().c_str());
	const string& name=noti.m_strNotiName;
	if(StringHelper::isEqual(name,LoginFacade::NOTIFICATION_CLOSE))
	{
		MgrScene::getInstance()->popScene(this);
	}
}
void Equipment::callback(CCObject *obj, TouchEventType type)
{
	UIButton* button=dynamic_cast<UIButton*>(obj);
	if(button)
	{
		IMediator* mediator=getFacade()->getMediator(LoginFacade::MEDIATOR_LOGIN);
		Equipment* lm=dynamic_cast<Equipment*>(mediator);
		if(lm)
		{
			const string& name=button->getName();
			if(StringHelper::isEqual(name,"close_Button"))
			{
				CCLog("close");
				lm->sendCommand(LoginFacade::COMMAND_EXIT);
			}
			else if(StringHelper::isEqual(name,"login_Button"))
			{
				CCLog("login");
				LoginVO vo;
				vo.setUserName("ys");
				vo.setUserPassword("ys");
				lm->sendCommand(LoginFacade::COMMAND_LOGIN,(void*)&vo);
			}
		}
		
	}
	
	
}
void Equipment::initButton()
{
	UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(Equipment::callback),"ui_quest_button",ui);
	//UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(Equipment::callback),"login_Button",ui);

}
void Equipment::onLoadResource()
{

}
void Equipment::onLoadUI()
{

	ui=UtilCocostudio::getInstance()->createWidgetFromJsonFile("outmenu/index.json");
	UILayer* layer=UILayer::create();
	layer->addWidget(ui);
	CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	float x=UtilView::getViewDistanceX()+winSize.width/2-ui->getContentSize().width/2;
	float y=(winSize.height-ui->getContentSize().height)/2;
	layer->setPosition(ccp(x,y));
	layer->setAnchorPoint(CCPointZero);
	this->addChild(layer);

	initButton();

}
void Equipment::onEnterScene()
{

}
void Equipment::onExitScene()
{

}
void Equipment::loadExtraData(void* data)
{

}
void Equipment::initInterests()
{
	m_vInterests.push_back(LoginFacade::NOTIFICATION_LOGIN_SUCESS);
	m_vInterests.push_back(LoginFacade::NOTIFICATION_LOGIN_FAIL);
	m_vInterests.push_back(LoginFacade::NOTIFICATION_CLOSE);
}