#include "game/gamewidget/Rocker.h"
#include "game/scene/battle/BattleFacade.h"

void Rocker::updatePos(float dt){
	m_pJsSprite->setPosition(ccpAdd(m_pJsSprite->getPosition(),ccpMult(ccpSub(m_pCurrentPoint, m_pJsSprite->getPosition()),0.5)));
}
//启动摇杆
void Rocker::Active()
{
	if (!m_bActive) {
		m_bActive=true;
		schedule(schedule_selector(Rocker::updatePos));//添加刷新函数
		  CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0,false);//添加触摸委托
	}else {
	}
}
//解除摇杆
void   Rocker::UnActive()
{
	if (m_bActive) {
		m_bActive=false;
		this->unschedule(schedule_selector(Rocker::updatePos));//删除刷新
		  CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);//删除委托
	}else {
	}
}
//摇杆方位
CCPoint Rocker::getDirection()
{
	return ccpNormalize(ccpSub(m_pCenterPoint, m_pCurrentPoint));
}
//摇杆力度
float Rocker::getVelocity()
{
	return ccpDistance(m_pCenterPoint, m_pCurrentPoint);
}
Rocker* Rocker:: createRockerWithCenter(CCPoint aPoint ,float aRadius ,CCSprite* aJsSprite,CCSprite* aJsBg,bool _isFollowRole){
	Rocker *jstick=new Rocker();
	if(jstick)
	{
		jstick->autorelease();
		jstick->initWithCenter(aPoint,aRadius,aJsSprite,aJsBg,_isFollowRole);
	}
	else
	{
		delete jstick;
		jstick=NULL;
	}
	
	return jstick;
}
bool Rocker::ccTouchBegan(CCTouch* touch, CCEvent* event)
{

	if (!m_bActive)
		return false;
	this->setVisible(true);
	CCPoint touchPoint = touch->getLocationInView();
	touchPoint = CCDirector:: sharedDirector()->convertToGL(touchPoint);
	if(!m_bIsFollowRole){
		if (ccpDistance(touchPoint, m_pCenterPoint) > m_fRadius){
			return false;
		}
	}
	m_pCurrentPoint = touchPoint;
	if(m_bIsFollowRole){
		m_pCenterPoint=m_pCurrentPoint;
		m_pJsSprite->setPosition(m_pCurrentPoint);
		this->getChildByTag(88)->setPosition(m_pCurrentPoint);
	}
	Facade::getInstance()->sendNotification(getBeginNotification());
	return true;
}
void  Rocker::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	CCPoint touchPoint = touch->getLocationInView();
	touchPoint = CCDirector:: sharedDirector()->convertToGL(touchPoint);
	if (ccpDistance(touchPoint, m_pCenterPoint) > m_fRadius)
	{
		m_pCurrentPoint =ccpAdd(m_pCenterPoint,ccpMult(ccpNormalize(ccpSub(touchPoint, m_pCenterPoint)), m_fRadius));
	}else {
		m_pCurrentPoint = touchPoint;
	}
	Facade::getInstance()->sendNotification(getMoveNotification(),&getDirection());
}
void  Rocker::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	m_pCurrentPoint = m_pCenterPoint;
	if(m_bIsFollowRole){
		this->setVisible(false);
	}
	Facade::getInstance()->sendNotification(getEndNotification());
}
Rocker* Rocker::initWithCenter(CCPoint aPoint ,float aRadius ,CCSprite* aJsSprite,CCSprite* aJsBg,bool _isFollowRole){

	m_bIsFollowRole =_isFollowRole;
	m_bActive = false;
	m_fRadius = aRadius;
	if(!_isFollowRole){
		m_pCenterPoint =aPoint;
	}else{
		m_pCenterPoint =ccp(0,0);
	}

	m_pCurrentPoint = m_pCenterPoint;
	m_pJsSprite = aJsSprite;
	m_pJsSprite->setPosition(m_pCenterPoint);
	aJsBg->setPosition(m_pCenterPoint);
	aJsBg->setTag(88);
	this->addChild(aJsBg);
	this->addChild(m_pJsSprite);
	if(m_bIsFollowRole){
		this->setVisible(false);
	}
	this->Active();//激活摇杆
	return this;
}