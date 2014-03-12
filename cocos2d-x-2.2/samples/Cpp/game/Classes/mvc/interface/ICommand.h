#ifndef __I_COMMAND__
#define __I_COMMAND__

class Notification;

class ICommand
{
public:
	virtual void execute(Notification& noti)=0;
};

#endif