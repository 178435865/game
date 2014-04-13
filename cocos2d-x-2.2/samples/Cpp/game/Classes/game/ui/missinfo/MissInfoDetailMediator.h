#ifndef _MISSINFODETAIL_MEDIATOR_
#define _MISSINFODETAIL_MEDIATOR_
#include "mvc/patterns/Mediator.h"
#include "framework/GameScene.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "framework/BaseMacros.h"
USING_NS_CC_EXT;
USING_NS_CC;


class MissInfoDetailMediator :public Mediator,public GameScene
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
	CREATE_SCENE_FUNC(MissInfoDetailMediator);
	void initInterests();
	const char * infoDetailName;
private:
	MissInfoDetailMediator();
	virtual ~MissInfoDetailMediator();
	void initButton();
private:
	UIWidget* ui;
	UIWidget* downmenuToolbarUi;

	
};
#endif