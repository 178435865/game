#ifndef _MISSINFODETAIL_FACADE_
#define _MISSINFODETAIL_FACADE_
#include "mvc/patterns/Facade.h"

class MissInfoDetailFacade :public Facade
{
	public:
		static MissInfoDetailFacade* getInstance();
	public:
		//static const string COMMAND_LOGIN;
		//static const string COMMAND_EXIT;
		//static const string PROXY_LOGIN;
		static const string MEDIATOR_MISS_INFO_DETAIL;

		//static const string NOTIFICATION_LOGIN_SUCESS;
	//	static const string NOTIFICATION_SWITCH_SRH_SUCCESS;
		//static const string NOTIFICATION_LOGIN_FAIL;
		//static const string NOTIFICATION_CLOSE;

	protected:
		void initModel();
		void initController();
	private:
		MissInfoDetailFacade();
		virtual ~MissInfoDetailFacade();
		static MissInfoDetailFacade* instance;
};


#endif