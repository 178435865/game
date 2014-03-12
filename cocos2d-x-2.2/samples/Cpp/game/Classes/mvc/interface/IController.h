#ifndef _I_CONTROLLER_
#define _I_CONTROLLER_
#include "gameStd.h"

class ICommand;
class Notification;

class IController
{
	public:
		virtual void registerCommand(const string& name,const ICommand* comm)=0;
		virtual void removeCommand(const string& name)=0;
		virtual bool hasCommand(const string& name)=0;
		virtual ICommand* getCommand(const string& name)=0;
		virtual void executeCommand(Notification& noti)=0;
};
#endif