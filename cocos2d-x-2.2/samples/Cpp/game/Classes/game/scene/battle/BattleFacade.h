#ifndef _BATTLE_FACADE_
#define _BATTLE_FACADE_
#include "mvc/patterns/Facade.h"

class BattleFacade :public Facade
{
	public:
		static BattleFacade* getInstance();
	public:
		static const string NOTIFICATION_ROCKER_TOUCH_LEFT_MOVE;
		static const string NOTIFICATION_ROCKER_TOUCH_LEFT_BEGIN;
		static const string NOTIFICATION_ROCKER_TOUCH_LEFT_END;
		static const string NOTIFICATION_ROCKER_TOUCH_RIGHT_MOVE;
		static const string NOTIFICATION_ROCKER_TOUCH_RIGHT_BEGIN;
		static const string NOTIFICATION_ROCKER_TOUCH_RIGHT_END;
	protected:
		void initModel();
		void initController();
	private:
		BattleFacade();
		virtual ~BattleFacade();
};


#endif