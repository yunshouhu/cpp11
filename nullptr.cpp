#include <vld.h>
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

void F(int a) {
	cout << a << endl;
}

void F(int *p) {
	assert(p != NULL);

	cout << p << endl;
}

//nullptr��Ϊ�˽��ԭ��C++��NULL�Ķ����������������һ���µ����ͣ���ΪNULLʵ���ϴ������0��
int main() {

	int *p = nullptr;
	int *q = NULL;
	bool equal = (p == q); // equal��ֵΪtrue��˵��p��q���ǿ�ָ��
	//int a = nullptr; // ����ʧ�ܣ�nullptr����ת��Ϊint
	F(0); // ��C++98�б���ʧ�ܣ��ж����ԣ���C++11�е���F��int��
	F(nullptr);

	return 0;
}