#include<iostream>
using namespace std;
#include<fstream>



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
	char buf2[1024] = { 0 };
	while (ifs.getline(buf2, sizeof(buf2))) {
		cout << buf2 << endl;
	}

	ifs.close();
}

int main() {
	test01();
	test02();

	return 0;
}