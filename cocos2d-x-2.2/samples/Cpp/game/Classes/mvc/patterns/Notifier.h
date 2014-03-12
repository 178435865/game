#ifndef _NOTIFIER_
#define _NOTIFIER_
#include "mvc/interface/INotifier.h"
class IFacade;

class Notifier :public INotifier
{
public:
	void sendNotification(const string& name);
	void sendNotification(const string& name,int type);
	void sendNotification(const string& name,void* data);
	void sendNotification(const string& name,void* data,int type);
	void sendCommand(const string& name,void* data);
	void sendCommand(const string& name);
	IFacade* getFacade();
};
#endif
