#ifndef __MEDIATOR__
#define __MEDIATOR__
#include <vector>
#include <string>
using namespace std;
#include "mvc/interface/IMediator.h"
#include "mvc/patterns/Notifier.h"


class Notification;

class Mediator:public IMediator,public Notifier
{
	public:
		bool init();
		Mediator(const string& name);
		virtual ~Mediator();
		const string& getName();
		virtual void handleNotification(Notification& noti);
		const vector<string>& getInterests();
	protected:
		string m_strName;
		vector<string> m_vInterests;
};

#endif