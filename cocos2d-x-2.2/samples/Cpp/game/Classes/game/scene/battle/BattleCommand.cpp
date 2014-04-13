#include "game/scene/battle/BattleCommand.h"


BattleCommand* BattleCommand::create()
{
	static BattleCommand* instance=NULL;
	if(instance==NULL)
	{
		instance=new BattleCommand();
	}
	return instance;
}
void BattleCommand::execute(Notification& noti)
{
	const string& name=noti.m_strNotiName;	
	void* data=noti.m_pData;
}