#include <vld.h>
#include <iostream>
#include <string>
#include <assert.h>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>   // sort函数模板、for_each函数模板
#include <functional>  // function类模板
using namespace std;

class Head
{
public:

	Head() = default;
	~Head() = default;
private:
	string name;
};
template<typename Head, typename Tail>
void Print(Head head, Tail...) {
	cout << head << endl;
	//Print(tail...);
}

//http://my.oschina.net/wangxuanyihaha/blog/183151
int main()
{
	auto p = std::make_pair(1, "C++ 11");//原来的初始化方法
	
	auto t1 = make_tuple(1, 2.0, "C++ 11");
	
	//auto t2 = make_tuple(1, 2.0, "C++ 11",{ 1, 0, 2 });
	
	
	//auto h = new Head();
	//Print(h,1,1.0, "C++11");

	//delete &t1;
	//delete &p;
	//delete &h;

	int arr[3] = { 1, 2, 3 };
	vector<int> v(arr, arr + 3);//原来的初始化方法
	for(auto const a:v )
	{
		cout<<a << endl;
	}
	//cpp11
	int arr11[3]{ 1, 2, 3 };
	vector<int> iv{ 11, 22, 33 };
	map<int, string>{ {1, "a"}, { 2, "b" }};
	string str{ "Hello World" };
	for (auto const a : iv)
	{
		cout << a << endl;
	}
	cout << str << endl;



	return 0;
}