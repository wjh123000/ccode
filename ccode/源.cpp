#include <iostream>
using namespace std;
#include <string>

//全局函数做友元
/*
class Building {
	//goodGay是Building的好朋友，可以访问Building中的私有成员
	friend void goodGay(Building* building);
public:
	Building() {
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
	

public:
	string m_SittingRoom;

private:

	string m_BedRoom;

};

void goodGay(Building* building) {
	cout << building->m_SittingRoom << endl;
	cout << building->m_BedRoom << endl;
}

void test01() {
	Building building;
	goodGay(&building);

}


void test02() {
	
}

int main() {
	test01();
	test02();
	return 0;
}
*/





//类做友元

/*
class Building;

class GoodGay {
public:
	void visit();
	GoodGay();
	Building* building;
};

class Building {
	//goodGay是Building的好朋友，可以访问Building中的私有成员
	friend class GoodGay;

public:
	Building();
public:
	string m_SittingRoom;

private:
	string m_BedRoom;

};

Building::Building() {
	m_SittingRoom = "Sitting Room";
	m_BedRoom = "Bedroom";

}

GoodGay::GoodGay() {
	building = new Building;
}

void GoodGay::visit() {
	cout << building->m_SittingRoom << endl;
	cout << building->m_BedRoom << endl;
}

void test01() {
	GoodGay gg;
	gg.visit();

}


int main() {
	test01();

	return 0;
}
*/




//成员函数做友元
class Building;
class GoodGay {
public:

	GoodGay();

	void visit();

	Building* building;

};

class Building {
public:
	friend void GoodGay::visit();
	
	Building();




public:

	string m_SittingRoom;

private:
	string m_BedRoom;
};


GoodGay::GoodGay() {
	building = new Building;
}

Building::Building() {
	m_SittingRoom = "Sitting Room";
	m_BedRoom = "Bed Room";
}

void GoodGay::visit() {
	cout << building->m_SittingRoom << endl;
	cout << building->m_BedRoom << endl;
}



void test01() {
	GoodGay gg;
	gg.visit();
}

int main() {
	test01();
	return 0;
}
