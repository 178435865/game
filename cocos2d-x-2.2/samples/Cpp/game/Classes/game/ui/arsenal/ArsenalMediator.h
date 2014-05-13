#ifndef _ARSENAL_MEDIATOR_
#define _ARSENAL_MEDIATOR_
#include "mvc/patterns/Mediator.h"
#include "framework/GameScene.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "framework/BaseMacros.h"
USING_NS_CC_EXT;
USING_NS_CC;


class ArsenalMediator :public Mediator,public GameScene
{
public:
	bool init();
	void handleNotification(Notification& noti);
	void callback(CCObject *obj, TouchEventType type);
	void onLoadResource();
	void onLoadUI();
	void onEnterScene();
	void onExitScene();
	void loadExtraData(void* data);
	CREATE_SCENE_FUNC(ArsenalMediator);
	void initInterests();
private:
	ArsenalMediator();
	virtual ~ArsenalMediator();
	void initButton();
private:
	UIWidget* ui;
	
};
#endif