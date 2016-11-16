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
#if 0
//����ֱ���޸�set��multiset�еļ�
void noModifySet()
{
	class Employee
	{
	public:
		Employee(const string &name, int id) :_name(name), _id(id) {};
		const string &name()const { return _name; };
		void setName(const string & name) { _name = name; };
		const int &id()const { return _id; }
		void setId(const int &id) { _id = id; }
	private:
		string _name;
		int _id;
	};
	class IDLess :public std::binary_function<Employee, Employee, bool>
	{
	public:
		bool operator()(const Employee &lhs, const Employee& rhs)const
		{
			return lhs.id() < rhs.id();
		}
	};
	typedef set<Employee, IDLess> EmpIdSet;
	EmpIdSet se;
	se.insert(Employee("first", 1));
	se.insert(Employee("second", 2));
	Employee selectedId("name", 1);
	EmpIdSet::iterator i = se.find(selectedId);
	if (i != se.end())
		const_cast<EmpIdSet&>(*i).setName("changed name");
}
#endif

