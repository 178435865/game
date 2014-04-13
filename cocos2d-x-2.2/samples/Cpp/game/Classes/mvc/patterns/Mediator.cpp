#include "mvc/patterns/Mediator.h"
#include "mvc/patterns/Facade.h"


Mediator::Mediator(const string& name){
	m_strName=name;
};
Mediator::~Mediator(){
	Facade::getInstance()->removeMediator(m_strName);
};
const string& Mediator::getName(){
	return m_strName;
};
bool Mediator::init()
{
	initInterests();
	Facade::getInstance()->registerMediator(this);
	return true;
}
const vector<string>& Mediator::getInterests()
{
	return m_vInterests;
}