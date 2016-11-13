#ifndef COMMON_H
#define COMMON_H
#include<iostream>
template<typename T>
void display(T &tmp)
{
	for (auto item : tmp)
		std::cout << "the key is "<<item.first << " the value is "<<item.second<<std::endl;
	std::cout << std::endl;
}
#endif // !COMMON_H