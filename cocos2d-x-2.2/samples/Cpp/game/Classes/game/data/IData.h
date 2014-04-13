#ifndef _I_DATA_
#define _I_DATA_
#include "util/Util.h"

class IData
{
	virtual void loadData(int id)=0;
	virtual void setData(const Value& json)=0;
};
#endif