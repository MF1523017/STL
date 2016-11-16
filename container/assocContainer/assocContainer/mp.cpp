#include"mp.h"
#include"common.h"
using std::map;
std::ostream &operator<<(std::ostream &os, const Widget &rhs)
{
	os << rhs._weight << " ";
	return os;
}
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

//单效率至关重要时，请在map::operator[]与map::insert之间慎重选择
void mapInsert()
{
	typedef map<int, Widget> IntWidgetMap;
	IntWidgetMap m;
	double j = 0;
	for (int i = 0; i < 5; ++i,++j)
	{
		m.insert(IntWidgetMap::value_type(i,Widget(j)));//没有key值的，insert效率更好
	}
	displayMap(m);

	for (int i = 0; i < 5; ++i, --j)
	{
		m[i] = Widget(j);//有key值的，operator[]效率更高
	}
	displayMap(m);
}
