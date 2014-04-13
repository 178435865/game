#include "Creature.h"

Creature::~Creature()
{

}
void Creature::setFace(float currentX,float currentY,float destX,float destY)
{
	if(currentX>destX)
	{
		this->setScaleX(1);
	}
	else
	{
		this->setScaleX(-1);
	}
}
Creature::Creature(int resId):Obj(resId)
{
}