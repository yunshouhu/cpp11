#include <vld.h>
#include <iostream>
using namespace std;

class X{
public:
	//��������Ϊ��ʽ������ defaulted �����Զ����ɺ����塣�Զ�����Ĭ�Ϲ��캯�� X::X(){}
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
	XX() = default; //Inline defaulted Ĭ�Ϲ��캯��
	XX(const XX&);
	XX& operator = (const XX&);
	~XX() = default;  //Inline defaulted ��������
};

XX::XX(const XX&) = default;  //Out-of-line defaulted �������캯��
XX& XX::operator = (const XX&) = default;     //Out-of-line defaulted  
										   // ������ֵ������

class XXX {
public:
	//virtual ~XXX() {};     // �ֶ���������������
	virtual ~XXX()=default;// �������Զ����� defaulted ����������
private:
	int x;
};

//Defaulted �������Խ���������������Ա�������Ҹ������Ա����û��Ĭ�ϲ�����
class Y : public XXX {
	//���������Զ���ʽ��Ϊ��������һ����������
private:
	int y;
};

int add(int, int) = delete;//����Ĭ�Ϻ���
double add(double a, double b) {
	return a + b;
}

class X_delete {
public:
	X_delete()=default;
	X_delete(const X_delete&) = delete;  // �����������캯��Ϊ deleted ����
	X_delete& operator = (const X_delete &) = delete; // ����������ֵ������Ϊ deleted ����
};

//http://www.ibm.com/developerworks/cn/aix/library/1212_lufang_c11new/
//ͨ������������Ա��������Ϊ defaulted ������������ʽָ��������Ϊ�ú����Զ�����Ĭ�Ϻ����塣
//ͨ������������Ϊ deleted ���������Խ���ĳЩ��������ת�����߲�����
int main(int argc,char* argv[])
{
	X x;
	x.show();
	X hehe(1024);
	hehe.show();

	XXX *xxx = new Y;
	delete xxx;

	//cout << add(1, 3) << endl;    // ���󣬵����� deleted ���� add(int, int) 
	cout << add(1.2, 1.3) << endl;
	X_delete x1;
	//X_delete x2 = x1;   // ���󣬿������캯��������
	X_delete x3;
	//x3 = x1;     // ���󣬿�����ֵ������������
	return 0;
}