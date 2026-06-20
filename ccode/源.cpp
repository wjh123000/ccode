#include <iostream>
using namespace std;
#include <string>

//运算符重载
//加号

/*
class Person {
public:

	//Person operator+ (Person& p) {
	//	Person temp;
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}


public:
	int m_A;
	int m_B;
};


Person operator+ (Person& p1, Person& p2) {
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}


void test01() {
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;
	Person p3 = p1 + p2;

	cout << p3.m_A << endl;
	cout << p3.m_B << endl;
}

int main() {
	test01();
	return 0;
}

*/


//重载<<运算符
//便于输出

/*
class Person{
public:
	friend ostream& operator<<(ostream& cout, Person& p);
	friend void test01();
	//void operator<<(Person& p) {

	//}


private:
	int m_A;
	int m_B;

};

//无法进行链式输出
//void operator<<(ostream& cout, Person& p) {
//	cout << p.m_A << " " << p.m_B;
//}

ostream& operator<<(ostream& cout, Person& p) {
	cout << p.m_A << " " << p.m_B;
	return cout;
}


void test01() {
	Person p;
	p.m_A = 10;
	p.m_B = 10;
	cout << p<<endl;

}


int main() {
	test01();


	return 0;
}

*/




//递增运算符重载

/*
class MyInteger {
	friend ostream& operator<<(ostream& cout, const MyInteger& myint);
public:
	MyInteger() {
		m_num = 0;
	}

	//重载++
	//前置++
	MyInteger& operator++() {
		m_num++;
		return *this;
	}

	//后置++
	MyInteger operator++(int) {
		MyInteger temp = *this;//保存当前对象的值
		m_num++;//当前对象的值加1
		return temp;//返回保存的值
	}

private:
	int m_num;
};

ostream& operator<<(ostream& cout,const MyInteger& myint) {
	cout << myint.m_num;
	return cout;
}


void test01() {
	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
	cout << myint++ << endl;
	cout << myint << endl;
}

int main() {
	test01();

	return 0;
}
*/



//赋值运算符重载

/*
class Person {
public:
	Person(int age) {
		m_age = new int(age);
	}

	~Person() {
		if (m_age != nullptr) {
			delete m_age;
		}
		m_age = nullptr;
	}

	//重载赋值运算符
	Person& operator=(Person& p) {
		//先判断是否有年龄，如果有，先释放掉
		if (m_age != nullptr) {
			delete m_age;
		}
		m_age = nullptr;//防止野指针
		m_age = new int(*p.m_age);//深拷贝
		return *this;
	}

	int* m_age;
};





void test01() {
	Person p1(18);
	Person p2(20);
	cout << *p1.m_age << endl;
	cout << *p2.m_age << endl;
	p2 = p1;
	cout << *p2.m_age << endl;
	Person p3(30);
	p3 = p2 = p1;
	cout << *p3.m_age << endl;
}

int main() {
	test01();

	//int a = 10;
	//int b = 20;
	//int c = 30;
	//c = b = a;
	//cout << a << ' ' << b << ' ' << c << endl;
	return 0;
}

*/


//重载关系运算符

/*
class Person {
public:
	Person(string name, int age) {
		m_Name = name;
		m_Age = age;
	}

	//重载==运算符
	bool operator==(const Person& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!=(const Person& p) {
		if (this->m_Name != p.m_Name || this->m_Age != p.m_Age) {
			return true;
		}
		else {
			return false;
		}
	}


public:
	string m_Name;
	int m_Age;
};


void test01() {
	Person p1("Tom", 18);
	Person p2("Tom", 19);

	if (p1 == p2) {
		cout << "p1==p2" << endl;
	}
	else {
		cout << "p1!=p2" << endl;
	}

	if (p1 != p2) {
		cout << "p1!=p2" << endl;
	}
	else {
		cout << "p1==p2" << endl;
	}
}


int main() {
	test01();

	return 0;
}
*/


//函数调用运算符重载
//仿函数


class MyPrint {
public:

	void operator()(string text) {
		cout << text << endl;
	}

};


void MyPrint02(string text) {
	cout << text << endl;
}




void test01() {
	MyPrint myprint;
	myprint("Hello World");//使用起来非常类似函数调用
	MyPrint02("Hello World");
}

//加法类

class MyAdd {
public:
	int operator()(int num1, int num2) {
		return num1 + num2;
	}
};

void test02() {
	MyAdd myadd;
	int result = myadd(10, 20);
	cout << "result=" << result << endl;
}

int main() {
	test01();
	test02();

	return 0;
}
