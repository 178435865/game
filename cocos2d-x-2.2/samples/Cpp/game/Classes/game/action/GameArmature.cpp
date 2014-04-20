#include "game/action/GameArmature.h"
#include "util/Util.h"
#include "game/obj/Creature.h"

bool IArmature::isDone(void)
{
	return m_bIsDone;
}
void IArmature::startWithTarget(CCNode *pTarget)
{
	Obj* obj=dynamic_cast<Obj*>(pTarget);
	if(obj)
	{
		obj->getAnimation()->play(m_sArmatureName.c_str(),-1,-1,m_bLoop?1:0);
	}

}

bool GameArmature::isDone(void)
{
	return IArmature::isDone();
}
void GameArmature::startWithTarget(CCNode *pTarget)
{
	CCAction::startWithTarget(pTarget);
	IArmature::startWithTarget(pTarget);
	Obj* obj=dynamic_cast<Obj*>(pTarget);
	if(obj&&!m_bLoop)
	{
		obj->getAnimation()->setMovementEventCallFunc(this, movementEvent_selector(GameArmature::animationEvent));
	}
	
}
void GameArmature::stop(void)
{
	CCAction::stop();
}
void GameArmature::step(float dt)
{
	if(!m_bIsDone)
	{
		//CCAction::step(dt);
	}
	
}
GameArmature* GameArmature::create(const string& name,bool loop)
{
	GameArmature* ga=new GameArmature();
	if(ga)
	{
		ga->m_sArmatureName=name;
		ga->m_bLoop=loop;
		ga->autorelease();
	}
	else
	{
		delete ga;
		ga=NULL;
	}
	return ga;
	
}
void GameArmature::animationEvent(cocos2d::extension::CCArmature *armature, MovementEventType movementType, const char *movementID)
{
	if(movementType==COMPLETE)
	{
		m_bIsDone=true;
		//m_pTarget->stopAction(this);
		
	}
	else if(movementType==LOOP_COMPLETE)
	{
		//m_bIsDone=true;
		//m_pTarget->stopAction(this);
	}
}


ActionMoveTo* ActionMoveTo::create(const CCPoint& moveDest,float duration)
{
	ActionMoveTo* action=new ActionMoveTo();
	if(action)
	{
		action->autorelease();
		action->initWithDuration(duration,moveDest);
	}
	else
	{
		delete action;
		action=NULL;
	}
	return action;
}
bool ActionMoveTo::isDone(void)
{
	return CCMoveTo::isDone();
}
 void ActionMoveTo::startWithTarget(CCNode *pTarget)
 {
	 CCMoveTo::startWithTarget(pTarget);
	 IArmature::startWithTarget(pTarget);
 }
 void ActionMoveTo::stop(void)
 {
	 CCMoveTo::stop();
 }
 void ActionMoveTo::step(float dt)
 {
	 
	 Creature* obj=dynamic_cast<Creature*>(m_pTarget);
	 if(obj)
	 {
		 float x=obj->getPositionX();
		 float y=obj->getPositionY();
		 float destX=x+m_positionDelta.x;
		 float destY=y+m_positionDelta.y;
		 obj->setFace(x,y,destX,destY);
	 }
	 CCMoveTo::step(dt);
 }
 const CCPoint& ActionMoveTo::getEndPos()
 {
	 return m_endPosition;
 }
 
 ActionMoveBy* ActionMoveBy::create(const CCPoint& moveDest,float duration)
 {
	 ActionMoveBy* action=new ActionMoveBy();
	 if(action)
	 {
		 action->autorelease();
		 action->initWithDuration(duration,moveDest);
	 }
	 else
	 {
		 delete action;
		 action=NULL;
	 }
	 return action;
 }
 bool ActionMoveBy::isDone(void)
 {
	 return CCMoveBy::isDone();
 }
 void ActionMoveBy::startWithTarget(CCNode *pTarget)
 {
	 CCMoveBy::startWithTarget(pTarget);
	 IArmature::startWithTarget(pTarget);
 }
 void ActionMoveBy::stop(void)
 {
	 CCMoveBy::stop();
 }
 void ActionMoveBy::step(float dt)
 {
	 CCMoveBy::step(dt);
	 Creature* obj=dynamic_cast<Creature*>(m_pTarget);
	 if(obj)
	 {
		 float x=obj->getPositionX();
		 float y=obj->getPositionY();
		 float destX=x+m_positionDelta.x;
		 float destY=y+m_positionDelta.y;
		 obj->setFace(x,y,destX,destY);
	 }
 }
void ActionMoveBy::mergetAction(IArmature* action)
{
	ActionMoveBy* other=dynamic_cast<ActionMoveBy*>(action);
	if(other)
	{
		m_positionDelta=other->m_positionDelta;
		CCPoint m_startPosition=m_pTarget->getPosition();
	}
}