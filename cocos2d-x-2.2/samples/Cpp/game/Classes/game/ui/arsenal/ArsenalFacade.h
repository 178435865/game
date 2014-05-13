#ifndef _ARSENAL_FACADE_
#define _ARSENAL_FACADE_
#include "mvc/patterns/Facade.h"

class ArsenalFacade :public Facade
{
	public:
		static ArsenalFacade* getInstance();
	public:
		//static const string COMMAND_LOGIN;
	//	static const string COMMAND_SWITCH_SEARCHPAGE;
		//static const string COMMAND_EXIT;
		//static const string PROXY_LOGIN;
		static const string MEDIATOR_MISS_INFO;

		//static const string NOTIFICATION_LOGIN_SUCESS;
	//	static const string NOTIFICATION_SWITCH_SRH_SUCCESS;
		//static const string NOTIFICATION_LOGIN_FAIL;
		//static const string NOTIFICATION_CLOSE;

	protected:
		void initModel();
		void initController();
	private:
		ArsenalFacade();
		virtual ~ArsenalFacade();
		static ArsenalFacade* instance;
};


#endif