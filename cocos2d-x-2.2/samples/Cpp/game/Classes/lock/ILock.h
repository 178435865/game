#ifndef _ILock_H  
#define _ILock_H  

//���ӿ���  
class ILock  
{  
public:  
	virtual ~ILock() {}  

	virtual void Lock() const = 0;  
	virtual void Unlock() const = 0;  
};
#endif