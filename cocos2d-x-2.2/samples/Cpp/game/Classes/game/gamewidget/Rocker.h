#ifndef	_ROCKER_
#define _ROCKER_
#include "util/Util.h"

class Rocker :public CCLayer {

public :
	//��ʼ�� aPoint��ҡ������ aRadius��ҡ�˰뾶 aJsSprite��ҡ�˿��Ƶ� aJsBg��ҡ�˱���
	static Rocker*  createRockerWithCenter(CCPoint aPoint ,float aRadius ,CCSprite* aJsSprite,CCSprite* aJsBg,bool _isFollowRole);
	//����ҡ��
	void Active();
	//���ҡ��
	void UnActive();
	CC_SYNTHESIZE(string,m_iBeginNotification,BeginNotification);
	CC_SYNTHESIZE(string,m_iEndNotification,EndNotification);
	CC_SYNTHESIZE(string,m_iMoveNotification,MoveNotification);
private:
	CCPoint m_pCenterPoint;//ҡ������
	CCPoint m_pCurrentPoint;//ҡ�˵�ǰλ��
	bool m_bActive;//�Ƿ񼤻�ҡ��
	float m_fRadius;//ҡ�˰뾶
	CCSprite *m_pJsSprite;
	bool m_bIsFollowRole;//�Ƿ�����û����
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
