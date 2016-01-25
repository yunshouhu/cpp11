#include <vld.h>
#include <iostream>
using namespace std;

class X{
public:
	//编译器将为显式声明的 defaulted 函数自动生成函数体。自动生成默认构造函数 X::X(){}
	X() = default;
	X(int i) {
		a = i;
	}
	void show()
	{
		cout << a << endl;
	}
private:
	int a;
};
class XX {
public:
	XX() = default; //Inline defaulted 默认构造函数
	XX(const XX&);
	XX& operator = (const XX&);
	~XX() = default;  //Inline defaulted 析构函数
};

XX::XX(const XX&) = default;  //Out-of-line defaulted 拷贝构造函数
XX& XX::operator = (const XX&) = default;     //Out-of-line defaulted  
										   // 拷贝赋值操作符

class XXX {
public:
	//virtual ~XXX() {};     // 手动定义虚析构函数
	virtual ~XXX()=default;// 编译器自动生成 defaulted 函数定义体
private:
	int x;
};

//Defaulted 函数特性仅适用于类的特殊成员函数，且该特殊成员函数没有默认参数。
class Y : public XXX {
	//编译器会自动隐式的为该类生成一个析构函数
private:
	int y;
};

int add(int, int) = delete;//禁用默认函数
double add(double a, double b) {
	return a + b;
}

class X_delete {
public:
	X_delete()=default;
	X_delete(const X_delete&) = delete;  // 声明拷贝构造函数为 deleted 函数
	X_delete& operator = (const X_delete &) = delete; // 声明拷贝赋值操作符为 deleted 函数
};

//http://www.ibm.com/developerworks/cn/aix/library/1212_lufang_c11new/
//通过将类的特殊成员函数声明为 defaulted 函数，可以显式指定编译器为该函数自动生成默认函数体。
//通过将函数声明为 deleted 函数，可以禁用某些不期望的转换或者操作符
int main(int argc,char* argv[])
{
	X x;
	x.show();
	X hehe(1024);
	hehe.show();

	XXX *xxx = new Y;
	delete xxx;

	//cout << add(1, 3) << endl;    // 错误，调用了 deleted 函数 add(int, int) 
	cout << add(1.2, 1.3) << endl;
	X_delete x1;
	//X_delete x2 = x1;   // 错误，拷贝构造函数被禁用
	X_delete x3;
	//x3 = x1;     // 错误，拷贝赋值操作符被禁用
	return 0;
}