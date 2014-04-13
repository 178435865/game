#ifndef _LOGIN_VO_
#define _LOGIN_VO_
#include "cocos2d.h"
USING_NS_CC;

class LoginVO
{
	public:
		CC_SYNTHESIZE(string,userName,UserName);
		CC_SYNTHESIZE(string,userPassword,UserPassword);
};
#endif