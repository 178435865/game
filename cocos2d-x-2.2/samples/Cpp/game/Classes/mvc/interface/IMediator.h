#ifndef __I_MEDIATOR__
#define __I_MEDIATOR__
#include "gameStd.h"

class Notification;

class IMediator
{
	public:
		virtual const string& getName()=0;
		virtual void handleNotification(Notification& noti)=0;
		virtual void initInterests()=0;
		virtual const vector<string>& getInterests()=0;
		virtual ~IMediator(){};
};

#endif