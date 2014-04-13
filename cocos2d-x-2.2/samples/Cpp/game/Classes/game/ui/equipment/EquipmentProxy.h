#ifndef _EQUIPMENT_PROXY_
#define _EQUIPMENT_PROXY_
#include "mvc/patterns/Proxy.h"

class EquipmentVO;

class EquipmentProxy:public Proxy
{
	public:
		EquipmentProxy(const string& name);
		virtual ~EquipmentProxy();
		bool checkEquipment(const EquipmentVO& vo);
	private:
		
};
#endif