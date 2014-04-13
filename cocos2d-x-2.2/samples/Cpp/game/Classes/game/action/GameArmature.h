#ifndef _GAME_ARMATURE_
#define _GAME_ARMATURE_
#include "util/Util.h"

class IArmature
{
public:
	virtual ~IArmature(){};
	 virtual void startWithTarget(CCNode *pTarget);
	 virtual bool isDone(void);
	 virtual void mergetAction(IArmature* action){};
	 void setIsDone(bool isDone){m_bIsDone=isDone;};
protected:
	IArmature(){m_bLoop=false;m_bIsDone=false;};
	string m_sArmatureName;
	bool m_bLoop;
	bool m_bIsDone;
};

class GameArmature :public CCAction,public IArmature
{
public:
	virtual ~GameArmature(){};
	virtual bool isDone(void);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void stop(void);
    virtual void step(float dt);
	static GameArmature* create(const string& name,bool loop=false);
	void animationEvent(cocos2d::extension::CCArmature *armature, MovementEventType movementType, const char *movementID);
protected:
	GameArmature(){};
};

class  ActionDead :public GameArmature
{
public:
	virtual ~ActionDead(){};
	bool init(){return true;};
	CREATE_FUNC(ActionDead);
protected:
	ActionDead(){m_sArmatureName="dead";m_bLoop=false;};
};

class  ActionAttack :public GameArmature
{
public:
	virtual ~ActionAttack(){};
	bool init(){return true;};
	CREATE_FUNC(ActionAttack);
protected:
	ActionAttack(){m_sArmatureName="attack";m_bLoop=false;};
};

class  ActionHit :public GameArmature
{
public:
	virtual ~ActionHit(){};
	bool init(){return true;};
	CREATE_FUNC(ActionHit);
protected:
	ActionHit(){m_sArmatureName="hit";m_bLoop=false;};
};

class  ActionStand :public GameArmature
{
public:
	virtual ~ActionStand(){};
	bool init(){return true;};
	CREATE_FUNC(ActionStand);
protected:
	ActionStand(){m_sArmatureName="stand";m_bLoop=true;};
};

class ActionMoveTo:public CCMoveTo,public IArmature
{
public:
	virtual ~ActionMoveTo(){};
	static ActionMoveTo* create(const CCPoint& moveDest,float duration);
	virtual bool isDone(void);
	virtual void startWithTarget(CCNode *pTarget);
	virtual void stop(void);
	virtual void step(float dt);
	const CCPoint& getEndPos();
protected:
	ActionMoveTo(){m_sArmatureName="run";m_bLoop=true;};
};

class ActionMoveBy:public CCMoveBy,public IArmature
{
public:
	virtual ~ActionMoveBy(){};
	static ActionMoveBy* create(const CCPoint& moveDest,float duration);
	virtual bool isDone(void);
	virtual void startWithTarget(CCNode *pTarget);
	virtual void stop(void);
	virtual void step(float dt);
	virtual void mergetAction(IArmature* action);
protected:
	ActionMoveBy(){m_sArmatureName="run";m_bLoop=true;};
};



#endif // !_GAME_ARMATURE_
