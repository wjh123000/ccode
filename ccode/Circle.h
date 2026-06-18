#pragma once
#include<iostream>
#include "Point.h"
class Circle {
public:
	void setR(int r);
	int getR();
	void setCenter(Point center);
	Point getCenter();

private:
	int m_R;//半径

	Point m_Center;//圆心坐标

};