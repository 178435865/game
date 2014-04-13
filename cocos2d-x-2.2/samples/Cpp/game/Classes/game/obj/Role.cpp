#include "Role.h"

Role::~Role()
{

}


Role::Role(int resId):Creature(resId)
{
}

Role* Role::create(int resId)
{
	Role* obj=new Role(resId);
	if(obj&&obj->init())
	{
		obj->autorelease();
	}
	else
	{
		delete obj;
		obj=NULL;
	}
	return obj;
}