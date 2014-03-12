#ifndef _VIEW_
#define _VIEW_
#include "gameStd.h"
#include "mvc/interface/IView.h"

class IMediator;

class View:public IView
{
	public:
		void registerMediator(IMediator* mediator);
		IMediator* getMediator(const string& mediatorName);
		bool hasMediator(const string& mediatorName);
		IMediator* removeMediator(const string& mediatorName);
		void notifyMediator(Notification& noti);
		static View* getInstance();
	private:
		void removeInsterests(IMediator* mediator);
	private:
		static View* instance;
		map<string,vector<IMediator*> > m_mInterests;
		map<string,IMediator*> m_mMediators;
};
#endif