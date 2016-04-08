#include "Subject.h"
#include "Observer.h"
#include <iostream>
#include <algorithm>

void Subject::attach(Observer * pObserver)
{
	std::cout << "attach an observer" << std::endl;
	m_listObserver.push_back(pObserver);
}

void Subject::detach(Observer * pObserver)
{
	std::cout << "detach an observer" << std::endl;
	std::list<Observer *>::iterator it;

	it = std::find(m_listObserver.begin(),
				   m_listObserver.end(),
				   pObserver);

	if(it != m_listObserver.end())
	{
		m_listObserver.erase(it);
	}
}

void Subject::notify()
{
	std::list<Observer *>::iterator iter;
	for(iter = m_listObserver.begin();
		iter != m_listObserver.end();
		++iter)
	{
		(*iter)->update(this);
	}
}

void Subject::setState(STATE nstate)
{
	std::cout << "Subject::setState()" << std::endl;
	m_nSubjectState = nstate;
}

STATE Subject::getState()
{
	return m_nSubjectState;
}


Subject::~Subject()
{
	std::list<Observer *>::iterator iter;
	for(iter = m_listObserver.begin();
		iter != m_listObserver.end();
		++iter)
	{
		Observer * tmp = *iter;
		delete tmp;
	}
	m_listObserver.clear();
}


void ConcreateSubject::setState(STATE nstate)
{
	std::cout << "ConcreateSubject::setState()" << std::endl;
	m_nSubjectState = nstate;
}

STATE ConcreateSubject::getState()
{
	return m_nSubjectState;
}
