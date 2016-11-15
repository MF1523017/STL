#include"st.h"
#include"common.h"
#include<string>
#include<algorithm>

using std::string;
using std::set;
using std::endl;
using std::cout;
//为包含指针的关联容器指定比较类型
class StringPtrLess :public std::binary_function<const string *, const string *, bool>
{
public:
	bool operator()(const string *p1, const string *p2)const
	{
		return *p1 > *p2;//定义自己的less函数可以按照自己的意愿进行排序存储
	}
};
void print(const string * ps)
{
	std::cout << *ps<<std::endl;
}
void testSetPtr()
{
	typedef set<string *, StringPtrLess> StringPtrSet;
	StringPtrSet ssp;//保存一些book
	ssp.insert(new string("math"));
	ssp.insert(new string("English"));
	ssp.insert(new string("science"));
	//这里我们打印出来的是3个16进制的指针值
#if 0
	for (set<string*>::const_iterator i = ssp.begin(); i != ssp.end(); ++i)
		std::cout <<*(*i) << std::endl;
#endif
	//在displaySet里面我们使用了auto 来进行for循环，auto 的对象就是*i
	//displaySet(ssp);
	//定义了自己的less 函数
#if 0
	for (StringPtrSet::const_iterator i = ssp.begin(); i != ssp.end(); ++i)
		std::cout << *(*i) << std::endl;
#endif
	//使用for_each 打印
	std::for_each(ssp.begin(), ssp.end(), print);
}