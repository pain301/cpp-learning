#include <iostream>
#include <vector>
#include <memory>

std::unique_ptr<int> getval()
{
	std::unique_ptr<int> up(new int(88));
	return up;
}

int main(void)
{
	std::unique_ptr<int> api(new int(88));
	//无法进行复制操作,调用的是复制构造函数
	//std::unique_ptr<int> one(api);
	std::cout << "*api = " << *api << std::endl;

	//调用的是移动构造函数
	std::unique_ptr<int> uptr = getval();
	std::cout << "*uptr = " << *uptr << std::endl;

	std::unique_ptr<int> up(new int(66));
	//调用的是移动构造函数
	std::unique_ptr<int> uptr2 = std::move(up);
	std::cout << "*uptr2 = " << *uptr2 << std::endl;

	std::cout << std::endl;

	std::unique_ptr<int> sp(new int(88));
	std::vector<std::unique_ptr<int> > vec;
	//sp是一个有名字的对象，是左值
	//vec.push_back(sp);
	//将sp转换成了一个右值，此时sp所托管的对象就无法再使用了
	vec.push_back(std::move(sp));
	return 0;
}
