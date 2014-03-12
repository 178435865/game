#ifndef _I_MODEL_
#define _I_MODEL_
#include "gameStd.h"

class IProxy;

class IModel
{
	public:
		virtual IProxy* getProxy(const string& name)=0;
		virtual void removeProxy(const string& name)=0;
		virtual void registerProxy(IProxy* proxy)=0;
		virtual bool hasProxy(const string& name)=0;
};
#endif