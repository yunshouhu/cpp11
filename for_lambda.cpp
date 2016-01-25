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
int main()
{
	map<string, int> m{ { "a", 1 },{ "b", 2 },{ "c", 3 } };
	for (auto p : m) {
		cout << p.first << "=" << p.second << endl;
	}

	vector<int> iv{ 5, 4, 3, 2, 1 };
	int a = 2, b = 1;

	cout << "=============" << endl;
	for_each(iv.begin(), iv.end(), [b](int &x) {cout << (x + b) << endl; }); // (1)

	cout << "=============" << endl;
	for_each(iv.begin(), iv.end(), [=](int &x) {x *= (a + b); cout << x <<endl; });     // (2)

	cout << "=============" << endl;
	for_each(iv.begin(), iv.end(), [=](int &x)->int {cout << x * (a + b) << endl;  return x * (a + b);  });// (3)


	return 0;
}