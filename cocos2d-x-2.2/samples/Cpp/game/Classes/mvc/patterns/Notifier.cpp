#include "mvc/patterns/Notifier.h"
#include "mvc/patterns/Facade.h"

void Notifier::sendNotification(const string& name)
{
	Facade::getInstance()->sendNotification(name);
}
void Notifier::sendNotification(const string& name,int type)
{
	Facade::getInstance()->sendNotification(name,type);
}
void Notifier::sendNotification(const string& name,void* data)
{
	Facade::getInstance()->sendNotification(name,data);
}
void Notifier::sendNotification(const string& name,void* data,int type)
{
	Facade::getInstance()->sendNotification(name,data,type);
}

void Notifier::sendCommand(const string& name,void* data)
{
	Facade::getInstance()->sendCommand(name,data);
}

void Notifier::sendCommand(const string& name)
{
	Facade::getInstance()->sendCommand(name);
}
IFacade* Notifier::getFacade()
{
	return Facade::getInstance();
}