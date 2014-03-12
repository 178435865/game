#include "game/test/testScene.h"

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
	//SceneManager::getInstance()->runUIScene(LOAD_UI("UIScene"));
	SceneManager::getInstance()->runWidthScene("LoginMediator");
}