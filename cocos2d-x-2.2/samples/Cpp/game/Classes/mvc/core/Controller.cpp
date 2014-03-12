#include "mvc/core/Controller.h"
#include "mvc/interface/ICommand.h"
#include "mvc/patterns/Notification.h"

Controller* Controller::instance=NULL;
Controller::Controller()
{
	
}
Controller::~Controller()
{
	
}
Controller* Controller::getInstance()
{
	if(instance==NULL)
	{
		instance=new Controller();
	}
	return instance;
}
 void Controller::registerCommand(const string& name,const ICommand* comm)
 {
	if(m_mCommands.find(name)!=m_mCommands.end())
	{
		//’“µΩ
	}
	else
	{
		m_mCommands[name]=const_cast<ICommand*>(comm);
	}

 }
 void Controller::removeCommand(const string& name)
 {
	 map<string,ICommand*>::iterator it=m_mCommands.find(name);
	 if(it!=m_mCommands.end())
	 {
		 m_mCommands.erase(it);
	 }
 }
 bool Controller::hasCommand(const string& name)
 {
	if(m_mCommands.find(name)!=m_mCommands.end())
	{
		return true;
	}
	return false;

 }
 void Controller::executeCommand(Notification& noti)
 {
 	const string& name=noti.m_strNotiName;
	if(m_mCommands.find(name)!=m_mCommands.end())
	{
		ICommand* comm=m_mCommands[name];
		comm->execute(noti);
	}

 }
 ICommand* Controller::getCommand(const string& name)
 {
	 if(hasCommand(name))
	 {
		return m_mCommands[name];
	 }
	 return NULL;
 }