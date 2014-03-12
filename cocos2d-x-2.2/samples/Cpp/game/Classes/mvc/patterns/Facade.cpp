#include "mvc/patterns/Facade.h"
#include "mvc/interface/IController.h"
#include "mvc/interface/IView.h"
#include "mvc/interface/IModel.h"
#include "mvc/patterns/Notification.h"

#include "mvc/core/View.h"
#include "mvc/core/Controller.h"
#include "mvc/core/Model.h"

Facade* Facade::instance=NULL;

Facade::Facade()
{
	m_pView=NULL;
	m_pController=NULL;
	m_pModel=NULL;
	initFacade();	
}

Facade::~Facade()
{

}
Facade* Facade::getInstance()
{
	if(instance==NULL)
	{
		instance=new Facade();
	}
	return instance;
}

void Facade::notifyMediator(Notification& noti)
{
	m_pView->notifyMediator(noti);
}
void Facade::notifyCommand(Notification& noti)
{
	m_pController->executeCommand(noti);
}

void Facade::registerCommand(const string& notificationName,const ICommand* command)
{
	m_pController->registerCommand(notificationName,command);
}
void Facade::removeCommand(const string& notificationName)
{
	m_pController->removeCommand(notificationName);
}
bool Facade::hasCommand(const string& notificationName)
{
	return m_pController->hasCommand(notificationName);
}
ICommand* Facade::getCommand(const string& name)
{
	return m_pController->getCommand(name);
}

void Facade::registerMediator(IMediator* mediator)
{
	m_pView->registerMediator(mediator);
}
IMediator* Facade::getMediator(const string& mediatorName)
{
	return m_pView->getMediator(mediatorName);
}
bool Facade::hasMediator(const string& mediatorName)
{
	return m_pView->hasMediator(mediatorName);
}
IMediator* Facade::removeMediator(const string& mediatorName)
{
	return m_pView->removeMediator(mediatorName);
}

void Facade::registerProxy(IProxy* proxy)
{
	m_pModel->registerProxy(proxy);
}
void Facade::removeProxy(const string& name)
{
	m_pModel->removeProxy(name);
}
IProxy* Facade::getProxy(const string& name)
{
	return m_pModel->getProxy(name);
}

void Facade::sendNotification(const string& name)
{
	sendNotification(name,NULL,NOTIFIER_ALL);
}
void Facade::sendNotification(const string& name,int type)
{
	sendNotification(name,NULL,type);
}
void Facade::sendNotification(const string& name,void* data)
{
	sendNotification(name,data,NOTIFIER_ALL);
}
void Facade::sendNotification(const string& name,void* data,int type)
{
	Notification noti(name,data,type);
	notifyMediator(noti);
}
void Facade::sendCommand(const string& name,void* data)
{
	Notification noti(name,data,NOTIFIER_ALL);
	notifyCommand(noti);
}
void Facade::sendCommand(const string& name)
{
	sendCommand(name,NULL);
}
void Facade::initFacade(){
	initView();
	initController();
	initModel();
};
void Facade::initView()
{
	if(m_pView==NULL)
	{
		m_pView=View::getInstance();
	}
	
}
void Facade::initModel()
{
	if(m_pModel==NULL)
	{
		m_pModel=Model::getInstance();
	}
}
void Facade::initController()
{
	if(m_pController==NULL)
	{
		m_pController=Controller::getInstance();
	}
}
