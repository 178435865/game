#ifndef _IAI_
#define _IAI_
#include "util/Util.h"


enum AI_TYPE
{
	eAI_TRACK,
	eAI_ATTACK,
};

class Creature;

class IAI
{
	public:
		virtual void execute(Creature* src,Creature* target)=0;
};

class AITrack:public IAI
{
public:
	void execute(Creature* src,Creature* target){};
};