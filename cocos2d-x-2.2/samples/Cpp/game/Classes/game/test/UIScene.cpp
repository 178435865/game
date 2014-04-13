#include "game/test/UIScene.h"

void UIScene::onLoadResource()
{

}
void UIScene::onLoadUI()
{
	CCLog("loadUi");
	CCSprite* sprite=CCSprite::create("close2.png");
	addChild(sprite);
	sprite->setPosition(ccp(600,400));

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(  
		"close1.png",  
		"close2.png",  
		this,  
		menu_selector(UIScene::menuCloseCallback));  

	pMenu = CCMenu::create(pCloseItem,NULL); 
	pMenu->setPosition(ccp(100,400));
	addChild(pMenu);

	CCLabelTTF* label=CCLabelTTF::create();
	label->setString("UI Scene");
	label->setPosition(ccp(500,500));
	label->setFontSize(80);
	addChild(label);
}
void UIScene::onEnterScene()
{

}
void UIScene::onExitScene()
{

}
void UIScene::loadExtraData(void* data)
{

}
void UIScene::menuCloseCallback(CCObject* obj)
{
	//MgrScene::getInstance()->popUIScene(this);
	MgrScene::getInstance()->runUIScene("UIScene");
}