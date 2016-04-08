#include <iostream>
#include <memory>

class Parent;
class Child;

typedef std::shared_ptr<Parent> parent_ptr;
typedef std::shared_ptr<Child> child_ptr;

class Child
{
public:
	Child()
	{
		std::cout << "Child::Child()" << std::endl;
	}

	~Child()
	{
		std::cout << "Child::~Child()" << std::endl;
	}

	parent_ptr parent_;
};

class Parent
{
public:
	Parent()
	{
		std::cout << "Parent::Parent()" << std::endl;
	}
	~Parent()
	{
		std::cout << "Parent::~Parent()" << std::endl;
	}

	//child_ptr child_;
	std::weak_ptr<Child> child_;
};

int main(void)
{	
	//循环引用的时候发生了内存泄露
	parent_ptr parent(new Parent);
	std::cout << "parent's use_count = " 
			  << parent.use_count()
			  << std::endl;

	child_ptr child(new Child);
	std::cout << "child's use_count = " 
			  << child.use_count()
			  << std::endl;

	parent->child_ = child;
	child->parent_ = parent; 
	std::cout << "parent's use_count = " 
			  << parent.use_count()
			  << std::endl;
	std::cout << "child's use_count = " 
			  << child.use_count()
			  << std::endl;
	return 0;
}
