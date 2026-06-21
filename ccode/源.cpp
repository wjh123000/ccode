#include <iostream>
using namespace std;
#include <string>

//多态

/*
class Animal {
public:

	virtual void speak() {
		cout << "Animal::speak" << endl;
	}
};


class Cat : public Animal {
public:
	virtual void speak() {
		cout << "Cat::speak" << endl;
	}
};

class Dog : public Animal {
public:
	void speak() {
		cout << "Dog::speak" << endl;
	}
};


//允许父类的指针或者引用指向子类对象
//地址早绑定：编译阶段就确定函数地址
//如果想执行要猫说话，函数地址不能提前绑定，必须等到运行阶段才能确定函数地址，这就是地址晚绑定
void doSpeak(Animal& animal) {
	animal.speak();
}

void test01() {
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

void test02() {
	cout << sizeof(Animal) << endl;
}

int main() {
	test01();
	test02();
	return 0;
}
*/




//实现计算器
/*
class Calculator {
public:

	int getResult(string oper) {
		if (oper == "+") {
			return m_num1 + m_num2;
		}
		else if (oper == "-") {
			return m_num1 - m_num2;
		}
		else if (oper == "*") {
			return m_num1 * m_num2;
		}
		return 0;
	}
	int m_num1;
	int m_num2;

};



void test01() {
	Calculator c;
	c.m_num1 = 10;
	c.m_num2 = 5;
	cout << c.getResult("+") << endl;
	cout << c.getResult("-") << endl;
	cout << c.getResult("*") << endl;
}

//利用多态实现计算器

class AbstractCalculator {
public:

	virtual int getResult() {
		return 0;
	}

	int m_num1;
	int m_num2;
};

class AddCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_num1 + m_num2;
	}
};

class SubCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_num1 - m_num2;
	}
};

class MulCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_num1 * m_num2;
	}
};

void test02() {
	AbstractCalculator* ptr = new AddCalculator;
	ptr->m_num1 = 10;
	ptr->m_num2 = 5;
	cout << ptr->getResult() << endl;
	delete ptr;

	AbstractCalculator* ptr2 = new SubCalculator;
	ptr2->m_num1 = 10;
	ptr2->m_num2 = 5;
	cout << ptr2->getResult() << endl;
	delete ptr2;

	AbstractCalculator* ptr3 = new MulCalculator;
	ptr3->m_num1 = 10;
	ptr3->m_num2 = 5;
	cout << ptr3->getResult() << endl;
	delete ptr3;
}


int main() {
	//test01();
	test02();

	return 0;
}
*/



//纯虚函数和抽象类

/*
class Base {
public:
	virtual void func() = 0; //纯虚函数


};

class Son : public Base {
public:
	void func() {
		cout << "Son::func" << endl;
	}

};

void test01() {
	//Base base;
	//Base* base = new Base; //抽象类不能实例化对象

	Base* base = new Son();//抽象类的子类必须重写父类的纯虚函数，否则子类也是抽象类，不能实例化对象
	base->func();

	delete base;
}



int main() {
	test01();
	return 0;
}


*/




/*
class AbstractDrink {
public:

	virtual void Boil() = 0;

	virtual void Brew() = 0;

	virtual void Pour() = 0;

	virtual void Add() = 0;

	void makeDrink() {
		Boil();
		Brew();
		Pour();
		Add();
	}

};

class Coffee : public AbstractDrink {
public:
	void Boil() {
		cout << "Boil water" << endl;
	}
	void Brew() {
		cout << "Brew coffee" << endl;
	}
	void Pour() {
		cout << "Pour coffee" << endl;
	}
	void Add() {
		cout << "Add sugar and milk" << endl;
	}


};

class Tea : public AbstractDrink {
public:
	void Boil() {
		cout << "Boil water" << endl;
	}
	void Brew() {
		cout << "Brew tea" << endl;
	}
	void Pour() {
		cout << "Pour tea" << endl;
	}
	void Add() {
		cout << "Add lemon" << endl;
	}

};

void doWork(AbstractDrink& drink) {
	drink.makeDrink();
	delete& drink;
}


void test01() {
	doWork(*new Coffee);
	doWork(*new Tea);
}


int main() {
	test01();

	return 0;
}

*/



/*
class Animal {
public:

	Animal() {
		cout << "Animal::Animal()" << endl;
	}
	//virtual ~Animal() {
	//	cout << "Animal::~Animal()" << endl;
	//}

	virtual ~Animal() = 0; //纯虚析构函数

	virtual void speak() = 0;

};

Animal::~Animal() {
	cout << "Animal::~Animal()" << endl;
}

class Cat : public Animal {
public:

	Cat(string name) {
		cout << "Cat::Cat(string name)" << endl;
		m_name = new string(name);
	}

	~Cat() {
		cout << "Cat::~Cat()" << endl;
		if (m_name != nullptr) {
			delete m_name;
			m_name = nullptr;
		}
	}

	virtual void speak() {
		cout << *m_name << "Cat::speak" << endl;
	}

	string* m_name;

};


void test01() {
	Animal* animal = new Cat("Tom");
	animal->speak();

	//父类指针在析构时不会调用子类的析构函数，导致子类的资源无法释放，造成内存泄漏
	delete animal;

}


int main() {
	test01();
	return 0;
}


*/

class CPU {
public:
	virtual void calculate() = 0;
};

class VideoCard {
public:
	virtual void display() = 0;
};

class Memory {
public:
	virtual void storage() = 0;
};

class Computer {
public:
	Computer(CPU* m_cpu, VideoCard* m_vc, Memory* m_mem) {
		cpu = m_cpu;
		vc = m_vc;
		mem = m_mem;
	}
	~Computer() {
		if (cpu != nullptr) {
			delete cpu;
			cpu = nullptr;
		}
		if (vc != nullptr) {
			delete vc;
			vc = nullptr;
		}
		if (mem != nullptr) {
			delete mem;
			mem = nullptr;
		}
	}

	void work() {
		cpu->calculate();
		vc->display();
		mem->storage();
	}


private:
	CPU* cpu;
	VideoCard* vc;
	Memory* mem;
};

class IntelCPU : public CPU {
public:
	void calculate() {
		cout << "IntelCPU::calculate" << endl;
	}
};
class IntelVideoCard : public VideoCard {
public:
	void display() {
		cout << "IntelVideoCard::display" << endl;
	}
};
class IntelMemory : public Memory {
public:
	void storage() {
		cout << "IntelMemory::storage" << endl;
	}
};


class LenovoCPU : public CPU {
public:
	void calculate() {
		cout << "LenovoCPU::calculate" << endl;
	}
};
class LenovoVideoCard : public VideoCard {
public:
	void display() {
		cout << "LenovoVideoCard::display" << endl;
	}
};
class LenovoMemory : public Memory {
public:
	void storage() {
		cout << "LenovoMemory::storage" << endl;
	}
};


void test01() {
	CPU* intelCpu = new IntelCPU;
	VideoCard* intelVc = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	Computer* computer1 = new Computer(intelCpu, intelVc, intelMem);
	computer1->work();
	delete computer1;

	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

}

int main() {
	test01();
	return 0;
}
