#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>//算法头文件


void test01()
{
	vector<int>a;
	a.push_back(10);
	a.push_back(20);
	for_each(a.begin(), a.end(), [](int val) {
		cout << val << endl;
		});
}



int main()
{
	test01();


	return 0;
}