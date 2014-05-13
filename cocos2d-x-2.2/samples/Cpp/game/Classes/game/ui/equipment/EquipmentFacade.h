#ifndef _EQUIPMENT_FACADE_
#define _EQUIPMENT_FACADE_
#include "mvc/patterns/Facade.h"

class EquipmentFacade :public Facade
{
	public:
		static EquipmentFacade* getInstance();
	public:
		//static const string COMMAND_LOGIN;
		static const string COMMAND_SWITCH_SEARCHPAGE;
		static const string COMMAND_SWITCH_ARSENALPAGE;
		//static const string COMMAND_EXIT;
		//static const string PROXY_LOGIN;
		static const string MEDIATOR_EQUIPMENT;

		//static const string NOTIFICATION_LOGIN_SUCESS;
		static const string NOTIFICATION_SWITCH_SRH_SUCCESS;
		static const string NOTIFICATION_SWITCH_ARL_SUCCESS;
		//static const string NOTIFICATION_LOGIN_FAIL;
		//static const string NOTIFICATION_CLOSE;

	protected:
		void initModel();
		void initController();
	private:
		EquipmentFacade();
		virtual ~EquipmentFacade();
		static EquipmentFacade* instance;
};


#endif