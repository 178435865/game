#ifndef _RUNNABLE_
#define _RUNNABLE_
class Runnable
{
public:
	virtual void mainloop()=0;
	void run();
	void kill();
	void pause();
	void resume();
private:
	bool m_bKill;
	bool m_bPause;
};
#endif