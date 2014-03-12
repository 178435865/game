#ifndef _UI_SCENE_
#define _UI_SCENE_
#include "framework/GameScene.h"

class UIScene :public GameScene
{
public:
	void onLoadResource();
	void onLoadUI();
	void onEnterScene();
	void onExitScene();
	void loadExtraData(void* data);
	bool init(){return true;};
	CREATE_SCENE_FUNC(UIScene);
	void menuCloseCallback(CCObject* obj);
private:
	CCMenu* pMenu;
};
#endif