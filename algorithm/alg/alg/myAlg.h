#pragma once
#include<iostream>
void testTransform();
void testSort();
void testRemove();
void testRemovePtr();
class Point
{
	friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
	friend bool operator<(const Point &lhs, const Point &rhs);
private:
	int _x;
	int _y;
public:
	Point(int x, int y) :_x(x), _y(y) {}
	Point() = default;
	int getX()const { return _x; }
	int getY()const { return _y; }

};
std::ostream &operator<<(std::ostream &os, const Point &rhs);
bool operator<(const Point &lhs, const Point &rhs);