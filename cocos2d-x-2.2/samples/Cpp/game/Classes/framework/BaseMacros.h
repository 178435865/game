#ifndef _BASE_MACROS_
#define _BASE_MACROS_
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class GameScene;
class SceneManager;

typedef GameScene* (*FnCreate)();

#ifndef CREATE_SCENE_FUNC
#define CREATE_SCENE_FUNC(_CLASS_) \
	static GameScene* create() { \
	GameScene* gs=new _CLASS_; \
	if(gs&&gs->init()) \
	{ gs->autorelease();} \
	else{ delete gs; gs=NULL;} \
	return gs; } 
#endif

#ifndef REGISTER_SCENE_FUN
#define REGISTER_SCENE_FUN(_CLASS_) \
SceneManager::getInstance()->registerScene(#_CLASS_,&_CLASS_::create)
#endif // !REGISTER_SCENE_FUN

//#ifndef LOAD_SCENE
//#define LOAD_SCENE(_CLASS_) \
//SceneManager::getInstance()->loadScene(_CLASS_)
//#endif

#ifndef REGISTER_UI
#define REGISTER_UI(_CLASS_) \
	SceneManager::getInstance()->registerUI(#_CLASS_,&_CLASS_::create)
#endif // !REGISTER_SCENE_FUN

//#ifndef LOAD_UI
//#define LOAD_UI(_CLASS_) \
//	SceneManager::getInstance()->loadUI(_CLASS_)
//#endif


#endif // !_BASE_MACROS_
