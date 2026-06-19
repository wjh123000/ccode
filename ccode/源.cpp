#include <iostream>
using namespace std;

class Person {
public:
	//1.当形参和成员变量同名时，用于区分成员变量和形参，必须在成员变量前加上this指针
	Person(int age) {
		//this指针：指向调用成员函数的对象的指针
		this->age = age;
	}

	Person PersonAddAge(Person& p) {//应用传递，传递对象的地址，防止对象的拷贝构造函数被调用，造成资源的浪费
		this->age += p.age;
		return *this;
	}

	int age;

};



void test01() {
	Person p(20);
	cout << p.age << endl;
}
void test02() {
	Person p1(10);
	Person p2(10);
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);//链式编程，连续调用成员函数
	cout << p2.age << endl;
	
}


int main() {
	test02();
	return 0;
}