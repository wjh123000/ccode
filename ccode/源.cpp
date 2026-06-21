#include <iostream>
using namespace std;
#include <string>

//继承

//class Java {
//public:
//
//	void header() {
//		cout << "Java header" << endl;
//	}
//
//	void footer() {
//		cout << "Java footer" << endl;
//	}
//
//	void left() {
//		cout << "Java left" << endl;
//	}
//
//	void content() {
//		cout << "Java content" << endl;
//	}
//
//
//};
//
//
//class Python {
//public:
//
//	void header() {
//		cout << "Python header" << endl;
//	}
//
//	void footer() {
//		cout << "Python footer" << endl;
//	}
//
//	void left() {
//		cout << "Python left" << endl;
//	}
//
//	void content() {
//		cout << "Python content" << endl;
//	}
//
//
//};
//
//class Cpp {
//public:
//
//	void header() {
//		cout << "c++ header" << endl;
//	}
//
//	void footer() {
//		cout << "c++ footer" << endl;
//	}
//
//	void left() {
//		cout << "c++ left" << endl;
//	}
//
//	void content() {
//		cout << "c++ content" << endl;
//	}
//
//
//};


/*
class BasePage {
public:
	void header() {
		cout << "header" << endl;
	}

	void footer() {
		cout << "footer" << endl;
	}

	void left() {
		cout << "left" << endl;
	}


};
//继承,减少代码冗余
//语法：class 子类 : 继承方式 父类
//子类也称为派生类，父类也称为基类

class Java : public BasePage {
public:
	void content() {
		cout << "Java content" << endl;
	}
};

class Python : public BasePage {
public:
	void content() {
		cout << "Python content" << endl;
	}
};

class Cpp : public BasePage {
public:
	void content() {
		cout << "c++ content" << endl;
	}
};


void test01() {
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	Cpp cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();
}


int main() {
	test01();
	return 0;
}

*/



/*
class Base {
public:
	static int m_A;
	static void func() {
		cout << "Base func" << endl;
	}

};
int Base::m_A = 100;
class Son : public Base {
public:
	static int m_A;
	static void func() {
		cout << "Son func" << endl;
	}
};
int Son::m_A = 200;

void test01() {
	Son s;
	cout << s.m_A << endl;//200
	cout << s.Base::m_A << endl;//100

	cout << Son::Base::m_A << endl;//100
	cout << Son::m_A << endl;//200
}

void test02() {
	Son s;
	s.func();//Son func
	s.Base::func();//Base func


	Son::func();
	Son::Base::func();
}


int main() {
	//test01();
	test02();
	return 0;
}

*/




//菱形继承
class Animal {
public:
	int m_Age;
};

//利用虚继承解决菱形继承问题
class Sheep : virtual public Animal {

};


class Tuo : virtual public Animal {

};


class SheepTuo : public Sheep, public Tuo {

};



void test01() {
	SheepTuo st;
	//st.m_Age = 18;//错误，编译器无法确定访问哪个父类中的m_Age
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 20;
	cout << st.Sheep::m_Age << endl;//18
	cout << st.Tuo::m_Age << endl;//20

	//这份数据只要有一份就够了，浪费内存空间

}


int main() {
	test01();

	return 0;
}

