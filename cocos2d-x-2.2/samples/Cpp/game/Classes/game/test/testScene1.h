#ifndef _TEST_SCENE1_
#define _TEST_SCENE1_
#include "framework/GameScene.h"

class testScene1 :public GameScene
{
public:
	void onLoadResource();
	void onLoadUI();
	void onEnterScene();
	void onExitScene();
	void loadExtraData(void* data);
	bool init(){return true;};
	CREATE_SCENE_FUNC(testScene1);
	void menuCloseCallback(CCObject* obj);
private:
	CCMenu* pMenu;
};
#endif