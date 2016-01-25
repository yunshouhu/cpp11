#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	cout << "Hello, It's work!" << endl;
	auto i = 1;
	auto d = 0.57;
	auto str = "Hello";
	//-----------for--------------------------------
	map<string, int> m{ { "a",1 },{ "b",2 },{ "c",3 } };
	for (const auto &p : m) {
		cout << p.first << "=" << p.second << endl;
	}

	//----------------lambda-----------------------
	int count = 0;
	auto print_num = [&count](int num) {
		cout << "num : " << num << endl;
		count += num;
	};
	print_num(12);
	print_num(32);
	cout << "count=" << count << endl;
}