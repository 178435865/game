#ifndef _TEST_SCENE_
#define _TEST_SCENE_
#include "framework/GameScene.h"

class testScene :public GameScene
{
public:
	void onLoadResource();
	void onLoadUI();
	void onEnterScene();
	void onExitScene();
	void loadExtraData(void* data);
	bool init(){return true;};
	CREATE_SCENE_FUNC(testScene);
	void menuCloseCallback(CCObject* obj);
private:
	CCMenu* pMenu;
};
#endif