#include "game/obj/IObjectState.h"
#include "game/obj/Obj.h"
#include "game/action/GameArmature.h"

bool IObjectState::isDone()
{
	if(action)
	{
		return action->isDone();
	}
	return false;
}
void IObjectState::finish(Obj* obj)
{
	obj->chgState(StateStand::create());
}
void IObjectState::execute(Obj* obj){
	m_bIsExecuted=true;
	if(action)
	{
		obj->runAction(action);
	}
};
IObjectState::~IObjectState(){
	CC_SAFE_RELEASE_NULL(action);
}

StateStand* StateStand::create()
{
	StateStand* ss=new StateStand();
	ss->action=ActionStand::create();
	ss->action->retain();
	return ss;
}
StateMoveTo* StateMoveTo::create(float x,float y,float duration)
{
	StateMoveTo* ss=new StateMoveTo();
	ss->action=ActionMoveTo::create(ccp(x,y),duration);
	ss->action->retain();
	return ss;
}
void StateMoveTo::mergeState(IObjectState* state)
{
	CCAction* other=NULL;
	if(state)
	{
		other=state->getAction();
	}
	if(other)
	{
		ActionMoveTo* action=dynamic_cast<ActionMoveTo*>(other);
		ActionMoveTo* currentAction=dynamic_cast<ActionMoveTo*>(getAction());
		if(action&&currentAction)
		{
			currentAction->initWithDuration(action->getDuration(),action->getEndPos());
		}
	}

}
StateMoveBy* StateMoveBy::create(float x,float y,float duration)
{
	StateMoveBy* ss=new StateMoveBy();
	ss->action=ActionMoveBy::create(ccp(x,y),duration);
	ss->action->retain();
	return ss;
}
void StateMoveBy::mergeState(IObjectState* state)
{
	CCAction* other=NULL;
	if(state)
	{
		other=state->getAction();
	}
	if(other)
	{
		ActionMoveBy* action=dynamic_cast<ActionMoveBy*>(other);
		ActionMoveBy* currentAction=dynamic_cast<ActionMoveBy*>(getAction());
		if(action&&currentAction)
		{
			currentAction->mergetAction(action);
		}
	}

}
StateHit* StateHit::create()
{
	StateHit* ss=new StateHit();
	ss->action=ActionHit::create();
	ss->action->retain();
	return ss;
}
StateAttack* StateAttack::create()
{
	StateAttack* ss=new StateAttack();
	ss->action=ActionAttack::create();
	ss->action->retain();
	return ss;
}
StateDead* StateDead::create()
{
	StateDead* ss=new StateDead();
	ss->action=ActionDead::create();
	ss->action->retain();
	return ss;
}
