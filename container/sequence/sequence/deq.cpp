#include"deq.h"
#include"common.h"
using std::deque;
using std::cout;
using std::endl;
//template void display(deque &tmp);
bool badValue(int &i)//ɾ������ż��
{
	return i % 2 == 0;
}
void testDelete()
{
	deque<int> dt;
	for (int i = 0; i < 10; ++i)
		dt.push_back(i);
#if 0
	//ɾ��ĳ���̶�ֵ������Ԫ��
	dt.erase(remove(dt.begin(), dt.end(), 5), dt.end());
	
	display(dt);
#endif
#if 0
	//ɾ������ĳ�������Ķ���
	dt.erase(remove_if(dt.begin(), dt.end(), badValue), dt.end());
	display(dt);
#endif
	//ɾ���Ĺ�����һЩ��������
	for (auto item = dt.begin(); item != dt.end();)
	{
		if (badValue(*item)) {
			cout << "ż�� " << *item << "��ɾ��" << endl;
			item = dt.erase(item);//һ��erase����ɣ�����ָ����汻ɾ��
								//����һ��Ԫ�ص���Ч������
		}
		else
			++item;
	}
	display(dt);

}