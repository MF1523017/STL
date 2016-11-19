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

//remove�㷨ɾ����ʱ�򲢲���������ɾ������Ϊ��������
void testRemove()
{
	int a[10] = { 4,4,4,90,78,6,7,8,4,10 };
	//std::nth_element(std::begin(a), std::begin(a) + 4, std::end(a), compareA);//��ȻĬ��������
	//display(a);
	vector<int> vs(a,a+10);
	std::cout << "before remove " << std::endl;
	display(vs);// 4,1,54,90,78,6,7,8,4,10
	std::cout << "vs size is " << vs.size() << std::endl;//10

#if 0
	//��װɾ��
	std::remove(vs.begin(), vs.end(), 4);
	std::cout << "after remove " << std::endl;
	display(vs);// 1,54,90,78,6,7,8,0��4,10 ��Ȼ4��ɾ���ˣ�����������10��Ԫ�أ�ĩβΪ0
	std::cout << "vs size is " << vs.size() << std::endl;//10
#endif
#if 0
	//����ɾ��
	vs.erase(std::remove(vs.begin(), vs.end(), 4));
	std::cout << "after erase-remove " << std::endl;
	display(vs);
	std::cout << "vs size is " << vs.size() << std::endl;//9
#endif
	//unique
	vector<int>::iterator it=std::unique(vs.begin(), vs.end());
	//std::cout << " the last element not removed is " << (*it)<<std::endl;
	std::cout << "after unique " << std::endl;//ֻ��ɾ������������ֵ
	display(vs);//4,4,4,90,78,6,7,8,4,10 
	vs.resize(std::distance(vs.begin(), it));
	
	std::cout << "after real unique " << std::endl;
	display(vs);//4,90,78,6,7,8,4,10
}
//��ɾ������ָ�������ʹ��remove��һ���㷨ʱҪ�ر�С�ģ��п���ָ��ָ��Ķ�̬�ڴ潫��Զ�����ͷ�
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
	vptr.erase(std::remove_if(vptr.begin(), vptr.end(), isX4));//��Ȼɾ����ָ�룬����ָ��ָ��Ķ�̬�ڴ�û���ͷš�
	//display(vptr);

}

//transform�㷨
void testTransform()
{
	vector<int> tf(10, 10);
	vector<int> half;
	half.reserve(10);
	std::transform(tf.begin(), tf.end(), std::back_inserter(half), halfValue);
	display(half);
}

//���ֲ�ͬ�������㷨�����ؿ���
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
	//std::nth_element(std::begin(a), std::begin(a) + 4, std::end(a), compareA);//��ȻĬ��������
	//display(a);
	vector<Point> vs;
	for (auto i : a)
	{
		vs.push_back(Point(i, 100 - i));
	}
	std::cout << "before sort "<<std::endl;
	display(vs);
	//std::sort(vs.begin(), vs.end(),compareX);//�������Ƕ����˱Ƚ�X�Ĵ�С��������
	//std::partial_sort(vs.begin(), vs.begin() + 4, vs.end(), compareX);//ֻ��ǰ�ĸ����������
	//std::nth_element(vs.begin(), vs.begin() + 4, vs.end(), compareX);//����ǰ�ĸ�XС�ĵĵ㣬����ģ����Ǳ������������������
	std::partition(vs.begin(), vs.end(), isLess10);//��XС��10�Ķ�����ǰ�棬����
	std::cout << "after sort "<<std::endl;
	display(vs);
}