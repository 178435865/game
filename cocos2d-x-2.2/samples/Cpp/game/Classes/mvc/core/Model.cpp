#include "mvc/core/Model.h"
#include "mvc/interface/IProxy.h"

Model* Model::instance=NULL;

Model* Model::getInstance()
{
	if(instance==NULL)
	{
		instance=new Model();
	}
	return instance;
}

Model::Model()
{
	
}
Model::~Model()
{
	
}

IProxy* Model::getProxy(const string& name)
{
	map<string,IProxy*> ::iterator it=m_mModels.find(name);
	if(it!=m_mModels.end())
	{
		return it->second;
	}
	return NULL;
}
void Model::removeProxy(const string& name)
{
	map<string,IProxy*> ::iterator it=m_mModels.find(name);
	if(it!=m_mModels.end())
	{
		m_mModels.erase(it);
	}
}
void Model::registerProxy(IProxy* proxy)
{
	const string& name=proxy->getName();
	if(!hasProxy(name))
	{
		m_mModels[name]=const_cast<IProxy*>(proxy);
	}
}
bool Model::hasProxy(const string& name)
{
	if(m_mModels.find(name)!=m_mModels.end())
	{
		return true;
	}
	return false;
}