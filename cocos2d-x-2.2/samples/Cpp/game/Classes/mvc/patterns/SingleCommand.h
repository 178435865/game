#ifndef _SINGLE_COMMAND_
#define _SINGLE_COMMAND_
#include "mvc/interface/ICommand.h"
#include "mvc/patterns/Notifier.h"

class SingleCommand :public ICommand,public Notifier
{
	public:
		virtual void execute(Notification& noti){};
};
#endif