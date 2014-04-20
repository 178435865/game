#ifndef	_ROCKER_
#define _ROCKER_
#include "util/Util.h"

class Rocker :public CCLayer {

public :
	//初始化 aPoint是摇杆中心 aRadius是摇杆半径 aJsSprite是摇杆控制点 aJsBg是摇杆背景
	static Rocker*  createRockerWithCenter(CCPoint aPoint ,float aRadius ,CCSprite* aJsSprite,CCSprite* aJsBg,bool _isFollowRole);
	//启动摇杆
	void Active();
	//解除摇杆
	void UnActive();
	CC_SYNTHESIZE(string,m_iBeginNotification,BeginNotification);
	CC_SYNTHESIZE(string,m_iEndNotification,EndNotification);
	CC_SYNTHESIZE(string,m_iMoveNotification,MoveNotification);
private:
	CCPoint m_pCenterPoint;//摇杆中心
	CCPoint m_pCurrentPoint;//摇杆当前位置
	bool m_bActive;//是否激活摇杆
	float m_fRadius;//摇杆半径
	CCSprite *m_pJsSprite;
	bool m_bIsFollowRole;//是否跟随用户点击
private:
	Rocker * initWithCenter(CCPoint aPoint ,float aRadius ,CCSprite* aJsSprite,CCSprite* aJsBg,bool _isFollowRole);
	CCPoint getDirection();
	float getVelocity();
	void  updatePos(float dt);
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	Rocker():m_iBeginNotification(""),m_iEndNotification(""),m_iMoveNotification(""){};
};
#endif
