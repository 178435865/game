#include "game/ui/missinfo/MissInfoDetailMediator.h"
#include "game/ui/missinfo/MissInfoDetailFacade.h"
//#include "game/ui/missinfo/MissInfoDetailVO.h"
#include "util/Util.h"
#include "mvc/patterns/Notification.h"

MissInfoDetailMediator::MissInfoDetailMediator():Mediator(MissInfoDetailFacade::MEDIATOR_MISS_INFO_DETAIL)
{

}
MissInfoDetailMediator::~MissInfoDetailMediator()
{
	CCLog("dasd");
}
bool MissInfoDetailMediator::init()
{
	Mediator::init();
	//CCLog("====%s====",MgrScene::getInstance()->infoDetailName);
	
	return true;
}
void MissInfoDetailMediator::handleNotification(Notification& noti)
{
	CCLog("handle notification %s",noti.toString().c_str());
	const string& name=noti.m_strNotiName;
	/**
	if(StringHelper::isEqual(name,MissInfoDetailFacade::NOTIFICATION_CLOSE))
	{
		MgrScene::getInstance()->popScene(this);
	}
	else  
	if(StringHelper::isEqual(name,MissInfoDetailFacade::NOTIFICATION_SWITCH_SRH_SUCCESS))
	{
		//MgrScene::getInstance()->popScene(this);
		MgrScene::getInstance()->runWidthScene("LoginMediator");
	}*/
}
void MissInfoDetailMediator::callback(CCObject *obj, TouchEventType type)
{
	//CCMenuItemLabel *itemLabel=dynamic_cast<CCMenuItemLabel*>(obj);
	//CCLabelTTF *label = dynamic_cast<CCLabelTTF*>(itemLabel->getLabel());
	
	//CCLog(((CCString*)pCloseItemn->getUserData())->m_sString.c_str());
	MgrScene::getInstance()->runWidthScene("MissInfoMediator");
	
	
}
void MissInfoDetailMediator::initButton()
{
	UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(MissInfoDetailMediator::callback),"Button_65",downmenuToolbarUi);
	//ui->getChildByName("Button_134");
	UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(MissInfoDetailMediator::callback),"Button_102_0_0",ui);
	//UtilCocostudio::getInstance()->addEventRelease(this,toucheventselector(MissInfoDetailMediator::callback),"login_Button",ui);

}
void MissInfoDetailMediator::onLoadResource()
{

}
void MissInfoDetailMediator::onLoadUI()
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

	downmenuToolbarUi=UtilCocostudio::getInstance()->createWidgetFromJsonFile("outmenu/downmenu.json");
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
		menu_selector(MissInfoDetailMediator::callback));  
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
void MissInfoDetailMediator::onEnterScene()
{
	//?????????????????
	/*CCDictionary *strings = CCDictionary::createWithContentsOfFile(MgrScene::getInstance()->infoDetailName);
	CCArray* _targets =strings->allKeys();
    CCObject* jt = NULL;
	int baseX = 500;
	int baseY = 150;
    CCARRAY_FOREACH(_targets, jt)
    {
        CCString *target = dynamic_cast<CCString*>(jt);
		const char *chinese  = ((CCString*)strings->objectForKey(target->getCString()))->m_sString.c_str();

		CCSprite* sprite=CCSprite::create("ui_button_select.png");
		addChild(sprite);
		sprite->setPosition(ccp(baseX,baseY));
		CCLabelTTF* labelTTF = CCLabelTTF::create(chinese, "Helvetica", 40);
		labelTTF->setColor(ccBLACK);
		CCMenuItemLabel *labelMenu = CCMenuItemLabel::create(labelTTF, this, NULL);
		CCMenu* pMenu = CCMenu::create(labelMenu,NULL); 
		pMenu->setPosition(ccp(baseX,baseY));
		addChild(pMenu);

		baseY+=100;
    }*/


}
void MissInfoDetailMediator::onExitScene()
{

}
void MissInfoDetailMediator::loadExtraData(void* data)
{

}
void MissInfoDetailMediator::initInterests()
{
//	m_vInterests.push_back(MissInfoDetailFacade::NOTIFICATION_LOGIN_SUCESS);
//	m_vInterests.push_back(MissInfoDetailFacade::NOTIFICATION_SWITCH_SRH_SUCCESS);
//	m_vInterests.push_back(MissInfoDetailFacade::NOTIFICATION_LOGIN_FAIL);
//	m_vInterests.push_back(MissInfoDetailFacade::NOTIFICATION_CLOSE);
}