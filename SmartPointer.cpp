#include <vld.h>
#include <iostream>
#include <string>
#include <assert.h>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>   // sort����ģ�塢for_each����ģ��
#include <functional>  // function��ģ��
#include <memory>

using namespace std;

//http://zh.cppreference.com/w/cpp/memory/shared_ptr
//http://zh.cppreference.com/w/cpp/utility
int main()
{
	std::unique_ptr<int> p1(new int(42));
	std::unique_ptr<int> p2 = std::move(p1); // �ƽ�uniqueָ��
	auto sp = std::make_shared<int>(42);
	std::weak_ptr<int> wp = sp;
	{
		auto sp = wp.lock(); // ����shared_ptr
		std::cout << *sp << std::endl;
	}
	sp.reset();

	if (wp.expired())
		std::cout << "expired" << std::endl;

	return 0;
}