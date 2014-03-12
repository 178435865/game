#include "network/Thread.h"
#include "network/Runnable.h"

Thread::Thread(Runnable* runnable)
{
	m_pRunnable=runnable;
}
void* startRoutine(void* param)
{
	Thread* thread = static_cast<Thread*>(param);
	if(thread){
		if(thread->m_pRunnable){
			thread->m_pRunnable->run();
		}
	}
	return 0;

}
void Thread::start()
{
	if(!isRunning())
	{
		pthread_create(&m_thread,NULL,startRoutine,const_cast<Thread*>(this));
	}
}
bool Thread::isRunning()
{
	int kill_rc = pthread_kill(m_thread,0);

	if(kill_rc == ESRCH)
	{
		printf("the specified thread did not exists or already quit\n");
		return false;
	}
	else if(kill_rc == EINVAL)
	{
		printf("signal is invalid\n");
		return false;
	}
	else
	{
		printf("the specified thread is alive\n");
		return true;
	}
}