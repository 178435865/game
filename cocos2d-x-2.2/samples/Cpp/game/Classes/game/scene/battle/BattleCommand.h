#ifndef _BATTLE_COMMAND_
#define _BATTLE_COMMAND_
#include "mvc/patterns/SingleCommand.h"
class BattleCommand:public SingleCommand
{
	public:
		void execute(Notification& noti);
		static BattleCommand* create();
};
#endif