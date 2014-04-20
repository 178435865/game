#include "AppDelegate.h"
#include <vector>
#include <string>

#include "AppMacros.h"
#include "game/scene/login/LoginFacade.h"
#include "game/ui/equipment/EquipmentFacade.h"
#include "game/ui/missinfo/MissInfoFacade.h"
#include "game/ui/missinfo/MissInfoDetailFacade.h"
#include "mvc/patterns/Mediator.h"
#include "framework/manager/MgrScene.h"
#include "game/test/testScene.h"
#include "game/test/UIScene.h"
#include "framework/GameScene.h"
#include "game/test/testScene1.h"
#include "game/scene/login/LoginMediator.h"
#include "game/ui/equipment/EquipmentMediator.h"
#include "game/ui/missinfo/MissInfoMediator.h"
#include "game/ui/missinfo/MissInfoDetailMediator.h"

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* director = CCDirector::sharedDirector();
    CCEGLView* glView = CCEGLView::sharedOpenGLView();

    director->setOpenGLView(glView);
    
    CCSize size = director->getWinSize();

    // CCSet the design resolution
    glView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionFixedHeight);

	CCSize frameSize = glView->getFrameSize();
    
    vector<string> searchPath;

    // In this demo, we select resource according to the frame's height.
    // If the resource size is different from design resolution size, you need to set contentScaleFactor.
    // We use the ratio of resource's height to the height of design resolution,
    // this can make sure that the resource's height could fit for the height of design resolution.

    // if the frame's height is larger than the height of medium resource size, select large resource.
	//if (frameSize.height > mediumResource.size.height)
	//{
 //       searchPath.push_back(largeResource.directory);

 //       director->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
	//}
 //   // if the frame's height is larger than the height of small resource size, select medium resource.
 //   else if (frameSize.height > smallResource.size.height)
 //   {
 //       searchPath.push_back(mediumResource.directory);
 //       
 //       director->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
 //   }
 //   // if the frame's height is smaller than the height of medium resource size, select small resource.
	//else
 //   {
 //       searchPath.push_back(smallResource.directory);

 //       director->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
 //   }
 //   
 //   // set searching path
 //   FileUtils::getInstance()->setSearchPaths(searchPath);
	
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

	MissInfoFacade::getInstance();
	MissInfoDetailFacade::getInstance();
	EquipmentFacade::getInstance();
	LoginFacade::getInstance();

	REGISTER_SCENE_FUN(testScene);
	REGISTER_SCENE_FUN(testScene1);
	REGISTER_SCENE_FUN(MissInfoMediator);
	REGISTER_SCENE_FUN(MissInfoDetailMediator);
	REGISTER_SCENE_FUN(EquipmentMediator);
	REGISTER_SCENE_FUN(LoginMediator);
	REGISTER_UI(UIScene);
	MgrScene::getInstance()->runWidthScene("EquipmentMediator");
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
