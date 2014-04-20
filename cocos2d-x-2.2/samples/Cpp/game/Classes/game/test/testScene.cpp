#include "game/test/testScene.h"
#include "game/action/GameArmature.h"
#include "game/obj/Obj.h"
#include "game/obj/Role.h"
#include "game/obj/IObjectState.h"
#include "game/gamewidget/Rocker.h"
#include "game/scene/battle/BattleFacade.h"

testScene::testScene():Mediator("testScene")
{

}
void testScene::onLoadResource()
{

}
void testScene::onLoadUI()
{
	CCLog("loadUi");
	CCSprite* sprite=CCSprite::create("close2.png");
	addChild(sprite);
	sprite->setPosition(ccp(600,400));

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(  
		"close1.png",  
		"close2.png",  
		this,  
		menu_selector(testScene::menuCloseCallback));  

	pMenu = CCMenu::create(pCloseItem,NULL); 
	pMenu->setPosition(ccp(100,400));
	addChild(pMenu);
	CCLabelTTF* label=CCLabelTTF::create();
	label->setString("tesst Scene main");
	label->setPosition(ccp(500,500));
	label->setFontSize(80);
	addChild(label);

	CCSize size=CCDirector::sharedDirector()->getWinSize();
	m_pObj=Role::create(2);
	m_pObj->setPosition(ccp(size.width/2,size.height/2));
	m_pObj->chgState(StateStand::create());
	addChild(m_pObj);

	{
		CCSprite *spRocker=CCSprite::create("joystick/joystick_left_fg.png");//Ò¡¸Ë
		CCSprite *spRockerBG=CCSprite::create("joystick/joystick_left_bg.png");//Ò¡¸Ë±³¾°
		Rocker *rocker=Rocker::createRockerWithCenter(ccp(120,120.0f),50.0f ,spRocker ,spRockerBG,false);//´´½¨Ò¡¸Ë
		rocker->setBeginNotification(BattleFacade::NOTIFICATION_ROCKER_TOUCH_LEFT_BEGIN);
		rocker->setMoveNotification(BattleFacade::NOTIFICATION_ROCKER_TOUCH_LEFT_MOVE);
		rocker->setEndNotification(BattleFacade::NOTIFICATION_ROCKER_TOUCH_LEFT_END);
		this->addChild(rocker);//Ò¡¸ËÌí¼Óµ½layerÖÐ

	}
	
	{
		CCSprite *spRocker=CCSprite::create("joystick/control_joystick.png");//Ò¡¸Ë
		CCSprite *spRockerBG=CCSprite::create("joystick/control_baseboard.png");//Ò¡¸Ë±³¾°
		Rocker *rocker=Rocker::createRockerWithCenter(ccp(size.width-120,120.0f),50.0f ,spRocker ,spRockerBG,false);//´´½¨Ò¡¸Ë
		rocker->setBeginNotification(BattleFacade::NOTIFICATION_ROCKER_TOUCH_RIGHT_BEGIN);
		rocker->setMoveNotification(BattleFacade::NOTIFICATION_ROCKER_TOUCH_RIGHT_MOVE);
		rocker->setEndNotification(BattleFacade::NOTIFICATION_ROCKER_TOUCH_RIGHT_END);
		this->addChild(rocker);//Ò¡¸ËÌí¼Óµ½layerÖÐ

	}


	//this ÊÇ¸ölayer


}
void testScene::onEnterScene()
{

}
void testScene::onExitScene()
{

}
void testScene::loadExtraData(void* data)
{

}
void testScene::menuCloseCallback(CCObject* obj)
{
	CCLog("dsaddsa");
	//MgrScene::getInstance()->runUIScene(LOAD_UI("UIScene"));
	MgrScene::getInstance()->runWidthScene("LoginMediator");
}
void testScene::initInterests()
{
	m_vInterests.push_back(BattleFacade::NOTIFICATION_ROCKER_TOUCH_LEFT_MOVE);
	m_vInterests.push_back(BattleFacade::NOTIFICATION_ROCKER_TOUCH_LEFT_BEGIN);
	m_vInterests.push_back(BattleFacade::NOTIFICATION_ROCKER_TOUCH_LEFT_END);

	m_vInterests.push_back(BattleFacade::NOTIFICATION_ROCKER_TOUCH_RIGHT_MOVE);
	m_vInterests.push_back(BattleFacade::NOTIFICATION_ROCKER_TOUCH_RIGHT_BEGIN);
	m_vInterests.push_back(BattleFacade::NOTIFICATION_ROCKER_TOUCH_RIGHT_END);
}
void testScene::handleNotification(Notification& noti)
{
	const string str=noti.m_strNotiName;
	CCLog("handleNotification %s ",str.c_str());
	if(StringHelper::isEqual(str,BattleFacade::NOTIFICATION_ROCKER_TOUCH_LEFT_MOVE))
	{
		
		void* data=noti.m_pData;
		CCPoint point=*((CCPoint*)data);
		m_pObj->chgState(StateMoveBy::create(-point.x*1000,-point.y*1000,1000));
	}
	else if(StringHelper::isEqual(str,BattleFacade::NOTIFICATION_ROCKER_TOUCH_LEFT_END))
	{
		m_pObj->chgState(StateStand::create());
	}
	else if(StringHelper::isEqual(str,BattleFacade::NOTIFICATION_ROCKER_TOUCH_RIGHT_BEGIN))
	{
		m_pObj->chgState(StateAttack::create());
	}

};