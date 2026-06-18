#pragma once  // 防止重复包含
#include<iostream>
using namespace std;

class Point {
public:
	void setPoint(int x, int y);

	int getX();

	int getY();

private:
	int m_X;//x坐标
	int m_Y;//y坐标
};