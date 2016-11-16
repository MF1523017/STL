#pragma once
#include<map>
#include<iostream>

void testMapRemove();
void mapInsert();
class Widget
{
	friend std::ostream &operator<<(std::ostream &os, const Widget &rhs);
public:
	Widget() :_weight(0) {};
	Widget(double w) :_weight(w) {}
	Widget& operator=(double w) { _weight = w; };
private:
	double _weight;

};
std::ostream &operator<<(std::ostream &os, const Widget &rhs);
