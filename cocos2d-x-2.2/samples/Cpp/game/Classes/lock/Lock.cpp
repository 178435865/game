
#include "lock/Lock.h"  

//---------------------------------------------------------------------------  

//����һ�������������  
CMutex::CMutex()  
{  
#if WIN32
	m_mutex = ::CreateMutex(NULL, FALSE, NULL);  
#else
	pthread_mutex_init(&m_mutex, NULL);  
#endif
	
}  

//���ٻ�������ͷ���Դ  
CMutex::~CMutex()  
{  
#if WIN32
	::CloseHandle(m_mutex);  
#else
	pthread_mutex_destroy(&m_mutex);  
#endif
	
}  

//ȷ��ӵ�л��������̶߳Ա�������Դ�Ķ��Է���  
void CMutex::Lock() const  
{  
#if WIN32
	DWORD d = WaitForSingleObject(m_mutex, INFINITE);  
#else
	pthread_mutex_lock(&m_mutex); 
#endif
	
}  

//�ͷŵ�ǰ�߳�ӵ�еĻ��������ʹ�����߳̿���ӵ�л�����󣬶Ա�������Դ���з���  
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
////��ʼ���ٽ���Դ����  
//CriSection::CriSection()  
//{  
//	::InitializeCriticalSection(&m_critclSection);  
//}  
//
////�ͷ��ٽ���Դ����  
//CriSection::~CriSection()  
//{  
//	::DeleteCriticalSection(&m_critclSection);  
//}  
//
////�����ٽ���������  
//void CriSection::Lock() const  
//{  
//	::EnterCriticalSection((LPCRITICAL_SECTION)&m_critclSection);  
//}     
//
////�뿪�ٽ���������  
//void CriSection::Unlock() const  
//{  
//	::LeaveCriticalSection((LPCRITICAL_SECTION)&m_critclSection);  
//}  

//---------------------------------------------------------------------------  

//����C++���ԣ������Զ�����  
CMyLock::CMyLock(const ILock& m) : m_lock(m)  
{  
	m_lock.Lock();  
}  

//����C++���ԣ������Զ�����  
CMyLock::~CMyLock()  
{  
	m_lock.Unlock();  
}  