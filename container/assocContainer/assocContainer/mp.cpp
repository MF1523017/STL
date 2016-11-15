#include"mp.h"
#include"common.h"
using std::map;
bool badValue(const int &i)
{
	return i % 2 == 0;
}
void testMapRemove()
{
	map<int, double>mp;
	for (int i = 0, j = 1; i < 10; ++i, ++j)
		mp[i] = j;
	//map 删除单个元素
#if 0
	mp.erase(6);//删除的是key对应的值
	displayMap(mp);
#endif
	//map 删除条件的所有对象
	for (auto item = mp.begin(); item != mp.end();)
	{	
		if (badValue(item->first)) {
			std::cout << "key " << item->first << " removed and the value is " << item->second<<std::endl;
			mp.erase(item++);
		}
		else
			++item;
	}
	displayMap(mp);
}
