#include "game/ui/equipment/EquipmentProxy.h"
#include "game/ui/equipment/EquipmentVO.h"
#include "util/Util.h"


EquipmentProxy::EquipmentProxy(const string& name):Proxy(name)
{

}
EquipmentProxy::~EquipmentProxy()
{
	
}
bool EquipmentProxy::checkEquipment(const EquipmentVO& vo)
{
	const string name=vo.getUserName();
	const string password=vo.getUserPassword();
	if(!StringHelper::isEmpty(name)&&!StringHelper::isEmpty(password))
	{
		return true;
	}
	return false;
}
