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
