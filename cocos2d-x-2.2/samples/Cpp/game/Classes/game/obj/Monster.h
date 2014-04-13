#ifndef _MONSTER_
#define _MONSTER_
#include "Creature.h"

class Monster :public Creature
{
public:
	virtual ~Monster();
	static Monster* create(int resId);
protected:
	Monster(int resId);
};


#endif