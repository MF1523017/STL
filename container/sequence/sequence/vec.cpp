#include"vec.h"
#include"common.h"
std::ostream& operator <<(std::ostream &os, const Widget &rhs)
{
	os << rhs.getLength() << " " << rhs.getWidth() << " " << rhs.getItem();
	return os;
}
#if 0
std::ostream& operator <<(std::ostream &os, const SpecialWidget &rhs)
{
	os << rhs.getLength() << " " << rhs.getWidth() <<" "<<rhs.getItem();
	return os;
}
std::ostream& operator <<(std::ostream &os, const SpecialWidget1 &rhs)
{
	
}
#endif
void testVec()
{
#if 0
	svector<Widget>vw;
	//int j = 1;
	for (int i = 0, j = 1, c = 2; i < 5; ++i, ++j)
	{
		vw.push_back(Widget(i, j));//�������Ƕ�����Ǳ�������vector
									//������push_back�����ʱ�򣬻�����������е�����
								//Ҳ����color�޷�����
								/*�����������ʹ�ó����ࣨ�麯����
								����������д��Widget��ɳ����࣬���ܲ���ʵ��*/
		if (c % 2 == 0)
			vw.push_back(SpecialWidget(i, j, c));
#endif
	
	vector<Widget*>vwPrt;
	//int j = 1;
	for (int i = 0, j = 1, item = 2; i < 5; ++i, ++j,++item)
	{
		if (item % 2 == 0)
			vwPrt.push_back(new SpecialWidget(i, j, item));
		else
			vwPrt.push_back(new SpecialWidget1(i, 0,item));
	}

#if 0
	for (auto item : vw)
		std::cout << item << std::endl;
#endif
	for (auto itemp : vwPrt)
		std::cout << *itemp << std::endl;


}

void testReserve()
{
	vector<int> vc;
	vc.reserve(100);
	for (int i = 0; i < 100; ++i)vc.push_back(i);
	display(vc);
}