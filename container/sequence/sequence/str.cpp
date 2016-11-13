#include"str.h"
void testAssign()
{
	string v1, v2("hello,world!");
	v1.assign(v2.begin() + v2.size() / 2, v2.end());
	std::cout << "v1 is " << v1<<std::endl
		<< "v2 is" << v2 << std::endl;
}