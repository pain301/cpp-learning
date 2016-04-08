#ifndef __MY_OBSERVER_H
#define __MY_OBSERVER_H

#include <string>
typedef std::string STATE;

class Subject;//前向声明

class Observer
{
public:
	Observer(): m_nObserverState(""){}

	virtual ~Observer(){}

	virtual void update(Subject * pSubject) = 0;
protected:
	STATE m_nObserverState;
};


class ConcreateObserver : public Observer
{
public:
	ConcreateObserver() : Observer(){}
	virtual ~ConcreateObserver(){}

	virtual void update(Subject *pSubject);

};


#endif

