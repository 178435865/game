#include "util/UtilView.h"
#include "AppMacros.h"
#include "cocos2d.h"
USING_NS_CC;

float UtilView::getViewDistanceX()
{
	CCSize resourceSize=mediumResource.size;
	CCSize visibleSize=CCDirector::sharedDirector()->getVisibleSize();

	int resourceWidth=resourceSize.width;
	int curViewWidth=visibleSize.width;
	return (curViewWidth-resourceWidth)/2;
}