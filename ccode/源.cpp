#include <iostream>
using namespace std;

class Person {
public:
	void showClassName() {
		cout << "Person Class" << endl;
	}

	void showPersonAge() {
		cout << m_Age << endl;
	}

	int m_Age;
};



void test01() {
	Person* p=NULL;

	p->showClassName(); // 通过空指针访问成员函数是允许的, 因为成员函数并不访问成员属性
	//p->showPersonAge(); // 通过空指针访问成员属性是非法的, 因为成员函数访问成员属性时需要this指针, 而this指针指向对象本身, 但是p是一个空指针, 没有指向任何对象, 所以会导致程序崩溃

}


int main() {
	test01();
	return 0;
}