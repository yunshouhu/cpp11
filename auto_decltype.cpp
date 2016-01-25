#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product
{
private:
	string name;
};
class Creator
{
public:
	Product* makeObject()
	{
		return new Product();
	}
private:
	string name;

};

template <typename Creator>
void processProduct(const Creator& creator) {
	auto val = creator->makeObject();
	// do somthing with val
	cout << "processProduct"<< endl;
}

template <typename Creator>
auto processProduct2(const Creator& creator) -> decltype(creator->makeObject()) {
	auto val = creator->makeObject();
	// do somthing with val
	cout << "processProduct2" << endl;
	return val;
}

int main()
{
	//auto a; // ����auto��ͨ����ʼ�����ʽ���������Ƶ������û�г�ʼ�����ʽ�����޷�ȷ��a������
	auto i = 1;
	auto d = 1.0;
	auto str = "Hello World";
	auto ch = 'A';
	auto func = less<int>();
	vector<int> iv;
	auto ite = iv.begin();
	auto p = new Product(); // ���Զ������ͽ��������Ƶ�

	auto c = new Creator();
	processProduct(c);

	auto c2 = new Creator();
	processProduct2(c2);


	return 0;
}