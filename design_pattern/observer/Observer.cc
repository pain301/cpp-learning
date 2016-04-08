#include "Subject.h"
#include "Observer.h"
#include <iostream>

void ConcreateObserver::update(Subject * pSubject)
{
	if(NULL == pSubject)
		return ;
	m_nObserverState = pSubject->getState();
	std::cout << "The Subject State is " << m_nObserverState << std::endl;
}
