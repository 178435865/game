#include "game/test/testScene1.h"

void testScene1::onLoadResource()
{

}
void testScene1::onLoadUI()
{
	CCLog("loadUi");
	CCSprite* sprite=CCSprite::create("close2.png");
	addChild(sprite);
	sprite->setPosition(ccp(600,400));

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(  
		"close1.png",  
		"close2.png",  
		this,  
		menu_selector(testScene1::menuCloseCallback));  

	pMenu = CCMenu::create(pCloseItem,NULL); 
	pMenu->setPosition(ccp(100,400));
	addChild(pMenu);
	CCLabelTTF* label=CCLabelTTF::create();
	label->setString("tesst Scene 11111111111111111");
	label->setPosition(ccp(500,500));
	label->setFontSize(80);
	addChild(label);
}
void testScene1::onEnterScene()
{

}
void testScene1::onExitScene()
{

}
void testScene1::loadExtraData(void* data)
{

}
void testScene1::menuCloseCallback(CCObject* obj)
{
	CCLog("dsaddsa");
	MgrScene::getInstance()->runWidthScene("testScene");
	//MgrScene::getInstance()->runUIScene("UIScene");
	//MgrScene::getInstance()->popScene();
}