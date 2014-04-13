#ifndef _SCENE_MANAGER_
#define _SCENE_MANAGER_
#include "cocos2d.h"
#include "framework/BaseMacros.h"
USING_NS_CC;
using namespace std;

class GameScene;

enum SceneSwitchType
{
	eSceneSwitchReplace,
	eSceneSwitchPush,
	eSceneSwitchPop
};

enum UISceneSwitchType
{
	eUISceneSwitchPush,
	eUISceneSwitchReplace,
	eUISceneSwitchPop,
};

struct SCENESWITCH
{
	GameScene* m_pNextScene;
	int m_iType;
	void* m_pExtraData;
	bool m_bIsBlockSwitch;
};
struct UISCENESWITCH
{
	GameScene* m_pNextUIScene;
	int m_iType;
	void* m_pExtraData;
	bool m_bIsBlockSwitch;
};


class MgrScene:public CCScene
{
	public:
		static MgrScene* getInstance();
		void runUIScene(const string& name,void* extraData=NULL);
		void runWidthScene(const string& name,void* extraData=NULL);
		void replaceScene(const string& name,void* extraData=NULL);
		void runUIScene(GameScene* gs,void* extraData=NULL);
		void pushScene(GameScene* gs,void* extraData=NULL);
		void replaceScene(GameScene* gs,void* extraData=NULL);

		void popScene();
		void popScene(GameScene* gs);
		void popUIScene(GameScene* gs);
		void popAllUIScene();
		bool isRunningUIScene(const string& name);
		virtual void visit();
		GameScene* getRunningScene();
		void registerScene(const string& name,FnCreate fc);
		GameScene* loadScene(const string& name);
		void registerUI(const string& name,FnCreate fc);
		GameScene* loadUI(const string& name);

	private:
		MgrScene();
		~MgrScene();
		void mainLoop();
		void setNextScene();
		bool isLoadedResource(GameScene* gs);
		void handleSwitchScene(SCENESWITCH& ss);
		void handleUISwitchScene(UISCENESWITCH& ss);
		

	private:
		list<SCENESWITCH> m_lSceneSwitchQueue;
		list<UISCENESWITCH> m_lUISceneSwitchQueue;
		vector<GameScene*> m_vRunningUIScenes;
		vector<GameScene*> m_vRunningScenes;
		static MgrScene* instance;
		map<string,FnCreate> m_mFunSceneCreate;
		map<string,FnCreate> m_mFunUICreate;

};
#endif