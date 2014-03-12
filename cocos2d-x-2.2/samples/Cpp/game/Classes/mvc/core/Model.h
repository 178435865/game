#ifndef _MVC_MODEL_
#define _MVC_MODEL_
#include "mvc/interface/IModel.h"
#include "gameStd.h"

class IProxy;

class Model :public IModel
{
public:
	static Model* getInstance();
	IProxy* getProxy(const string& name);
	void removeProxy(const string& name);
	void registerProxy(IProxy* proxy);
	bool hasProxy(const string& name);
protected:
	Model();
	virtual ~Model();
protected:
	static Model* instance;
	map<string,IProxy*> m_mModels;
};
#endif
