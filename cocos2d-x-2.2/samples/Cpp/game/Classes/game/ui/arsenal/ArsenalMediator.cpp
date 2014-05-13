#include "game/ui/arsenal/ArsenalMediator.h"
#include "game/ui/arsenal/ArsenalFacade.h"
//#include "game/ui/arsenal/ArsenalVO.h"
#include "util/Util.h"
#include "mvc/patterns/Notification.h"

ArsenalMediator::ArsenalMediator():Mediator(ArsenalFacade::MEDIATOR_MISS_INFO)
{

}
ArsenalMediator::~ArsenalMediator()
{
	CCLog("dasd");
}
bool ArsenalMediator::init()
{
	Mediator::init();
	
	return true;
}
void ArsenalMediator::handleNotification(Notification& noti)
{
	CCLog("handle notification %s",noti.toString().c_str());
	const string& name=noti.m_strNotiName;
	/**
	if(StringHelper::isEqual(name,ArsenalFacade::NOTIFICATION_CLOSE))
	{
		MgrScene::getInstance()->popScene(this);
	}
	else  
	if(StringHelper::isEqual(name,ArsenalFacade::NOTIFICATION_SWITCH_SRH_SUCCESS))
	{
		//MgrScene::getInstance()->popScene(this);
		MgrScene::getInstance()->runWidthScene("LoginMediator");
	}*/
}
void ArsenalMediator::callback(CCObject *obj, TouchEventType type)
{
	
}
void ArsenalMediator::initButton()
{
	//UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(ArsenalMediator::callback),"Button_102_0_0",ui);
	//ui->getChildByName("Button_134");
	//UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(ArsenalMediator::callback),"Button_102_0",ui);
	//UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(ArsenalMediator::callback),"login_Button",ui);

}
void ArsenalMediator::onLoadResource()
{

}
void ArsenalMediator::onLoadUI()
{

	ui=UtilCocostudio::getInstance()->createWidgetFromJsonFile("outmenu/arsenal.json");
	UILayer* layer=UILayer::create();
	layer->addWidget(ui);
	CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	float x=UtilView::getViewDistanceX()+winSize.width/2-ui->getContentSize().width/2;
	float y=(winSize.height-ui->getContentSize().height)/2;
	layer->setPosition(ccp(x,y));
	layer->setAnchorPoint(CCPointZero);
	layer->setZOrder(0);
	this->addChild(layer);

	UIWidget* commToolbarUi=UtilCocostudio::getInstance()->createWidgetFromJsonFile("outmenu/head_menu.json");
	UILayer* commToolbarLayer=UILayer::create();
	commToolbarLayer->addWidget(commToolbarUi);
	float commToolbarX=UtilView::getViewDistanceX()+winSize.width/2-ui->getContentSize().width/2;
	float commToolbarY=(winSize.height-ui->getContentSize().height)/2;
	commToolbarLayer->setPosition(ccp(commToolbarX,commToolbarY));
	commToolbarLayer->setAnchorPoint(CCPointZero);
	commToolbarLayer->setZOrder(1);
	this->addChild(commToolbarLayer);

	UIWidget* downmenuToolbarUi=UtilCocostudio::getInstance()->createWidgetFromJsonFile("outmenu/downmenu.json");
	UILayer* downmenuToolbarLayer=UILayer::create();
	downmenuToolbarLayer->addWidget(downmenuToolbarUi);
	float downmenuToolbarX=UtilView::getViewDistanceX()+winSize.width/2-ui->getContentSize().width/2;
	float downmenuToolbarY=(winSize.height-ui->getContentSize().height)/2;
	downmenuToolbarLayer->setPosition(ccp(downmenuToolbarX,downmenuToolbarY));
	downmenuToolbarLayer->setAnchorPoint(CCPointZero);
	downmenuToolbarLayer->setZOrder(2);
	this->addChild(downmenuToolbarLayer);

	initButton();





	/** 
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"ui_button_select.png",  
		"ui_button_select.png",  
		this,  
		menu_selector(ArsenalMediator::callback));  
	pCloseItem->setScale(1.2);
	CCMenu* pMenu = CCMenu::create(pCloseItem,NULL); 
	pMenu->setPosition(ccp(500,450));
	addChild(pMenu);
	CCLabelTTF* label=CCLabelTTF::create();
	label->setString("shanggu");
	label->setPosition(ccp(500,450));
	label->setFontSize(40);
	label->setColor(ccBLACK);
	addChild(label);
	 */

}
void ArsenalMediator::onEnterScene()
{

}
void ArsenalMediator::onExitScene()
{

}
void ArsenalMediator::loadExtraData(void* data)
{

}
void ArsenalMediator::initInterests()
{
//	m_vInterests.push_back(ArsenalFacade::NOTIFICATION_LOGIN_SUCESS);
//	m_vInterests.push_back(ArsenalFacade::NOTIFICATION_SWITCH_SRH_SUCCESS);
//	m_vInterests.push_back(ArsenalFacade::NOTIFICATION_LOGIN_FAIL);
//	m_vInterests.push_back(ArsenalFacade::NOTIFICATION_CLOSE);
}