#include"st.h"
#include"common.h"
#include<string>
#include<algorithm>

using std::string;
using std::set;
using std::endl;
using std::cout;
//Ϊ����ָ��Ĺ�������ָ���Ƚ�����
class StringPtrLess :public std::binary_function<const string *, const string *, bool>
{
public:
	bool operator()(const string *p1, const string *p2)const
	{
		return *p1 > *p2;//�����Լ���less�������԰����Լ�����Ը��������洢
	}
};
void print(const string * ps)
{
	std::cout << *ps<<std::endl;
}
void testSetPtr()
{
	typedef set<string *, StringPtrLess> StringPtrSet;
	StringPtrSet ssp;//����һЩbook
	ssp.insert(new string("math"));
	ssp.insert(new string("English"));
	ssp.insert(new string("science"));
	//�������Ǵ�ӡ��������3��16���Ƶ�ָ��ֵ
#if 0
	for (set<string*>::const_iterator i = ssp.begin(); i != ssp.end(); ++i)
		std::cout <<*(*i) << std::endl;
#endif
	//��displaySet��������ʹ����auto ������forѭ����auto �Ķ������*i
	//displaySet(ssp);
	//�������Լ���less ����
#if 0
	for (StringPtrSet::const_iterator i = ssp.begin(); i != ssp.end(); ++i)
		std::cout << *(*i) << std::endl;
#endif
	//ʹ��for_each ��ӡ
	std::for_each(ssp.begin(), ssp.end(), print);
}