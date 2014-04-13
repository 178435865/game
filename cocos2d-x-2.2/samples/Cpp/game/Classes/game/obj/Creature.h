#ifndef _CREATURE_
#define _CREATURE_
#include "Obj.h"




class Creature :public Obj
{
public:
	virtual ~Creature();
	void Creature::setFace(float currentX,float currentY,float destX,float destY);
	bool init(){return Obj::init();};
protected:
	Creature(int resId);
};


#endif