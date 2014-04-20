#ifndef __UTIL_COCOSTUDIO__
#define __UTIL_COCOSTUDIO__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;
using namespace ui;

class UtilCocostudio
{
private:
	static UtilCocostudio* instance;
	UtilCocostudio();
	~UtilCocostudio();
public :
	static UtilCocostudio* getInstance();
	UIWidget* createWidgetFromJsonFile(const char *fileName,bool isCached=false);
	static void setLabelText(const char* name,const char* text,UIWidget* ui);
	static void setImageViewImage(const char* name,const char* path,UIWidget* ui);
	static void setUIComponentVisible(const char* name,bool isShow,UIWidget* ui);
	static void setButtonViewImage(const char* name,const char* path,UIWidget* ui);
	static void setLabelAtlasText(const char* name,const char* text,UIWidget* ui);
	static void setLabelAreaText(const char* name,const char* text,UIWidget* ui);
	static void setImageScale(const char* name,float scaleX,float scaleY,UIWidget* ui);
	static void setImageScale(const char* name,int width,int height,UIWidget* ui);
	static bool addEventRelease(cocos2d::CCObject* target,SEL_TouchEvent selector,const char* name,UIWidget* ui);
	static bool addEventTouchBegin(cocos2d::CCObject* target,SEL_TouchEvent selector,const char* name,UIWidget* ui);
	static void setComponentXY(float x,float y,const char* name,UIWidget* ui);
	static bool addEventTouchMove(cocos2d::CCObject* target,SEL_TouchEvent selector,const char* name,UIWidget* ui);
	static void setUIComponentColor(const char* name,int r,int g,int b,UIWidget* ui);
	static void setAllButtonTouchEnable(bool enable,UIWidget* ui);
	static void setTouchEnable(bool enable,const char* name,UIWidget* ui);
	static bool isTouchEnable(const char* name,UIWidget* ui);
	static void setButtonNormal(const char* name,UIWidget* ui);
	static void setButtonDisable(const char* name,UIWidget* ui);
	static UIWidget* UtilCocostudio::getWidget(const char* name,UIWidget* ui);
};

#endif