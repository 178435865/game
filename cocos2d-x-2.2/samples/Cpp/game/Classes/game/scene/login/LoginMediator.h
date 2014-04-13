#ifndef _LOGIN_MEDIATOR_
#define _LOGIN_MEDIATOR_
#include "mvc/patterns/Mediator.h"
#include "framework/GameScene.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "framework/BaseMacros.h"
USING_NS_CC_EXT;
USING_NS_CC;


class LoginMediator :public Mediator,public GameScene
{
public:
	void handleNotification(Notification& noti);
	void callback(CCObject *obj, TouchEventType type);
	void onLoadResource();
	void onLoadUI();
	void onEnterScene();
	void onExitScene();
	void loadExtraData(void* data);
	CREATE_SCENE_FUNC(LoginMediator);
	void initInterests();
	bool init(){return Mediator::init();};
private:
	LoginMediator();
	virtual ~LoginMediator(){};
	void initButton();
private:
	UIWidget* ui;
	
};
#endif