#ifndef _MISSINFO_FACADE_
#define _MISSINFO_FACADE_
#include "mvc/patterns/Facade.h"

class MissInfoFacade :public Facade
{
	public:
		static MissInfoFacade* getInstance();
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
		MissInfoFacade();
		virtual ~MissInfoFacade();
		static MissInfoFacade* instance;
};


#endif