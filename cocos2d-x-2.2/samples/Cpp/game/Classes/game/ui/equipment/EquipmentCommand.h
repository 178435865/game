#ifndef _EQUIPMENT_COMMAND_
#define _EQUIPMENT_COMMAND_
#include "mvc/patterns/SingleCommand.h"
class EquipmentCommand:public SingleCommand
{
	public:
		void execute(Notification& noti);
		static EquipmentCommand* create();
	private:
		EquipmentCommand(){};
		~EquipmentCommand(){};
		static EquipmentCommand* instance;
};
#endif