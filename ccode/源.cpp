#include<iostream>
using namespace std;
#include<fstream>
#include<string>


void test01() {
	//ofstream ofs;
	//ofs.open("text.txt", ios::out);
	//ofs << "姓名：张三" << endl;
	//ofs << "姓别：男" << endl;
	//ofs.close();
}

void test02() {
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}
	// 读取文件内容
	// 方式1：按块读取
	//char buf[1024] = { 0 };
	//while(ifs >> buf) {
	//	cout << buf << endl;
	//}

	// 方式2：按行读取
	//char buf2[1024] = { 0 };
	//while (ifs.getline(buf2, sizeof(buf2))) {
	//	cout << buf2 << endl;
	//}

	// 方式3：按字符串读取
	//string buf;
	//while (getline(ifs, buf)) {
	//	cout << buf << endl;
	//}

	// 方式4：按字符读取
	char c;
	while ((c=ifs.get()) != EOF) {
		cout << c;
	}

	ifs.close();
}

class Person {
public:
	char m_Name[64];
	int m_Age;
};
// 二进制文件写入
void test03() {
	ofstream ofs("person.txt", ios::out | ios::binary);
	Person p={"张三", 20};
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();
}
// 二进制文件读取
void test04() {
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << p.m_Name << " " << p.m_Age << endl;
	ifs.close();
}

int main() {
	test04();

	return 0;
}