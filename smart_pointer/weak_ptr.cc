#include <iostream>
#include <memory>

class X
{
public:
	X()
	{
		std::cout << "X()" << std::endl;
	}

	~X()
	{
		std::cout << "~X()" << std::endl;
	}

	void Fun()
	{
		std::cout << "Fun()" << std::endl;
	}
};

int main(void)
{
	std::weak_ptr<X> p;
	{
		std::shared_ptr<X> p2(new X);
		std::cout << "p2's use_count = " << p2.use_count() << std::endl;

		p = p2;
		std::cout << "after p = p2;" << std::endl;
		std::cout << "p2's use_count = " << p2.use_count() << std::endl;

		//将weak_ptr提升为shared_ptr
		std::shared_ptr<X> p3 = p.lock();
		if(!p3)
		{
			std::cout << "object is destroyed" << std::endl;
		}
		else
		{
			p3->Fun();
			std::cout << "p3's use_count= " << p3.use_count() << std::endl;
		}
	}

	//weak_ptr提升失败--因为对象已经被销毁
	std::shared_ptr<X> p4 = p.lock();
	if(!p4)
	{
		std::cout << "==object is destroyed!" << std::endl;
	}
	else
	{
		p4->Fun();
	}
}
