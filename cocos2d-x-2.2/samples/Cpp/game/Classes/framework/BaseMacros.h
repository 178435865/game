#ifndef _BASE_MACROS_
#define _BASE_MACROS_
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class GameScene;
class MgrScene;
class MgrConfig;

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
MgrScene::getInstance()->registerScene(#_CLASS_,&_CLASS_::create);
#endif // !REGISTER_SCENE_FUN

//#ifndef LOAD_SCENE
//#define LOAD_SCENE(_CLASS_) \
//MgrScene::getInstance()->loadScene(_CLASS_)
//#endif

#ifndef REGISTER_UI
#define REGISTER_UI(_CLASS_) \
	MgrScene::getInstance()->registerUI(#_CLASS_,&_CLASS_::create);
#endif // !REGISTER_SCENE_FUN

//#ifndef LOAD_UI
//#define LOAD_UI(_CLASS_) \
//	MgrScene::getInstance()->loadUI(_CLASS_)
//#endif

#ifndef GET_INSTANCE
#define GET_INSTANCE(_CLASS_) \
	static _CLASS_* getInstance(){ \
	static _CLASS_* instance;	\
	if(instance==NULL){    \
	instance=new _CLASS_();}\
	return instance;}
#endif

#ifndef REGISTER_CONFIG
#define REGISTER_CONFIG(_CLASS_)	\
	MgrConfig::getInstance()->registerConfig(#_CLASS_,new _CLASS_());
#endif

#ifndef GET_CONFIG
#define GET_CONFIG(_CLASS_) \
	(_CLASS_*)MgrConfig::getInstance()->getConfig(#_CLASS_);
#endif


#endif // !_BASE_MACROS_
