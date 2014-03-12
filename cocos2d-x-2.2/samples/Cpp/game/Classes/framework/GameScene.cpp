#include "framework/GameScene.h"

GameScene::GameScene()
{
	m_bIsLoaded=false;
	setAnchorPoint(CCPointZero);
	setContentSize(CCDirector::sharedDirector()->getWinSize());
}
GameScene::~GameScene()
{

}
void GameScene::onEnter()
{
	onEnterScene();
	CCNode::onEnter();
}
void GameScene::onExit()
{
	onExitScene();
	CCNode::onExit();
}
void GameScene::onloadResourceCompleted()
{
	m_bIsLoaded=true;
	onLoadUI();
}
void GameScene::setClassName(const string& name)
{
	m_strClassName=name;
}
const vector<string>& GameScene::getResources()
{
	return m_vResources;
}
const string& GameScene::getClassName()
{
	return m_strClassName;
}
bool GameScene::getIsLoad()
{
	return m_bIsLoaded;
}
void GameScene::setIsLoad(bool ret)
{
	m_bIsLoaded=ret;
}