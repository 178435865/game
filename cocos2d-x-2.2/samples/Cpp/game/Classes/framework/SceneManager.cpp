#include "framework/SceneManager.h"
#include "framework/GameScene.h"
#include "util/Util.h"

SceneManager* SceneManager::instance=NULL;
SceneManager* SceneManager::getInstance()
{
	if(instance==NULL)
	{
		instance=new SceneManager();
		CCDirector::sharedDirector()->runWithScene(instance);
	}
	return instance;
}
void SceneManager::runUIScene(const string& name,void* extraData)
{
	GameScene* gs=NULL;

	int size=m_vRunningUIScenes.size();
	int i=1;
	for(vector<GameScene*>::iterator it=m_vRunningUIScenes.begin();it!=m_vRunningUIScenes.end();++it)
	{
		gs=(*it);
		if(gs&&StringHelper::isEqual(name,gs->getClassName()))
		{
			if(i==size)
			{
				gs->loadExtraData(extraData);
				return ;
			}
			else
			{
				m_vRunningUIScenes.erase(it);
				gs->onExit();
				pushScene(gs,extraData);
				gs->release();
				return ;
			}
		}
		++i;
	}

	gs=loadUI(name);
	if(gs)
	{
		runUIScene(gs,extraData);
	}
}
void SceneManager::runWidthScene(const string& name,void* extraData)
{
	GameScene* gs=NULL;

	int size=m_vRunningScenes.size();
	int i=1;
	for(vector<GameScene*>::iterator it=m_vRunningScenes.begin();it!=m_vRunningScenes.end();++it)
	{
		gs=(*it);
		if(gs&&StringHelper::isEqual(name,gs->getClassName()))
		{
			if(i==size)
			{
				gs->loadExtraData(extraData);
				return ;
			}
			else
			{
				m_vRunningScenes.erase(it);
				gs->onExit();
				pushScene(gs,extraData);
				gs->release();
				return ;
			}
		}
		++i;
	}

	gs=loadScene(name);
	if(gs)
	{
		pushScene(gs,extraData);
	}
}
void SceneManager::replaceScene(const string& name,void* extraData)
{
	GameScene* gs=NULL;

	int size=m_vRunningScenes.size();
	int i=1;
	for(vector<GameScene*>::iterator it=m_vRunningScenes.begin();it!=m_vRunningScenes.end();++it)
	{
		gs=(*it);
		if(gs&&StringHelper::isEqual(name,gs->getClassName()))
		{
			if(i==size)
			{
				gs->loadExtraData(extraData);
				return ;
			}
			else
			{
				m_vRunningScenes.erase(it);
				gs->onExit();
				pushScene(gs,extraData);
				gs->release();
				return ;
			}
		}
		++i;
	}

	gs=loadScene(name);
	if(gs)
	{
		replaceScene(gs,extraData);
	}
}
void SceneManager::pushScene(GameScene* gs,void* extraData)
{
	SCENESWITCH ss;
	ss.m_bIsBlockSwitch=true;
	ss.m_iType=eSceneSwitchPush;
	ss.m_pNextScene=gs;
	gs->retain();
	ss.m_pExtraData=extraData;
	if(gs->getIsLoad()||isLoadedResource(gs))
	{
		ss.m_bIsBlockSwitch=false;
	}	
	m_lSceneSwitchQueue.push_back(ss);
}
void SceneManager::replaceScene(GameScene* gs,void* extraData)
{
	SCENESWITCH ss;
	ss.m_bIsBlockSwitch=true;
	ss.m_iType=eSceneSwitchReplace;
	ss.m_pNextScene=gs;
	gs->retain();
	ss.m_pExtraData=extraData;
	if(gs->getIsLoad()||isLoadedResource(gs))
	{
		ss.m_bIsBlockSwitch=false;
	}	
	m_lSceneSwitchQueue.push_back(ss);
}
void SceneManager::popScene()
{
	SCENESWITCH ss;
	ss.m_bIsBlockSwitch=false;
	ss.m_iType=eSceneSwitchPop;
	ss.m_pExtraData=NULL;
	ss.m_pNextScene=NULL;
	m_lSceneSwitchQueue.push_back(ss);
}
void SceneManager::popScene(GameScene* gs)
{
	SCENESWITCH ss;
	ss.m_bIsBlockSwitch=false;
	ss.m_iType=eSceneSwitchPop;
	ss.m_pExtraData=NULL;
	ss.m_pNextScene=gs;
	m_lSceneSwitchQueue.push_back(ss);
}
void SceneManager::runUIScene(GameScene* gs,void* extraData)
{
	UISCENESWITCH ss;
	ss.m_bIsBlockSwitch=true;
	ss.m_iType=eSceneSwitchReplace;
	ss.m_pNextUIScene=gs;
	gs->retain();
	ss.m_pExtraData=extraData;
	if(gs->getIsLoad()||isLoadedResource(gs))
	{
		ss.m_bIsBlockSwitch=false;
	}	
	m_lUISceneSwitchQueue.push_back(ss);
}
void SceneManager::popUIScene(GameScene* gs)
{
	UISCENESWITCH ss;
	ss.m_bIsBlockSwitch=false;
	ss.m_iType=eUISceneSwitchPop;
	ss.m_pNextUIScene=gs;
	ss.m_pExtraData=NULL;
	m_lUISceneSwitchQueue.push_back(ss);
	
}
void SceneManager::popAllUIScene()
{
	int size=m_vRunningUIScenes.size();
	for(int i=0;i<size;++i)
	{
		GameScene* gs=m_vRunningUIScenes[i];
		popUIScene(gs);
	}
}
bool SceneManager::isRunningUIScene(const string& name)
{
	for(vector<GameScene*>::iterator it=m_vRunningUIScenes.begin();it!=m_vRunningUIScenes.end();++it)
	{
		GameScene* gs=(*it);
		if(StringHelper::isEqual(gs->getClassName(),name))
		{
			return true;
		}
	}
	return false;
}
void SceneManager::visit()
{
	mainLoop();
}
GameScene* SceneManager::getRunningScene()
{
	if(m_vRunningScenes.empty())
	{
		return NULL;
	}
	return m_vRunningScenes.back();
}
void SceneManager::registerScene(const string& name,FnCreate fc)
{
	if(m_mFunSceneCreate.find(name)==m_mFunSceneCreate.end())
	{
		m_mFunSceneCreate[name]=fc;
	}
}
GameScene* SceneManager::loadScene(const string& name)
{


	if(m_mFunSceneCreate.find(name)!=m_mFunSceneCreate.end())
	{
		GameScene* gs=m_mFunSceneCreate[name]();
		if(gs)
		{
			gs->setClassName(name);
		}
		return gs;
	}
	return NULL;
}
void SceneManager::registerUI(const string& name,FnCreate fc)
{
	if(m_mFunUICreate.find(name)==m_mFunUICreate.end())
	{
		m_mFunUICreate[name]=fc;
	}
}
GameScene* SceneManager::loadUI(const string& name)
{
	if(m_mFunUICreate.find(name)!=m_mFunUICreate.end())
	{
		GameScene* gs=m_mFunUICreate[name]();
		if(gs)
		{
			gs->setClassName(name);
		}
		
		return gs;
	}
	return NULL;
}
SceneManager::SceneManager()
{

}
SceneManager::~SceneManager()
{

}
void SceneManager::mainLoop()
{
	//swtich scene
	do 
	{
		CC_BREAK_IF(m_lSceneSwitchQueue.empty());
		SCENESWITCH& ss=m_lSceneSwitchQueue.front();
		CC_BREAK_IF(ss.m_bIsBlockSwitch);
		handleSwitchScene(ss);
		m_lSceneSwitchQueue.pop_front();

	} while (0);

	//swtich ui scene;
	do 
	{
		CC_BREAK_IF(m_lUISceneSwitchQueue.empty());
		UISCENESWITCH& uiss=m_lUISceneSwitchQueue.front();
		CC_BREAK_IF(uiss.m_bIsBlockSwitch);
		handleUISwitchScene(uiss);
		m_lUISceneSwitchQueue.pop_front();

	} while (0);


	// visit scene
	if(!m_vRunningScenes.empty())
	{
		(*m_vRunningScenes.back()).visit();
	}

	//visit ui
	int size=m_vRunningUIScenes.size();
	for(int i=0;i<size;++i)
	{
		GameScene* gs=m_vRunningUIScenes[i];
		if(gs)
		{
			gs->visit();
		}
	}
}
void SceneManager::setNextScene()
{

}
bool SceneManager::isLoadedResource(GameScene* gs)
{
	gs->onloadResourceCompleted();
	return true;
}
void SceneManager::handleSwitchScene(SCENESWITCH& ss)
{
	int type=ss.m_iType;
	switch (type)
	{
		case eSceneSwitchPop:
		{
			GameScene* gs=ss.m_pNextScene;
			if(gs==NULL)
			{
				gs=m_vRunningScenes.back();
				gs->onExit();
				gs->release();
				m_vRunningScenes.pop_back();
			}
			else
			{
				for(vector<GameScene*>::iterator it=m_vRunningScenes.begin();it!=m_vRunningScenes.end();++it)
				{
					if(*it==gs)
					{
						m_vRunningScenes.erase(it);
						gs->onExit();
						gs->release();
						break;
					}
				}
			}
			
			break;
		}
		case eSceneSwitchPush:
		{
			void* data= ss.m_pExtraData;
			GameScene* gs=ss.m_pNextScene;
			gs->onEnterTransitionDidFinish();
			gs->onEnter();
			gs->loadExtraData(data);
			m_vRunningScenes.push_back(gs);
			break;
		}
		case eSceneSwitchReplace:
		{
			GameScene* gs=m_vRunningScenes.back();
			gs->onExit();
			gs->release();
			gs=ss.m_pNextScene;
			void* data= ss.m_pExtraData;
			gs->loadExtraData(data);
			gs->onEnter();
			m_vRunningScenes.pop_back();
			m_vRunningScenes.push_back(gs);
			break;
		}
	default:
		break;
	}
}
void SceneManager::handleUISwitchScene(UISCENESWITCH& ss)
{
	int type=ss.m_iType;
	switch (type)
	{
		case eUISceneSwitchPop:
		{
			GameScene* gs=m_vRunningUIScenes.back();
			gs->onExit();
			gs->release();
			m_vRunningUIScenes.pop_back();
			break;
		}
		case eUISceneSwitchPush:
		{
			void* data= ss.m_pExtraData;
			GameScene* gs=ss.m_pNextUIScene;
			gs->loadExtraData(data);
			gs->onEnter();
			m_vRunningUIScenes.push_back(gs);
			break;
		}
		case eUISceneSwitchReplace:
		{
			GameScene* gs=m_vRunningUIScenes.back();
			gs->onExit();
			gs->release();
			gs=ss.m_pNextUIScene;
			void* data= ss.m_pExtraData;
			gs->loadExtraData(data);
			gs->onEnter();
			m_vRunningUIScenes.pop_back();
			m_vRunningUIScenes.push_back(gs);
			break;
		}
	default:
		break;
	}
}