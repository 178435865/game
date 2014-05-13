#include "game/ui/missinfo/MissInfoMediator.h"
#include "game/ui/missinfo/MissInfoDetailMediator.h"
#include "game/ui/missinfo/MissInfoFacade.h"
//#include "game/ui/missinfo/MissInfoVO.h"
#include "util/Util.h"
#include "mvc/patterns/Notification.h"

MissInfoMediator::MissInfoMediator():Mediator(MissInfoFacade::MEDIATOR_MISS_INFO)
{

}
MissInfoMediator::~MissInfoMediator()
{
	CCLog("dasd");
}
bool MissInfoMediator::init()
{
	Mediator::init();
	
	return true;
}
void MissInfoMediator::handleNotification(Notification& noti)
{
	CCLog("handle notification %s",noti.toString().c_str());
	const string& name=noti.m_strNotiName;
	/**
	if(StringHelper::isEqual(name,MissInfoFacade::NOTIFICATION_CLOSE))
	{
		MgrScene::getInstance()->popScene(this);
	}
	else  
	if(StringHelper::isEqual(name,MissInfoFacade::NOTIFICATION_SWITCH_SRH_SUCCESS))
	{
		//MgrScene::getInstance()->popScene(this);
		MgrScene::getInstance()->runWidthScene("LoginMediator");
	}*/
}
void MissInfoMediator::callback(CCObject *obj, TouchEventType type)
{
	CCMenuItemLabel *itemLabel=dynamic_cast<CCMenuItemLabel*>(obj);
	CCLabelTTF *label = dynamic_cast<CCLabelTTF*>(itemLabel->getLabel());
	MissInfoDetailMediator* infoDetailMediator = (MissInfoDetailMediator*)MgrScene::getInstance()->loadScene("MissInfoDetailMediator");
	//MgrScene::getInstance()->infoDetailName = label->getString();?????????????
	MgrScene::getInstance()->runWidthScene("MissInfoDetailMediator");
	//MgrScene::getInstance()->pu
	//MgrScene::getInstance()->
	//CCLog(((CCString*)pCloseItemn->getUserData())->m_sString.c_str());
	//MgrScene::getInstance()->runWidthScene("EquipmentMediator");
	
	
}
void MissInfoMediator::initButton()
{
	UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(MissInfoMediator::callback),"Button_102_0_0",ui);
	ui->getChildByName("Button_134");
	//UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(MissInfoMediator::callback),"Button_102_0",ui);
	//UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(MissInfoMediator::callback),"login_Button",ui);

}
void MissInfoMediator::onLoadResource()
{

}
void MissInfoMediator::onLoadUI()
{

	ui=UtilCocostudio::getInstance()->createWidgetFromJsonFile("outmenu/mission_normal.json");
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

	 CCDictionary *strings = CCDictionary::createWithContentsOfFile("strings.xml");
	 CCArray* _targets =strings->allKeys();
    CCObject* jt = NULL;
	int baseX = 500;
	int baseY = 150;
    CCARRAY_FOREACH(_targets, jt)
    {
        CCString *target = dynamic_cast<CCString*>(jt);
		const char *chinese  = ((CCString*)strings->objectForKey(target->getCString()))->m_sString.c_str();

			CCSprite* sprite=CCSprite::create("outmenu/Resources/ui_mission_purple.png");
		addChild(sprite);
		sprite->setPosition(ccp(baseX,baseY));

		/** */
		//CCMenuItemLabel *labelMenu = CCMenuItemLabel::create(CCLabelTTF::create(chinese, "Helvetica", 40), this, menu_selector(MissInfoMediator::callback));
		//labelMenu->setColor(ccBLACK);
		//
		///**
		//CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		//	"ui_button_select.png",  
		//	"ui_button_select.png",  
		//	this,  
		//	menu_selector(MissInfoMediator::callback)); 
		//pCloseItem->setScale(1.2);
		//pCloseItem->setUserObject(target); */
		////pCloseItem->set
		//CCMenu* pMenu = CCMenu::create(labelMenu,NULL); 
		//pMenu->setPosition(ccp(baseX,baseY));
		//addChild(pMenu);
		/**
		CCLabelTTF* label=CCLabelTTF::create();
		label->setString(chinese);
		label->setPosition(ccp(baseX,baseY));
		label->setFontSize(40);
		label->setColor(ccBLACK);
		addChild(label);
		*/


		baseY+=100;
    }


	/** 
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"ui_button_select.png",  
		"ui_button_select.png",  
		this,  
		menu_selector(MissInfoMediator::callback));  
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
void MissInfoMediator::onEnterScene()
{

}
void MissInfoMediator::onExitScene()
{

}
void MissInfoMediator::loadExtraData(void* data)
{

}
void MissInfoMediator::initInterests()
{
//	m_vInterests.push_back(MissInfoFacade::NOTIFICATION_LOGIN_SUCESS);
//	m_vInterests.push_back(MissInfoFacade::NOTIFICATION_SWITCH_SRH_SUCCESS);
//	m_vInterests.push_back(MissInfoFacade::NOTIFICATION_LOGIN_FAIL);
//	m_vInterests.push_back(MissInfoFacade::NOTIFICATION_CLOSE);
}