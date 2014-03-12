
#include "lock/Lock.h"  

//---------------------------------------------------------------------------  

//创建一个匿名互斥对象  
CMutex::CMutex()  
{  
#if WIN32
	m_mutex = ::CreateMutex(NULL, FALSE, NULL);  
#else
	pthread_mutex_init(&m_mutex, NULL);  
#endif
	
}  

//销毁互斥对象，释放资源  
CMutex::~CMutex()  
{  
#if WIN32
	::CloseHandle(m_mutex);  
#else
	pthread_mutex_destroy(&m_mutex);  
#endif
	
}  

//确保拥有互斥对象的线程对被保护资源的独自访问  
void CMutex::Lock() const  
{  
#if WIN32
	DWORD d = WaitForSingleObject(m_mutex, INFINITE);  
#else
	pthread_mutex_lock(&m_mutex); 
#endif
	
}  

//释放当前线程拥有的互斥对象，以使其它线程可以拥有互斥对象，对被保护资源进行访问  
void CMutex::Unlock() const  
{  
#if WIN32
	::ReleaseMutex(m_mutex);  
#else
	pthread_mutex_unlock(&m_mutex);  
#endif
	
}  

////---------------------------------------------------------------------------  
//
////初始化临界资源对象  
//CriSection::CriSection()  
//{  
//	::InitializeCriticalSection(&m_critclSection);  
//}  
//
////释放临界资源对象  
//CriSection::~CriSection()  
//{  
//	::DeleteCriticalSection(&m_critclSection);  
//}  
//
////进入临界区，加锁  
//void CriSection::Lock() const  
//{  
//	::EnterCriticalSection((LPCRITICAL_SECTION)&m_critclSection);  
//}     
//
////离开临界区，解锁  
//void CriSection::Unlock() const  
//{  
//	::LeaveCriticalSection((LPCRITICAL_SECTION)&m_critclSection);  
//}  

//---------------------------------------------------------------------------  

//利用C++特性，进行自动加锁  
CMyLock::CMyLock(const ILock& m) : m_lock(m)  
{  
	m_lock.Lock();  
}  

//利用C++特性，进行自动解锁  
CMyLock::~CMyLock()  
{  
	m_lock.Unlock();  
}  