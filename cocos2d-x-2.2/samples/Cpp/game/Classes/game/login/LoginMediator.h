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
	bool init();
	void handleNotification(Notification& noti);
	void callback(CCObject* obj);
	void onLoadResource();
	void onLoadUI();
	void onEnterScene();
	void onExitScene();
	void loadExtraData(void* data);
	CREATE_SCENE_FUNC(LoginMediator);
	void initInterests();
private:
	LoginMediator();
	virtual ~LoginMediator();
	void initButton();
private:
	UIWidget* ui;
	
};
#endif