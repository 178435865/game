#ifndef _CONTROLLER_
#define _CONTROLLER_
#include "mvc/interface/IController.h"
#include "gameStd.h"

class ICommand;

class Controller:public IController
{
public:	
		static Controller* getInstance();
		virtual void registerCommand(const string& name,const ICommand* comm);
		virtual void removeCommand(const string& name);
		virtual bool hasCommand(const string& name);
		virtual void executeCommand(Notification& noti);
		virtual ICommand* getCommand(const string& name);
protected:
	Controller();
	virtual ~Controller();
protected:
	static Controller* instance;
	map<string,ICommand*> m_mCommands;
		
};

#endif