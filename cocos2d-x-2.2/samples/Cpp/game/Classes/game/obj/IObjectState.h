#ifndef _IOBJECT_STATE_
#define _IOBJECT_STATE_
#include "util/Util.h"

class Obj;

enum enObjectState
{
	eStand,
	eHit,
	eMoveTo,
	eMoveBy,
	eAttack,
	eDead
};


class IObjectState
{
public:
	virtual enObjectState getState()=0;
	virtual void execute(Obj* obj);
	virtual void beforeExecute(Obj* obj)=0;
	virtual void afterExecute(Obj* obj)=0;
	virtual bool isDone();
	virtual void finish(Obj* obj);
	virtual void mergeState(IObjectState* state){};
	virtual ~IObjectState();
	CC_SYNTHESIZE_READONLY(bool,m_bIsExecuted,IsExecuted);
	CCAction* getAction(){return action;};
protected:
	IObjectState(){m_bIsExecuted=false;action=0;};
	CCAction* action;
};

class StateStand :public IObjectState
{
public:
	virtual void beforeExecute(Obj* obj){};
	virtual void afterExecute(Obj* obj){};
	virtual ~StateStand(){};
	static StateStand* create();
	enObjectState getState(){return eStand;};
private:
	StateStand(){};
	
};


class StateMoveTo :public IObjectState
{
public:
	virtual void beforeExecute(Obj* obj){};
	virtual void afterExecute(Obj* obj){};
	virtual ~StateMoveTo(){};
	static StateMoveTo* create(float x,float y,float duration);
	enObjectState getState(){return eMoveTo;};
	void mergeState(IObjectState* state);
private:
	StateMoveTo(){};
};


class StateMoveBy :public IObjectState
{
public:
	virtual void beforeExecute(Obj* obj){};
	virtual void afterExecute(Obj* obj){};
	virtual ~StateMoveBy(){};
	void mergeState(IObjectState* state);

	static StateMoveBy* create(float x,float y,float duration);
	enObjectState getState(){return eMoveBy;};
private:
	StateMoveBy(){};
};


class StateHit :public IObjectState
{
public:
	virtual void beforeExecute(Obj* obj){};
	virtual void afterExecute(Obj* obj){};
	virtual ~StateHit(){};
	static StateHit* create();
	enObjectState getState(){return eHit;};
private:
	StateHit(){};
};

class StateAttack :public IObjectState
{
public:
	virtual void beforeExecute(Obj* obj){};
	virtual void afterExecute(Obj* obj){};
	virtual ~StateAttack(){};
	static StateAttack* create();
	enObjectState getState(){return eAttack;};
private:
	StateAttack(){};
};

class StateDead :public IObjectState
{
public:
	virtual void beforeExecute(Obj* obj){};
	virtual void afterExecute(Obj* obj){};
	virtual ~StateDead(){};
	static StateDead* create();
	virtual void finish(Obj* obj){};
	enObjectState getState(){return eDead;};
private:
	StateDead(){};
};

#endif
