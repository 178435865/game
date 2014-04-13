#include "framework/manager/MgrConfig.h"



void MgrConfig::registerConfig(const string& name,IConfig* config)
{
	if(m_mConfigs.find(name)!=m_mConfigs.end())
	{
		throw "config error";
	}
	m_mConfigs[name]=config;
}
void MgrConfig::unRegisterConfig(const string& name)
{
	if(m_mConfigs.find(name)!=m_mConfigs.end())
	{
		m_mConfigs.erase(name);
	}
}
void MgrConfig::init()
{
	REGISTER_CONFIG(ConfigGraph);
	for(map<string,IConfig*>::iterator it=m_mConfigs.begin();it!=m_mConfigs.end();++it)
	{
		IConfig* config=(*it).second;
		config->loadConfig();
	}
}
IConfig* MgrConfig::getConfig(const string& name)
{
	return m_mConfigs[name];
}