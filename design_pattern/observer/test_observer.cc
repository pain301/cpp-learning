#include "Observer.h"
#include "Subject.h"

int main(void)
{
	Observer * p1 = new ConcreateObserver;
	Observer * p2 = new ConcreateObserver;

	Subject * pSubject = new ConcreateSubject;
	pSubject->attach(p1);
	pSubject->attach(p2);

	pSubject->setState("Hello,world");
	pSubject->notify();

	Observer * p3 = new ConcreateObserver;
	pSubject->attach(p3);

	pSubject->setState("welcome to wangdao");
	pSubject->notify();

}
