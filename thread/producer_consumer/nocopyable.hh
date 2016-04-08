#ifndef _NOCOPYABLE_H_
#define _NOCOPYABLE_H_

class Nocopyable{
protected:
	Nocopyable(){};
private:
	Nocopyable(const Nocopyable &);
	Nocopyable& operator=(const Nocopyable &);
};

#endif
