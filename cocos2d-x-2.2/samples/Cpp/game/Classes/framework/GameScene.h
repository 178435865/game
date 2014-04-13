#ifndef _GAME_SCENE_
#define _GAME_SCENE_
#include "cocos2d.h"
#include "framework/BaseMacros.h"
#include "framework/manager/MgrScene.h"
#include "mvc/patterns/Mediator.h"
USING_NS_CC;
using namespace std;

class GameScene :public CCScene
{
	public:
		virtual void onLoadResource()=0;
		virtual void onLoadUI()=0;
		virtual void onEnterScene()=0;
		virtual void onExitScene()=0;
		virtual void loadExtraData(void* data)=0;
		virtual bool init()=0;
		
		virtual void onloadResourceCompleted();
		virtual void onEnter();
		virtual void onExit();
		void setClassName(const string& name);
		const vector<string>& getResources();
		const string& getClassName();
		bool getIsLoad();
		void setIsLoad(bool ret);
		GameScene();
		virtual ~GameScene();
	protected:
		bool m_bIsLoaded;
		vector<string> m_vResources;
		string m_strClassName;
};
#endif