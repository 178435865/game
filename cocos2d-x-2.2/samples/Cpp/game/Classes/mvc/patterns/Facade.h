#ifndef _FACADE_
#define _FACADE_

#include "mvc/interface/IFacade.h"
#include "mvc/interface/INotifier.h"
#include "mvc/patterns/Notification.h"

class Notification;
class IView;
class IController;
class IModel;
class IProxy;
class ICommand;

class Facade :public IFacade,INotifier
{
	public :
		 void notifyMediator(Notification& noti);
		 void notifyCommand(Notification& noti);

		 void registerCommand(const string& notificationName,const ICommand* command);
		 void removeCommand(const string& notificationName);
		 bool hasCommand(const string& notificationName);
		 ICommand* getCommand(const string& name);

		 void registerProxy(IProxy* proxy);
		 void removeProxy(const string& name);
		 IProxy* getProxy(const string& name);

		 void registerMediator(IMediator* mediator);
		 IMediator* getMediator(const string& mediatorName);
		 bool hasMediator(const string& mediatorName);
		 IMediator* removeMediator(const string& mediatorName);
		 


		 void sendNotification(const string& name);
		 void sendNotification(const string& name,int type);
		 void sendNotification(const string& name,void* data);
		 void sendNotification(const string& name,void* data,int type);
		 void sendCommand(const string& name,void* data);
		 void sendCommand(const string& name);

		 virtual ~Facade();
		 static Facade* getInstance();
		

	protected:
		Facade();
		virtual void initFacade();
		virtual void initView();
		virtual void initModel();
		virtual void initController();

	protected:
		IController* m_pController;
		IView* m_pView;
		IModel* m_pModel;
		static Facade* instance;
};
#endif