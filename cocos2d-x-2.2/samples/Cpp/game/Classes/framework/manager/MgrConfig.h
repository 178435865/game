#ifndef _MANAGER_CONFIG_
#define _MANAGER_CONFIG_
#include "framework/BaseMacros.h"
#include "game/config/ConfigGraph.h"
#include "util/Util.h"

class IConfig;

class MgrConfig
{
public:
	GET_INSTANCE(MgrConfig);
	void registerConfig(const string& name,IConfig* config);
	void unRegisterConfig(const string& name);
	IConfig* getConfig(const string& name);
	void init();
private:
	MgrConfig(){};
	virtual ~MgrConfig(){};
private:
	map<string,IConfig*> m_mConfigs;
};
#endif