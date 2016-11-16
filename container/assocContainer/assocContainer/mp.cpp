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
	//map ɾ������Ԫ��
#if 0
	mp.erase(6);//ɾ������key��Ӧ��ֵ
	displayMap(mp);
#endif
	//map ɾ�����������ж���
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

//��Ч��������Ҫʱ������map::operator[]��map::insert֮������ѡ��
void mapInsert()
{
	typedef map<int, Widget> IntWidgetMap;
	IntWidgetMap m;
	double j = 0;
	for (int i = 0; i < 5; ++i,++j)
	{
		m.insert(IntWidgetMap::value_type(i,Widget(j)));//û��keyֵ�ģ�insertЧ�ʸ���
	}
	displayMap(m);

	for (int i = 0; i < 5; ++i, --j)
	{
		m[i] = Widget(j);//��keyֵ�ģ�operator[]Ч�ʸ���
	}
	displayMap(m);
}
