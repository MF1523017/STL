#include"deq.h"
#include"common.h"
using std::deque;
using std::cout;
using std::endl;
//template void display(deque &tmp);
bool badValue(int &i)//删除所有偶数
{
	return i % 2 == 0;
}
void testDelete()
{
	deque<int> dt;
	for (int i = 0; i < 10; ++i)
		dt.push_back(i);
#if 0
	//删除某个固定值的所有元素
	dt.erase(remove(dt.begin(), dt.end(), 5), dt.end());
	
	display(dt);
#endif
#if 0
	//删除满足某个条件的对象
	dt.erase(remove_if(dt.begin(), dt.end(), badValue), dt.end());
	display(dt);
#endif
	//删除的过程做一些其他工作
	for (auto item = dt.begin(); item != dt.end();)
	{
		if (badValue(*item)) {
			cout << "偶数 " << *item << "被删除" << endl;
			item = dt.erase(item);//一旦erase被完成，它是指向紧随被删除
								//的下一个元素的有效迭代器
		}
		else
			++item;
	}
	display(dt);

}