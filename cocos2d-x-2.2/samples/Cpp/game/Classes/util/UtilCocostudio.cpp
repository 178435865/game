#include "util/UtilCocostudio.h"
UtilCocostudio* UtilCocostudio::instance=NULL;


UtilCocostudio::UtilCocostudio()
{
	
}
UtilCocostudio::~UtilCocostudio()
{
	if(instance)
	{
		delete instance;
		instance=NULL;
	}
}

UtilCocostudio* UtilCocostudio::getInstance()
{
	if(instance==NULL)
	{
		instance=new UtilCocostudio();
	}
	return instance;
}

UIWidget* UtilCocostudio::createWidgetFromJsonFile(const char *fileName,bool isCached)
{
	return GUIReader::shareReader()->widgetFromJsonFile(fileName);
}
 void UtilCocostudio::setLabelText(const char* name,const char* text,UIWidget* ui)
{
	{
		UILabel* component=dynamic_cast<UILabel*>(getWidget(name,ui));
		if(component)
		{
			component->setText(text);
			return ;
		}
	}
	
	/*{
		UITextArea* component=dynamic_cast<UITextArea*>(getWidget(name,ui));
		if(component)
		{
			component->setText(text);
		}
	}*/
	

}
 void UtilCocostudio::setLabelAtlasText(const char* name,const char* text,UIWidget* ui)
 {
	 UILabelAtlas* component=dynamic_cast<UILabelAtlas*>(getWidget(name,ui));
	 if(component)
	 {
		 component->setStringValue(text);
	 }
 }
 void UtilCocostudio::setLabelAreaText(const char* name,const char* text,UIWidget* ui)
 {
	/* UITextArea* component=dynamic_cast<UITextArea*>(getWidget(name,ui));
	 if(component)
	 {
		 component->setText(text);
	 }*/
 }
 void UtilCocostudio::setImageScale(const char* name,float scaleX,float scaleY,UIWidget* ui)
 {
	 UIImageView* component=dynamic_cast<UIImageView*>(getWidget(name,ui));
	 if(component)
	 {
		 component->setScaleX(scaleX);
		 component->setScaleY(scaleY);
	 }
 }
 void UtilCocostudio::setImageScale(const char* name,int width,int height,UIWidget* ui)
 {
	 UIImageView* component=dynamic_cast<UIImageView*>(getWidget(name,ui));
	 if(component)
	 {
		 float currentWidth=component->getContentSize().width;
		 float currentHeight=component->getContentSize().height;
		 float scaleX=(float)width/currentWidth;
		 float scaleY=(float)height/currentHeight;
		 component->setScaleX(scaleX);
		 component->setScaleY(scaleY);
	 }
 }
 void UtilCocostudio::setImageViewImage(const char* name,const char* path,UIWidget* ui)
 {
	 UIImageView* component=dynamic_cast<UIImageView*>(getWidget(name,ui));
	 if(component)
	 {
		component->loadTexture(path,UI_TEX_TYPE_PLIST);
	 }
	
 }
 void UtilCocostudio::setButtonViewImage(const char* name,const char* path,UIWidget* ui)
 {
	 UIButton* component=dynamic_cast<UIButton*>(getWidget(name,ui));
	 if(component)
	 {
		 component->loadTextureNormal(path,UI_TEX_TYPE_PLIST);
		 component->loadTexturePressed(path,UI_TEX_TYPE_PLIST);
	 }

 }
 void UtilCocostudio::setUIComponentVisible(const char* name,bool isShow,UIWidget* ui)
 {
	
	UIWidget* widget=getWidget(name,ui);
	if(widget)
	{
		widget->setVisible(isShow);
	}
 }
 bool UtilCocostudio::addEventRelease(cocos2d::CCObject* target,SEL_TouchEvent selector,const char* name,UIWidget* ui)
 {
	 UIWidget* widget=getWidget(name,ui);
	 if(widget)
	 {
		 widget->addTouchEventListener(target,selector);
		 return true;
	 }
	return false;
 }
 bool UtilCocostudio::addEventTouchBegin(cocos2d::CCObject* target,SEL_TouchEvent selector,const char* name,UIWidget* ui)
 {
	 UIWidget* widget=getWidget(name,ui);
	 if(widget)
	 {
		 widget->addTouchEventListener(target,selector);
		 return true;
	 }
	 return false;
 }
 bool UtilCocostudio::addEventTouchMove(cocos2d::CCObject* target,SEL_TouchEvent selector,const char* name,UIWidget* ui)
 {
	 UIWidget* widget=getWidget(name,ui);
	 if(widget)
	 {
		 widget->addTouchEventListener(target,selector);
		 return true;
	 }
	 return false;
 }
 void UtilCocostudio::setUIComponentColor(const char* name,int r,int g,int b,UIWidget* ui)
 {
	 UIWidget* widget=getWidget(name,ui);
	 if(widget)
	 {
		 widget->setColor(ccc3(r,g,b));
	 }
 }
 void UtilCocostudio::setAllButtonTouchEnable(bool enable,UIWidget* ui)
 {
	 CCArray* arr=ui->getChildren();
	 int count=arr->count();
	 for(int i=0;i<count;++i)
	 {
		 cocos2d::CCObject* obj=arr->objectAtIndex(i);
		 UIButton* button=dynamic_cast<UIButton*>(obj);
		 if(button)
		 {
			 button->setTouchEnabled(enable);
		 }
		 UIWidget* widget=dynamic_cast<UIWidget*>(obj);
		 if(widget)
		 {
			CCArray* tempArr=widget->getChildren();
			if(tempArr->count()>0)
			{
				setAllButtonTouchEnable(enable,widget);
			}

		 }

	 }
 }
 void UtilCocostudio::setComponentXY(float x,float y,const char* name,UIWidget* ui)
 {
	 UIWidget* component=dynamic_cast<UIWidget*>(getWidget(name,ui));
	 if(component)
	 {
		 component->setPosition(ccp(x,y));
	 }
 }
 void UtilCocostudio::setTouchEnable(bool enable,const char* name,UIWidget* ui)
 {
	 UIWidget* component=dynamic_cast<UIWidget*>(getWidget(name,ui));
	 if(component)
	 {
		 component->setTouchEnabled(enable);
		/* if(!enable)
		 {
			 component->disable();
		 }
		 else
		 {
			component->active();
		 }*/
		
	 }
	 else
	 {
		throw;
	 }
	 
 }
 bool UtilCocostudio::isTouchEnable(const char* name,UIWidget* ui)
 {
	 UIWidget* component=dynamic_cast<UIWidget*>(getWidget(name,ui));
	 return component->isTouchEnabled();
	 /*if(component)
	 {
	 return component->isActive();
	 }
	 else
	 {
	 throw;
	 }
	 return false;*/
 }
 void UtilCocostudio::setButtonDisable(const char* name,UIWidget* ui)
 {
	/* UIButton* component=dynamic_cast<UIButton*>(getWidget(name,ui));
	 if(component)
	 {
		 component->initPressState(WidgetStateDisabled);
	 }
	 else
	 {
		 throw;
	 }*/

 }
 void UtilCocostudio::setButtonNormal(const char* name,UIWidget* ui)
 {
	/* UIButton* component=dynamic_cast<UIButton*>(getWidget(name,ui));
	 if(component)
	 {
		 component->initPressState(WidgetStateNormal);
	 }
	 else
	 {
		 throw;
	 }*/


 }

 UIWidget* UtilCocostudio::getWidget(const char* name,UIWidget* ui)
 {
	  UIWidget* widget=ui->getChildByName(name);
	  if(widget)
	  {
		  return widget;
	  }
	  CCArray* arr=ui->getChildren();
	  CCObject* obj=NULL;
	CCARRAY_FOREACH(arr,obj)
	{
		if(obj)
		{
			widget=dynamic_cast<UIWidget*>(obj);
			if(widget)
			{
				return getWidget(name,widget);
			}
		}
	}
	return NULL;
 }
