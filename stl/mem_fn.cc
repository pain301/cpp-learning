#include <iostream>
#include <functional>

struct Foo
{
	void display_greeting()
	{
		std::cout << "Hello,world!" << std::endl;
	}

	void display_number(int i)
	{
		std::cout << "number: " << i << std::endl;
	}
	int data;
};

int main(void)
{
	Foo f;
	auto greet = std::mem_fn(&Foo::display_greeting);
	greet(f);

	auto print_num = std::mem_fn(&Foo::display_number);
	print_num(f, 42);

	auto access_data = std::mem_fn(&Foo::data);
	std::cout << "data:" << access_data(f) << std::endl;
}
