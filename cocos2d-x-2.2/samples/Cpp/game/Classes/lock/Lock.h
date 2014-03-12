#ifndef _Lock_H  
#define _Lock_H  

#include "lock/ILock.h"
#ifdef WIN32
	#include <windows.h> 
#else
	#include <pthread.h>  
#endif // Win32

//互斥对象锁类  
class CMutex : public ILock  
{  
public:  
	CMutex();  
	~CMutex();  

	 void Lock() const;  
	 void Unlock() const;  

private:  
#if WIN32
	HANDLE m_mutex;  
#else
	 mutable pthread_mutex_t m_mutex;  
#endif
	
};  

////临界区锁类  
//class CriSection : public ILock  
//{  
//public:  
//	CriSection();  
//	~CriSection();  
//
//	 void Lock() const;  
//	 void Unlock() const;  
//
//private:  
//#if WIN32
//	CRITICAL_SECTION m_critclSection;  
//#else
//	mutable pthread_mutex_t m_mutex;  
//#endif
//	
//};  


//锁  
class CMyLock  
{  
public:  
	CMyLock(const ILock&);  
	~CMyLock();  

private:  
	const ILock& m_lock;  
};  


#endif 