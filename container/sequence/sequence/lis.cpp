#include"lis.h"
#include"common.h"
using std::cout;
using std::endl;
using std::list;
bool badValue1(int &i)//ɾ������ż��
{
	return i % 2 == 0;
}
void testListRemove()
{
	list<int>ls;
	for (int i = 0; i < 10; ++i)
		ls.push_back(i);
	//list ɾ��ĳ��ֵ �Ķ���
#if 0
	ls.remove(5);
	display(ls);
#endif
#if 0
	//list ɾ��ĳ�������Ķ���
	ls.remove_if(badValue1);
	display(ls);
#endif
	
}