#ifndef __LINE_H_
#define __LINE_H_

class Line{
	class Impl;
private:
	Impl *p;	
public:
	Line(int x1=0,int y1=0,int x2=0,int y2=0);
	~Line();
	void print();
};

#endif
