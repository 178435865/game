#ifndef _ICONFIG_
#define _ICONFIG_
#include "util/Util.h"
#define GONFIG_PATH "config/"
class IConfig
{
public:
	virtual void loadConfig()=0;
};

#endif

