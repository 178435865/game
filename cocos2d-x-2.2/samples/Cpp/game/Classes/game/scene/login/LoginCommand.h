#ifndef _LOGIN_COMMAND_
#define _LOGIN_COMMAND_
#include "mvc/patterns/SingleCommand.h"
class LoginCommand:public SingleCommand
{
	public:
		void execute(Notification& noti);
		static LoginCommand* create();
	private:
		LoginCommand(){};
		~LoginCommand(){};
		static LoginCommand* instance;
};
#endif