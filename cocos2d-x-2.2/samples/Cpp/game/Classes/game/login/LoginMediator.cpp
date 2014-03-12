#include "game/login/LoginMediator.h"
#include "game/login/LoginFacade.h"
#include "game/login/LoginVO.h"
#include "util/Util.h"
#include "mvc/patterns/Notification.h"

LoginMediator::LoginMediator():Mediator(LoginFacade::MEDIATOR_LOGIN)
{

}
LoginMediator::~LoginMediator()
{
	CCLog("dasd");
}
bool LoginMediator::init()
{
	Mediator::init();
	
	return true;
}
void LoginMediator::handleNotification(Notification& noti)
{
	CCLog("handle notification %s",noti.toString().c_str());
	const string& name=noti.m_strNotiName;
	if(StringHelper::isEqual(name,LoginFacade::NOTIFICATION_CLOSE))
	{
		SceneManager::getInstance()->popScene(this);
	}
}
void LoginMediator::callback(CCObject* obj)
{
	UIButton* button=dynamic_cast<UIButton*>(obj);
	if(button)
	{
		IMediator* mediator=getFacade()->getMediator(LoginFacade::MEDIATOR_LOGIN);
		LoginMediator* lm=dynamic_cast<LoginMediator*>(mediator);
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
void LoginMediator::initButton()
{
	UtilCocostudio::getInstance()->addEventRelease(this,coco_releaseselector(LoginMediator::callback),"close_Button",ui);
	UtilCocostudio::getInstance()->addEventRelease(this,coco_releaseselector(LoginMediator::callback),"login_Button",ui);

}
void LoginMediator::onLoadResource()
{

}
void LoginMediator::onLoadUI()
{
	ui=CCUIHELPER->createWidgetFromJsonFile("DemoLogin.json");
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
void LoginMediator::onEnterScene()
{

}
void LoginMediator::onExitScene()
{

}
void LoginMediator::loadExtraData(void* data)
{

}
void LoginMediator::initInterests()
{
	m_vInterests.push_back(LoginFacade::NOTIFICATION_LOGIN_SUCESS);
	m_vInterests.push_back(LoginFacade::NOTIFICATION_LOGIN_FAIL);
	m_vInterests.push_back(LoginFacade::NOTIFICATION_CLOSE);
}