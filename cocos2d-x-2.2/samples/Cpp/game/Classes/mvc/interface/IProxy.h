#ifndef _IPROXY_
#define _IPROXY_
#include "gameStd.h"

class IProxy
{
	public:
		virtual const string& getName()=0;
};
#endif