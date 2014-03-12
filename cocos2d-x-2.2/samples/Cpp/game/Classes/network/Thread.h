#ifndef _THREAD_
#define _THREAD_

#include <pthread.h>
#include "cocos2d.h"

class Runnable;

class Thread
{
	friend void* startRoutine(void* param);
public:
	Thread(Runnable* runnable);
	void start();
	bool isRunning();
private:
	pthread_t mutable m_thread;
	Runnable* m_pRunnable;
};
#endif