#ifndef _ROLE_
#define _ROLE_
#include "Creature.h"

class Role :public Creature
{
public:
	virtual ~Role();
	static Role* create(int resId);
	void Role::setFace(float currentX,float currentY,float destX,float destY);
	virtual bool init(){return Creature::init();};
protected:
	Role(int resId);
};


#endif