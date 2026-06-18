#include<iostream>
using namespace std;
#include "Point.h"
#include "Circle.h"

//class Point {
//public:
//	void setPoint(int x, int y) {
//		m_X = x;
//		m_Y = y;
//	}
//
//	int getX() {
//		return m_X;
//	}
//
//	int getY() {
//		return m_Y;
//	}
//
//private:
//	int m_X;//x坐标
//	int m_Y;//y坐标
//};
//
//
//class Circle {
//public:
//	void setR(int r) {
//		m_R = r;
//	}
//	int getR() {
//		return m_R;
//	}
//	void setCenter(Point center) {
//		m_Center = center;
//	}
//	Point getCenter() {
//		return m_Center;
//	}
//
//private:
//	int m_R;//半径
//
//	Point m_Center;//圆心坐标
//
//};


void isinCircle(Circle circle, Point point) {
	// Implementation for checking if a point is inside a circle
	int dis = (point.getX() - circle.getCenter().getX()) * (point.getX() - circle.getCenter().getX()) +
		(point.getY() - circle.getCenter().getY()) * (point.getY() - circle.getCenter().getY());
	if (dis < circle.getR() * circle.getR()) {
		cout << "Point is inside the circle." << endl;
	}
	else if (dis == circle.getR() * circle.getR()) {
		cout << "Point is on the circle." << endl;
	}
	else {
		cout << "Point is outside the circle." << endl;
	}
}


int main() {
	Point point;
	point.setPoint(1, 2);
	Circle circle;
	circle.setR(5);
	circle.setCenter(point);

	isinCircle(circle, point);

	return 0;
}
