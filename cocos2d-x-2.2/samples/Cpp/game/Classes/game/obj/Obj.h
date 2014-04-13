#ifndef _OBJ_
#define _OBJ_
#include "Graph.h"

class IObjectState;

class Obj :public Graph
{
public:
	virtual ~Obj();
	CC_SYNTHESIZE_READONLY(IObjectState*,m_pCurrentState,CurrentState);
	CC_SYNTHESIZE_READONLY(IObjectState*,m_pNextState,NextState);
	void chgState(IObjectState* state);
	virtual void update(float dt);
	virtual bool init();
protected:
	Obj(int resId);
};


#endif