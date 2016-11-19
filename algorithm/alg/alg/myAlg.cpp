#include"stdafx.h"
#include"myAlg.h"
#include"common.h"
#include<algorithm>
#include<vector>
#include<iostream>
#include<iterator>
using std::vector;
std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
	std::cout << rhs._x << " " << rhs._y<<std::endl;
	return os;
}
bool operator<(const Point &lhs, const Point &rhs)
{
	return true;
}
int halfValue(int i)
{
	return i / 2;
}

//remove算法删除的时候并不是真正的删除，因为他做不到
void testRemove()
{
	int a[10] = { 4,4,4,90,78,6,7,8,4,10 };
	//std::nth_element(std::begin(a), std::begin(a) + 4, std::end(a), compareA);//竟然默认排序了
	//display(a);
	vector<int> vs(a,a+10);
	std::cout << "before remove " << std::endl;
	display(vs);// 4,1,54,90,78,6,7,8,4,10
	std::cout << "vs size is " << vs.size() << std::endl;//10

#if 0
	//假装删除
	std::remove(vs.begin(), vs.end(), 4);
	std::cout << "after remove " << std::endl;
	display(vs);// 1,54,90,78,6,7,8,0，4,10 虽然4被删除了，但是它还是10个元素，末尾为0
	std::cout << "vs size is " << vs.size() << std::endl;//10
#endif
#if 0
	//真正删除
	vs.erase(std::remove(vs.begin(), vs.end(), 4));
	std::cout << "after erase-remove " << std::endl;
	display(vs);
	std::cout << "vs size is " << vs.size() << std::endl;//9
#endif
	//unique
	vector<int>::iterator it=std::unique(vs.begin(), vs.end());
	//std::cout << " the last element not removed is " << (*it)<<std::endl;
	std::cout << "after unique " << std::endl;//只能删除相邻连续的值
	display(vs);//4,4,4,90,78,6,7,8,4,10 
	vs.resize(std::distance(vs.begin(), it));
	
	std::cout << "after real unique " << std::endl;
	display(vs);//4,90,78,6,7,8,4,10
}
//在删除包含指针的容器使用remove这一类算法时要特别小心，有可能指针指向的动态内存将永远不被释放
bool isX4(const Point& rhs)
{
	return rhs.getX() == 4;
}
void testRemovePtr()
{
	vector<Point *>vptr;
	int a[10] = { 4,4,4,90,78,6,7,8,4,10 };
	for (auto i : a)
	{
		vptr.push_back(new Point(i, 100 - i));
	}
	vptr.erase(std::remove_if(vptr.begin(), vptr.end(), isX4));//虽然删除了指针，但是指针指向的动态内存没有释放。
	//display(vptr);

}

//transform算法
void testTransform()
{
	vector<int> tf(10, 10);
	vector<int> half;
	half.reserve(10);
	std::transform(tf.begin(), tf.end(), std::back_inserter(half), halfValue);
	display(half);
}

//几种不同的排序算法，慎重考虑
bool compareX(const Point &lhs, const Point &rhs)
{
	return lhs.getX() < rhs.getX();
}
bool compareA(int x, int y) { return x < y; }
bool isLess10(const Point &rhs)
{
	return rhs.getX() <10;
}
void testSort()
{
	int a[10] = { 4,1,54,90,78,6,7,8,9,0 };
	//std::nth_element(std::begin(a), std::begin(a) + 4, std::end(a), compareA);//竟然默认排序了
	//display(a);
	vector<Point> vs;
	for (auto i : a)
	{
		vs.push_back(Point(i, 100 - i));
	}
	std::cout << "before sort "<<std::endl;
	display(vs);
	//std::sort(vs.begin(), vs.end(),compareX);//这里我们定义了比较X的大小的排序函数
	//std::partial_sort(vs.begin(), vs.begin() + 4, vs.end(), compareX);//只对前四个点进行排序
	//std::nth_element(vs.begin(), vs.begin() + 4, vs.end(), compareX);//返回前四个X小的的点，无序的，但是编译器好像对它排序了
	std::partition(vs.begin(), vs.end(), isLess10);//将X小于10的都放在前面，无序
	std::cout << "after sort "<<std::endl;
	display(vs);
}