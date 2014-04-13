#ifndef _TEST_SCENE_
#define _TEST_SCENE_
#include "framework/GameScene.h"
class Obj;
class testScene :public GameScene,public Mediator
{
public:
	void onLoadResource();
	void onLoadUI();
	void onEnterScene();
	void onExitScene();
	void loadExtraData(void* data);
	bool init(){return Mediator::init();};
	CREATE_SCENE_FUNC(testScene);
	void menuCloseCallback(CCObject* obj);
	virtual void initInterests();
	virtual void handleNotification(Notification& noti);
private:
	testScene();
private:
	Obj* m_pObj;
	CCMenu* pMenu;
};
#endif