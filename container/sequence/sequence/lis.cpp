#include"lis.h"
#include"common.h"
using std::cout;
using std::endl;
using std::list;
bool badValue1(int &i)//删除所有偶数
{
	return i % 2 == 0;
}
void testListRemove()
{
	list<int>ls;
	for (int i = 0; i < 10; ++i)
		ls.push_back(i);
	//list 删除某个值 的对象
#if 0
	ls.remove(5);
	display(ls);
#endif
#if 0
	//list 删除某个条件的对象
	ls.remove_if(badValue1);
	display(ls);
#endif
	
}