#include <iostream>
using namespace std;


//成员变量和成员函数分开存储
class Person {

	int m_A;

	static int m_B; // 静态成员变量不占用对象内存

	void func() {
	}
};

int Person::m_B = 0; // 静态成员变量需要在类外进行初始化

void test01() {
	Person p;

	cout << sizeof(p) << endl; // 1
}

void test02() {
	Person p;
	cout<<sizeof(p)<<endl;
}


int main() {
	test01();
	return 0;
}