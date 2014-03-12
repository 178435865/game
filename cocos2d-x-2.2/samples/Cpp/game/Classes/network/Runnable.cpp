#include "network/Runnable.h"

void Runnable::run()
{
	while (true)
	{
		if(m_bKill)
		{
			break;
		}
		if(!m_bPause)
		{
			mainloop();
		}
	}
}
void Runnable::kill()
{
	m_bKill=true;
}
void Runnable::pause()
{
	m_bPause=true;
}
void Runnable::resume()
{
	m_bPause=false;
}
