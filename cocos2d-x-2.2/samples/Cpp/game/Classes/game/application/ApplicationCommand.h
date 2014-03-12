#ifndef _APPLICATION_COMMAND_
#define _APPLICATION_COMMAND_
#include "mvc/patterns/SingleCommand.h"

class ApplicationCommand :public SingleCommand
{
public:
	static ApplicationCommand* create();
	void execute(Notification& noti);
private:
	ApplicationCommand();
	virtual ~ApplicationCommand();
	static ApplicationCommand* instance;
};
#endif