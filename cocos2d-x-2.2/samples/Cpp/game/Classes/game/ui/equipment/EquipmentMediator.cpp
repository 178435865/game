#include "game/ui/equipment/EquipmentMediator.h"
#include "game/ui/equipment/EquipmentFacade.h"
#include "game/ui/equipment/EquipmentVO.h"
#include "util/Util.h"
#include "mvc/patterns/Notification.h"

EquipmentMediator::EquipmentMediator():Mediator(EquipmentFacade::MEDIATOR_EQUIPMENT)
{

}
EquipmentMediator::~EquipmentMediator()
{
	CCLog("dasd");
}
bool EquipmentMediator::init()
{
	Mediator::init();
	
	return true;
}
void EquipmentMediator::handleNotification(Notification& noti)
{
	CCLog("handle notification %s",noti.toString().c_str());
	const string& name=noti.m_strNotiName;
	/**
	if(StringHelper::isEqual(name,EquipmentFacade::NOTIFICATION_CLOSE))
	{
		MgrScene::getInstance()->popScene(this);
	}
	else  */
	if(StringHelper::isEqual(name,EquipmentFacade::NOTIFICATION_SWITCH_SRH_SUCCESS))
	{
		//MgrScene::getInstance()->popScene(this);
		MgrScene::getInstance()->runWidthScene("MissInfoMediator");
	}
	else if(StringHelper::isEqual(name,EquipmentFacade::NOTIFICATION_SWITCH_ARL_SUCCESS))
	{
		MgrScene::getInstance()->runWidthScene("ArsenalMediator");
	}
}
void EquipmentMediator::callback(CCObject *obj, TouchEventType type)
{
	UIButton* button=dynamic_cast<UIButton*>(obj);
	if(button)
	{
		IMediator* mediator=getFacade()->getMediator(EquipmentFacade::MEDIATOR_EQUIPMENT);
		EquipmentMediator* lm=dynamic_cast<EquipmentMediator*>(mediator);
		if(lm)
		{
			const string& name=button->getName();
			if(StringHelper::isEqual(name,"Button_65"))
			{
				lm->sendCommand(EquipmentFacade::COMMAND_SWITCH_SEARCHPAGE,NULL);
			}
			else if(StringHelper::isEqual(name,"Button_65_0_1_Copy0"))
			{
				lm->sendCommand(EquipmentFacade::COMMAND_SWITCH_ARSENALPAGE,NULL);
			}
		}
		
	}
	
	
}
void EquipmentMediator::initButton()
{
	UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(EquipmentMediator::callback),"Button_65",ui);
	//UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(EquipmentMediator::callback),"login_Button",ui);
	UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(EquipmentMediator::callback),"Button_65_0_1_Copy0",downmenuToolbarUi);
	UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(EquipmentMediator::callback),"Button_65",downmenuToolbarUi);

}
void EquipmentMediator::onLoadResource()
{

}
void EquipmentMediator::onLoadUI()
{

	ui=UtilCocostudio::getInstance()->createWidgetFromJsonFile("outmenu/index.json");
	UILayer* layer=UILayer::create();
	layer->addWidget(ui);
	CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	float x=UtilView::getViewDistanceX()+winSize.width/2-ui->getContentSize().width/2;
	float y=(winSize.height-ui->getContentSize().height)/2;
	layer->setPosition(ccp(x,y));
	layer->setAnchorPoint(CCPointZero);
	layer->setZOrder(0);
	this->addChild(layer);

	commToolbarUi=UtilCocostudio::getInstance()->createWidgetFromJsonFile("outmenu/head_menu.json");
	UILayer* commToolbarLayer=UILayer::create();
	commToolbarLayer->addWidget(commToolbarUi);
	float commToolbarX=UtilView::getViewDistanceX()+winSize.width/2-commToolbarUi->getContentSize().width/2;
	float commToolbarY=(winSize.height-commToolbarUi->getContentSize().height)/2;
	commToolbarLayer->setPosition(ccp(commToolbarX,commToolbarY));
	commToolbarLayer->setAnchorPoint(CCPointZero);
	commToolbarLayer->setZOrder(1);
	this->addChild(commToolbarLayer);

	downmenuToolbarUi=UtilCocostudio::getInstance()->createWidgetFromJsonFile("outmenu/downmenu.json");
	UILayer* downmenuToolbarLayer=UILayer::create();
	downmenuToolbarLayer->addWidget(downmenuToolbarUi);
	float downmenuToolbarX=UtilView::getViewDistanceX()+winSize.width/2-downmenuToolbarUi->getContentSize().width/2;
	float downmenuToolbarY=(winSize.height-downmenuToolbarUi->getContentSize().height)/2;
	downmenuToolbarLayer->setPosition(ccp(downmenuToolbarX,downmenuToolbarY));
	downmenuToolbarLayer->setAnchorPoint(CCPointZero);
	downmenuToolbarLayer->setZOrder(2);
	this->addChild(downmenuToolbarLayer);

	initButton();

}
void EquipmentMediator::onEnterScene()
{

}
void EquipmentMediator::onExitScene()
{

}
void EquipmentMediator::loadExtraData(void* data)
{

}
void EquipmentMediator::initInterests()
{
//	m_vInterests.push_back(EquipmentFacade::NOTIFICATION_LOGIN_SUCESS);
	m_vInterests.push_back(EquipmentFacade::NOTIFICATION_SWITCH_SRH_SUCCESS);
	m_vInterests.push_back(EquipmentFacade::NOTIFICATION_SWITCH_ARL_SUCCESS);
//	m_vInterests.push_back(EquipmentFacade::NOTIFICATION_LOGIN_FAIL);
//	m_vInterests.push_back(EquipmentFacade::NOTIFICATION_CLOSE);
}