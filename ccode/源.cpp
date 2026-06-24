#include <iostream>
using namespace std;
#include <string>


/*
template<typename T>//声明一个模板
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void swap(auto& a, auto& b) {
	auto temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 10;
	int b = 20;
	swap(a, b);
	cout << "a = " << a << ", b = " << b << endl;
	double c = 1.5;
	double d = 2.5;
	mySwap<double>(c, d);
	cout << "c = " << c << ", d = " << d << endl;
}

int main() {
	test01();
	return 0;
}

*/




/*
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}


template<typename T>
void sort(T arr[],int len) {
	for (int i = 0;i < len;i++) {
		for (int j = len - 1;j > i;j--) {
			if (arr[j-1] > arr[j]) {
				mySwap(arr[j-1], arr[j]);
			}
		}
	}
}

template<typename T>
void printArray(T arr[], int len) {
	for (int i = 0;i < len;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}



void test01() {
	char charArr[]="fljkalfga";
	int len = strlen(charArr);
	cout << len << '\n';
	sort(charArr, len);
	printArray(charArr, len);
}

void test02() {
	int intArr[] = { 1, 3, 5, 2, 4 };
	int len = sizeof(intArr) / sizeof(int);
	sort(intArr, len);
	printArray(intArr, len);
}

int main() {
	test01();
	test02();
	return 0;
}
*/




/*
class Person {
public:
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	//bool operator==(const Person& p)const {
	//	if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}
	//}

	string m_Name;
	int m_Age;
};

//bool myCompare(Person a, Person b) {
//	cout << "ahdfka" << endl;
//	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

template<typename T>
bool myCompare(T a, T b) {
	return a == b;
}

//利用具体化Person的版本，来实现对Person类型的比较，具体化优先调用
template<> bool myCompare(Person a, Person b) {
	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age) {
		return true;
	}
	else {
		return false;
	}
}



void test01() {
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);
	if (ret == true) {
		cout << "a == b" << endl;
	}
	else {
		cout << "a != b" << endl;
	}
}

void test02() {
	Person p1("Tom", 20);
	Person p2("Tom", 20);
	bool ret = myCompare(p1, p2);
	if (ret == true) {
		cout << "p1 == p2" << endl;
	}
	else {
		cout << "p1 != p2" << endl;
	}

}



int main() {
	//test01();
	test02();
	return 0;
}
*/



//类模板
/*
template<class T1,class T2>
class Person 
{
public:

	Person(T1 name, T2 age) 
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson() 
	{
		cout << "Name: " << this->m_Name << ", Age: " << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};



void test01() 
{
	Person<string, int> p1("Tom", 20);
	p1.showPerson();
}


int main() 
{
	test01();

	return 0;
}
*/

//类模板与函数模板的区别


/*
template<class NameType ,class AgeType=int>
class Person
{
public:

	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "Name: " << this->m_Name << ", Age: " << this->m_Age << endl;
	}


	NameType m_Name;
	AgeType m_Age;
};

//1.类模板没有自动类型推导的使用方式，必须要指定类型
void test01()
{
	//Person p("Tom", 20); //错误，类模板没有自动类型推导,17可以
	Person<string> p("Tom", 20);
	p.showPerson();
}

//2.类模板在模板参数列表中可以有默认参数
void test02()
{
	Person<string, int>p("Tom", 20);
}

int main()
{
	//test01();
	test02();
	return 0;
}
*/





/*
class Person
{
public:
	void showPerson1() 
	{
		cout << "Perwsonal showPerson" << endl;
	}
};

class Person2
{
public:
	void showPerson2() 
	{
		cout << "Perwsonal showPerson2" << endl;
	}
};
//类模板中成员函数在调用是才创建，类模板中成员函数的创建依赖于类模板的对象
template<class T>
class MyClass
{
public:

	T obj;

	void fun1()
	{
		obj.showPerson1();
	}

	void fun2()
	{
		obj.showPerson2();
	}
};


void test01()
{
	MyClass<Person>m;
	m.fun1();
	MyClass<Person2>m2;
	m2.fun2();
}

int main()
{
	test01();

	return 0;
}
*/



//类模板对象做函数参数

/*
template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "Name: " << this->m_Name << ", Age: " << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};


//1.指定传入类型
void printPerson1(Person<string, int>& p)
{
	p.showPerson();
}


void test01()
{

	Person<string, int>p("Tom", 20);
	printPerson1(p);

}


//2.参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;
}

void test02()
{
	Person<string, int>p("Tom", 20);
	printPerson2(p);
}

//3.整体模板化
template<class T>
void printPerson3(T& p)
{
	p.showPerson();
	cout << typeid(T).name() << endl;
}

void test03()
{
	Person<string, int>p("Tom", 20);
	printPerson3(p);
}


int main()
{
	test01();
	test02();
	test03();
	return 0;
}
*/



//类模板与继承


/*
template<class T>
class Base
{
	T m;
};

//派生类继承类模板，必须指定父类模板的类型
class Son :public Base<int>
{

};



void test01()
{
	Son s1;

}

//如果想灵活的指定父类模板的类型，可以将子类也设计为类模板
template<class T1,class T2>
class Son2 :public Base<T1>
{
public:
	Son2() {
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	T2 obj;
};

void test02()
{
	Son2<int, char> s2;
}


int main()
{
	//test01();
	test02();

	return 0;
}
*/



//类模板成员函数的类外实现


/*
template<class T1,class T2>
class Person
{
public:

	Person(T1 name, T2 age);


	void showPerson();

	T1 m_Name;
	T2 m_Age;

};

template<class T1,class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1,class T2>
void Person<T1, T2>::showPerson()
{
	cout << "Name: " << this->m_Name << ", Age: " << this->m_Age << endl;
}

void test01()
{
	Person <string, int>p("Tom", 20);
	p.showPerson();
}

int main()
{
	test01();

	return 0;
}
*/


//类模板的份文件编写

//template<class T1,class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	void showPerson();
//	T1 m_Name;
//	T2 m_Age;
//};

//template<class T1,class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template<class T1,class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "Name: " << this->m_Name << ", Age: " << this->m_Age << endl;
//}



//类模板分文件编写
/*

//法1，直接包含源文件
#include "person.cpp"

//法2，将.h和.cpp文件写到一起，将后缀名改为.hpp，直接包含.hpp文件
#include "person.hpp"

void test01()
{
	Person<string, int>p("Tom", 20);
	p.showPerson();
}



int main() 
{
	test01();

	return 0;
}


*/ 


//类模板与友元

/*

//让编译器提前知道这个类模板的存在
template<class T1, class T2>
class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "Name: " << p.m_Name << ", Age: " << p.m_Age << endl;
}

template<class T1,class T2>
class Person
{
	//1.全局函数在类内实现
	friend void printPerson(Person<T1,T2>& p) 
	{
		cout << "Name: " << p.m_Name << ", Age: " << p.m_Age << endl;
	}
	//2.全局函数在类外实现
	//加一个空模板参数列表<>，告诉编译器这个函数是一个模板函数
	//如果是全局函数类外实现，需要让编译器提前知道这个函数的存在
	friend void printPerson2<>(Person<T1, T2>& p);

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};



void test01()
{
	Person <string, int>p("Tom", 20);
	printPerson(p);
}

void test02()
{
	Person <string, int>p("Tom", 20);
	printPerson2(p);
}


int main()
{
	test01();
	test02();
	return 0;
}
*/



#include "MyArray.hpp"

void printArray(MyArray<int>& arr)
{
	for (int i = 0;i < arr.getSize();i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	MyArray<int>arr1(5);

	for (int i = 0;i < 5;i++)
	{
		arr1.Push_Back(i);
	}
	cout << arr1[1] << endl;
	printArray(arr1);
	cout << "容量为：" << arr1.getCapacity() << endl;

	//MyArray<int>arr2(arr1); //拷贝构造函数调用
	//
	//MyArray<int>arr3(100);
	//arr3 = arr1; //赋值运算符重载调用
}

int main()
{
	test01();
	return 0;
}



