#ifndef _IVIEW_
#define _IVIEW_
#include "gameStd.h"

class IMediator;
class Notification;

class IView 
{
	public:
		 virtual void registerMediator(IMediator* mediator)=0;
		 virtual IMediator* getMediator(const string& mediatorName)=0;
		 virtual bool hasMediator(const string& mediatorName)=0;
		 virtual IMediator* removeMediator(const string& mediatorName)=0;
		 virtual void notifyMediator(Notification& noti)=0;

};

#endif // !_IVIEW_
