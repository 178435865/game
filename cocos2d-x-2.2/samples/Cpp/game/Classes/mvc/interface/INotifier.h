#ifndef _I_NOTIFIER_
#define _I_NOTIFIER_

#include "gameStd.h"

class INotifier
{
	public:
		enum ENUM_NOTIFIER
		{
			NOTIFIER_SINGLE,
			NOTIFIER_ALL
		};
		virtual void sendNotification(const string& name)=0;
		virtual void sendNotification(const string& name,int type)=0;
		virtual void sendNotification(const string& name,void* data)=0;
		virtual void sendNotification(const string& name,void* data,int type)=0;

		virtual void sendCommand(const string& name,void* data)=0;
		virtual void sendCommand(const string& name)=0;
};
#endif