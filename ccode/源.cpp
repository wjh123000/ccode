#include<iostream>
using namespace std;

/*
class Person {
public:
	//1. 构造函数 进行初始化操作
	//可以有参数，可以重载
	Person() {
		cout << "Person()" << endl;
	}

	//2.析构函数 进行清理工作
	//只能有一个，不能重载
	~Person() {
		cout << "~Person()" << endl;
	}

	
};


//void test01() {
//	Person p; //调用无参构造函数
//}

int main() {
	//test01();
	Person p;
	//system("pause");
	return 0;
}
*/




/*
class Person {
public:
	//普通构造函数
	//
	Person() {
		cout << "Person()" << endl;

	}

	Person(int a) {
	 age=a;
		cout << "Person(int a)" << endl;

	}

	//拷贝构造函数
	Person(const Person& p) {
		cout << "Person(const Person& p)" << endl;
		//将传入的人身上所有属性拷贝到当前对象身上
		age = p.age;
	}

	~Person() {
		cout << "~Person()" << endl;
	}

	int age;

};

void test01() {
	//Person p; //调用无参构造函数
	//1.括号法

	//Person p;
	////调用默认参数时不用括号，调用有参构造函数时必须加括号
	////如加括号，编译器会认为这是一个函数声明，而不是对象的定义
	//Person p2(10);
	//Person p3(p2); //调用拷贝构造函数
	//cout << p2.age << endl;
	//cout << p3.age << endl;

	//2.显示法
	Person p1;
	Person p2 = Person(10); //调用有参构造函数
	Person p3 = Person(p2); //调用拷贝构造函数
	//Person(10)  ; //匿名对象，调用有参构造函数，当前执行行结束后，匿名对象会被销毁
	//不要利用拷贝构造函数初始化匿名对象
	//Person (p3) 等价于  Person p3;

	//3.隐式转换法
	Person p4 = 10; //调用有参构造函数，隐式转换法,相当于 Person p4 = Person(10);
	Person p5 = p4; //调用拷贝构造函数，隐式转换法,相当于 Person p5 = Person(p4);
}
*/






/*
class Person {
public:
	Person() {
		cout << "Person()" << endl;
	}

	Person(int age) {
		m_age = age;
		cout << "Person(int age)" << endl;
	}

	Person(const Person& p) {
		cout << "Person(const Person& p)" << endl;
		m_age = p.m_age;
	}


	~Person() {
		cout << "~Person()" << endl;
	}

	int m_age;

};

//1.用一个已经创建完毕的对象来初始化一个新对象
void test01() {
	Person p1(20);
	Person p2(p1); //调用拷贝构造函数
	cout << p2.m_age << endl;
}
//2.以值传递的方式给函数传参

void doWork(Person p) {

}

void test02() {
	Person p;
	doWork(p); //调用拷贝构造函数
}

//3.以值方式返回局部对象
Person doWork2() {
	Person p;
	return p; //调用拷贝构造函数
}

void test03() {
	Person p=doWork2();
}



int main() {
	//test01();
	//test02();
	test03();

	return 0;
}
*/


/*
//1.当我们没有定义任何构造函数时，编译器会自动提供一个默认的无参构造函数和一个默认的拷贝构造函数和析构函数

class Person {
public:
	Person() {
		cout << "Person()" << endl;
	}

	Person(int age) {
		m_age = age;
		cout << "Person(int age)" << endl;
	}

	//Person(const Person& p) {
	//	cout << "Person(const Person& p)" << endl;
	//	m_age = p.m_age;
	//}
	

	~Person() {
		cout << "~Person()" << endl;
	}

	int m_age;

};

void test01() {
	Person p;
	p.m_age = 10;
	Person p2(p); //调用拷贝构造函数
	cout << p2.m_age << endl;
}

void test02() {

}

int main() {
	//test01();
	test02();
	return 0;
}
*/



//深拷贝和浅拷贝
/*
//浅拷贝
class Person {
public:
	Person() {
		cout << "Person()" << endl;
	}

	Person(int age, int height) {
		m_age = age;
		m_Height = new int(height);

	}

	~Person() {
		//释放堆区数据
		if (m_Height != NULL) {
			delete m_Height;
			m_Height = NULL;
		}
		cout << "~Person()" << endl;
	}

	int m_age;
	int* m_Height;
};
//复制指针，导致两个对象的指针指向同一块堆区数据，造成数据混乱和重复释放，产生报错
//浅拷贝的问题时堆区内存重复释放，解决办法是深拷贝，在拷贝构造函数中重新开辟堆区内存，并将数据进行复制
void test01() {
	Person p1(18,160);
	cout << p1.m_age << endl;
	cout << *p1.m_Height << endl;

	Person p2(p1);
	cout << p2.m_age << endl;
	cout << *p2.m_Height << endl;
}






int main() {
	test01();
	return 0;
}

*/


//深拷贝
//在拷贝构造函数中重新开辟堆区内存，并将数据进行复制
class Person {
public:
	Person() {
		cout << "Person()" << endl;
	}

	Person(int age, int height) {
		m_age = age;
		m_Height = new int(height);

	}

	Person(const Person& p) {
		cout << "Person(const Person& p)" << endl;
		m_age = p.m_age;
		//编译器默认：m_Height = p.m_Height; //浅拷贝
		//深拷贝
		m_Height = new int(*p.m_Height);
	}

	~Person() {
		//释放堆区数据
		if (m_Height != NULL) {
			delete m_Height;
			m_Height = NULL;
		}
		cout << "~Person()" << endl;
	}

	int m_age;
	int* m_Height;
};

void test01() {
	Person p1(18, 160);
	cout << p1.m_age << endl;
	cout << *p1.m_Height << endl;

	Person p2(p1);
	cout << p2.m_age << endl;
	cout << *p2.m_Height << endl;
}

int main() {
	test01();
	return 0;
}

