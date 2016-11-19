#ifndef COMMON_H
#define COMMON_H
#include<iostream>
template<typename T>
void display(T &tmp)
{
	
	for (auto item : tmp)
		std::cout << item << " ";
	std::cout << std::endl;
}
#endif // !COMMON_H