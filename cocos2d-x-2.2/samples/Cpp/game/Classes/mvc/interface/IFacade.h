#ifndef __I_FACADE__
#define __I_FACADE__
#include "gameStd.h"

class IMediator;
class Notification;
class ICommand;
class IProxy;

class IFacade
{
	public:
		virtual void notifyMediator(Notification& noti)=0;
		virtual void notifyCommand(Notification& noti)=0;

		virtual void registerCommand(const string& notificationName,const ICommand* command)=0;
		virtual void removeCommand(const string& notificationName)=0;
		virtual bool hasCommand(const string& notificationName)=0;
		virtual ICommand* getCommand(const string& name)=0;

		virtual void registerProxy(IProxy* proxy)=0;
		virtual IProxy* getProxy(const string& name)=0;
		virtual void removeProxy(const string& name)=0;

		virtual void registerMediator(IMediator* mediator)=0;
		virtual IMediator* getMediator(const string& mediatorName)=0;
		virtual bool hasMediator(const string& mediatorName)=0;
		virtual IMediator* removeMediator(const string& mediatorName)=0;
		
protected:
		virtual void initModel()=0;
		virtual void initController()=0;
		virtual void initView()=0;

};
#endif