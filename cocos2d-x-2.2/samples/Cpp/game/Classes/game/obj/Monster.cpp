#include "Monster.h"

Monster::~Monster()
{

}


Monster::Monster(int resId):Creature(resId)
{
}

 Monster* Monster::create(int resId)
 {
	 Monster* monster=new Monster(resId);
	 if(monster&&monster->init())
	 {
		 monster->autorelease();
	 }
	 else
	 {
		 delete monster;
		 monster=NULL;
	 }
	 return monster;
 }