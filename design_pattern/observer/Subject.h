/*********************************
 *@fileName: Subject.h
 *@author  : lemon
 *@email   : haohb13@gmail.com
 *@created : 2015-08-10 11:35:40
**********************************/
#ifndef __MY_SUBJECT_H
#define __MY_SUBJECT_H

#include <string>
#include <list>

typedef std::string STATE;

class Observer;

class Subject
{
public:
	Subject() : m_nSubjectState(""){}
	virtual ~Subject();

	void notify();
	void attach(Observer * pObserver);
	void detach(Observer * pObserver);

	virtual void setState(STATE nState);
	virtual STATE getState();
	
protected:
	STATE m_nSubjectState;
	std::list<Observer *> m_listObserver;
};


class ConcreateSubject : public Subject
{
public:
	ConcreateSubject(): Subject(){}

	virtual ~ConcreateSubject(){}

	virtual void setState(STATE nState);
	virtual STATE getState();
};


#endif
