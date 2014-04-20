#include "Obj.h"
#include "game/obj/IObjectState.h"
#include "game/action/GameArmature.h"

void Obj::chgState(IObjectState* state){
	if(m_pNextState)
	{
		CCLog("chgState delete m_pNextState");
		delete m_pNextState;
		m_pNextState=NULL;
	}

	m_pNextState=state;
	
}

void Obj::update(float dt)
{
	Graph::update(dt);
	bool isSame=false;
	if(m_pNextState)
	{
		if(m_pCurrentState)
		{
			if(m_pCurrentState->getState()==m_pNextState->getState())
			{
				isSame=true;
			}
			if(!isSame)
			{
				//this->stopAction(m_pCurrentState->getAction());
				//m_pCurrentState->getAction()->stop();
				CCAction* action=m_pCurrentState->getAction();
				if(action)
				{
					IArmature* ar=dynamic_cast<IArmature*>(action);
					if(ar)
					{
						ar->setIsDone(true);
					}
				}
				m_pCurrentState->afterExecute(this);
				delete m_pCurrentState;
				m_pCurrentState=NULL;
			}
			
		}
		if(!isSame)
		{
			m_pNextState->beforeExecute(this);
			m_pCurrentState=m_pNextState;
			m_pNextState=NULL;
		}
		else
		{
			CCLog("update merge");
			m_pCurrentState->mergeState(m_pNextState);
			delete m_pNextState;
			m_pNextState=NULL;
		}
		
	}

	if(m_pCurrentState&&!m_pCurrentState->getIsExecuted())
	{
		m_pCurrentState->execute(this);
	}

	if(m_pCurrentState&& m_pCurrentState->isDone())
	{
		m_pCurrentState->finish(this);
		//delete m_pCurrentState;
		//m_pCurrentState=NULL;
	}

}

Obj::~Obj()
{
	this->resumeSchedulerAndActions();
	CC_SAFE_DELETE(m_pCurrentState);
	CC_SAFE_DELETE(m_pNextState);
}

Obj::Obj(int resId):Graph(resId){
	m_pCurrentState=NULL;
	m_pNextState=NULL;
};

bool Obj::init()
{
	return Graph::init();
}

