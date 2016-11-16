#pragma once
#include<iostream>
#include<deque>
#include<algorithm>
using std::deque;
typedef deque<int>IntDeque;
typedef IntDeque::iterator Iter;
typedef IntDeque::const_iterator constIter;
//������iterator ����const_iterator

void testIter()
{
	IntDeque d(1);
	d.push_back(3);
	constIter ci(d.begin() + 1);
	//Iter i(ci);//���󣬴�const_iterator ��iterator û����ʽת��
	Iter i(d.begin());
	std::advance(i, std::distance<constIter>(i, ci));//ʹ��distance ��advance ��������const_iteratorת���� iterator
	std::cout << *i << std::endl;//���3��i����ci��λ�ã�
	for (auto item : d)
		std::cout << item << " ";

}