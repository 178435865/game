#ifndef _EQUIPMENT_VO_
#define _EQUIPMENT_VO_
#include "cocos2d.h"
USING_NS_CC;

class EquipmentVO
{
	public:
		CC_SYNTHESIZE(string,userName,UserName);
		CC_SYNTHESIZE(string,userPassword,UserPassword);
};
#endif