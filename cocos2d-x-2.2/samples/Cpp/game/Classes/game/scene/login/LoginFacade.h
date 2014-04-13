#ifndef _LOGIN_FACADE_
#define _LOGIN_FACADE_
#include "mvc/patterns/Facade.h"

class LoginFacade :public Facade
{
	public:
		static LoginFacade* getInstance();
	public:
		static const string COMMAND_LOGIN;
		static const string COMMAND_EXIT;
		static const string PROXY_LOGIN;
		static const string MEDIATOR_LOGIN;

		static const string NOTIFICATION_LOGIN_SUCESS;
		static const string NOTIFICATION_LOGIN_FAIL;
		static const string NOTIFICATION_CLOSE;

	protected:
		void initModel();
		void initController();
	private:
		LoginFacade();
		virtual ~LoginFacade();
		static LoginFacade* instance;
};


#endif