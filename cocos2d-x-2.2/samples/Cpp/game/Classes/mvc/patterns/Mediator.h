#ifndef __MEDIATOR__
#define __MEDIATOR__
#include <vector>
#include <string>
using namespace std;
#include "mvc/interface/IMediator.h"
#include "mvc/patterns/Notifier.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "util/Util.h"
using namespace ui;

class Notification;

class Mediator:public IMediator,public Notifier
{
	public:
		virtual bool init();
		Mediator(const string& name);
		virtual ~Mediator();
		const string& getName();
		const vector<string>& getInterests();
	protected:
		string m_strName;
		vector<string> m_vInterests;
};

#endif