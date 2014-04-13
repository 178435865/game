#ifndef _FIGHTCONFIG_EQUIPMENT_
#define _FIGHTCONFIG_EQUIPMENT_
#include "mvc/patterns/Mediator.h"
#include "framework/GameScene.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "framework/BaseMacros.h"
USING_NS_CC_EXT;
USING_NS_CC;


class Equipment :public Mediator,public GameScene
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
	CREATE_SCENE_FUNC(Equipment);
	void initInterests();
private:
	Equipment();
	virtual ~Equipment();
	void initButton();
private:
	UIWidget* ui;
	
};
#endif