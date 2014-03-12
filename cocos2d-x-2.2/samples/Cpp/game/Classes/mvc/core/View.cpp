#include "mvc/core/View.h"
#include "mvc/interface/IMediator.h"
#include "mvc/patterns/Notification.h"

View* View::instance=NULL;
View* View::getInstance()
{
	if(instance==NULL)
	{
		instance=new View();
	}
	return instance;
}

void View::registerMediator(IMediator* mediator)
{
	const string& name=mediator->getName();
	if(m_mMediators.find(name)==m_mMediators.end())
	{
		m_mMediators[name]=mediator;
		const vector<string>& interests=mediator->getInterests();
		int size=interests.size();
		for(int i=0;i<size;++i)
		{
			const string& interestName=interests[i];
			if(m_mInterests.find(interestName)!=m_mInterests.end())
			{
				vector<IMediator*>& vec=m_mInterests[interestName];
				vec.push_back(mediator);
			}
			else
			{
				vector<IMediator*> vec;
				vec.push_back(mediator);
				m_mInterests[interestName]=vec;
			}
		}
	}

	

}
IMediator* View::getMediator(const string& mediatorName)
{
	if(m_mMediators.find(mediatorName)!=m_mMediators.end())
	{
		return m_mMediators[mediatorName];
	}	
	return NULL;
}
bool View::hasMediator(const string& mediatorName)
{
	if(m_mMediators.find(mediatorName)!=m_mMediators.end())
	{
		return true;
	}	
	return false;
}
IMediator* View::removeMediator(const string& mediatorName)
{
	map<string,IMediator*>::iterator it=m_mMediators.find(mediatorName);
	if(it!=m_mMediators.end())
	{
		IMediator* med=m_mMediators[mediatorName];
		removeInsterests(med);
		m_mMediators.erase(it);
		return med;
	}	
	return NULL;
}
void View::notifyMediator(Notification& noti)
{
	const string& name=noti.m_strNotiName;
	if(m_mInterests.find(name)!=m_mInterests.end())
	{
		vector<IMediator*>& vec=m_mInterests[name];
		int size=vec.size();
		for(int i=0;i<size;++i)
		{
			IMediator* med=vec[i];
			med->handleNotification(noti);
		}
	}
}
void View::removeInsterests(IMediator* mediator)
{
	const vector<string>&  vec=mediator->getInterests();
	int size=vec.size();
	for(int i=0;i<size;++i)
	{
		const string& insterestName=vec[i];
		if(m_mInterests.find(insterestName)!=m_mInterests.end())
		{
			vector<IMediator*>& vec=m_mInterests[insterestName];
			for(vector<IMediator*>::iterator it=vec.begin();it!=vec.end();++it)
			{
				if(*it==mediator)
				{
					vec.erase(it);
					break;
				}
			}
		}
	}
}