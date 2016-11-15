#pragma once
#include<vector>
#include<iostream>
using std::vector;
class Widget
{
	friend std::ostream& operator <<(std::ostream &os, const Widget &rhs);
public:
	Widget() :_length(0), _width(0) {};
	Widget(int l, int w) :_length(l), _width(w) {};
	virtual int getItem()const = 0;
	
	virtual int getLength()const { return _length; };
	virtual int getWidth()const{ return _width; };
private:
	int _length;
	int _width;
};

class SpecialWidget :public Widget
{
	friend std::ostream& operator <<(std::ostream &os, const SpecialWidget &rhs);
public:
	//virtual int getLength()const;
	//virtual int getWidth()const;
	SpecialWidget(int l, int w, int c) :Widget(l, w), _color(c) {};
	virtual int getItem()const { return _color; };
private:
	int _color;
};
class SpecialWidget1 :public Widget
{
public:
	SpecialWidget1(int l, int w, int s) :Widget(l, w), _size(s) {};
	virtual int getItem()const { return _size; };
private:
	int _size;
};
void testReserve();
void testVec();

std::ostream& operator <<(std::ostream &os, const Widget &rhs);
std::ostream& operator <<(std::ostream &os, const SpecialWidget &rhs);
std::ostream& operator <<(std::ostream &os, const SpecialWidget1 &rhs);