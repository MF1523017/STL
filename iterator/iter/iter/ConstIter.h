#pragma once
#include<iostream>
#include<deque>
#include<algorithm>
using std::deque;
typedef deque<int>IntDeque;
typedef IntDeque::iterator Iter;
typedef IntDeque::const_iterator constIter;
//尽量用iterator 代替const_iterator

void testIter()
{
	IntDeque d(1);
	d.push_back(3);
	constIter ci(d.begin() + 1);
	//Iter i(ci);//错误，从const_iterator 到iterator 没有隐式转换
	Iter i(d.begin());
	std::advance(i, std::distance<constIter>(i, ci));//使用distance 和advance 将容器的const_iterator转换成 iterator
	std::cout << *i << std::endl;//输出3，i到达ci的位置，
	for (auto item : d)
		std::cout << item << " ";

}