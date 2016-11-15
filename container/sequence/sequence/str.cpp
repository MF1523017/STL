#include"str.h"
void testAssign()
{
	string v1, v2("hello,world!");
	v1.assign(v2.begin() + v2.size() / 2, v2.end());
	std::cout << "v1 is " << v1<<std::endl
		<< "v2 is" << v2 << std::endl;
}
void charFunc(const char *rhs)
{
	for (int i = 0; i < 5; ++i)
		std::cout << rhs[i] << " ";
	std::cout << std::endl;
}
//string��cAPI��ת��
void testCAPI()
{
	string tmp("testC_API");
	//charFunc(tmp);//�������޷�Ĭ��ת����
	charFunc(tmp.c_str());//��string ת����const char *
	const char * cstr = "testCchar*";
	string s(cstr);//const char *�ɱ�������ʼ��string
	char * noncstr = "testNon-char*";
	string nons(noncstr);
	std::cout << nons;

}
//ʹ��swap����ȥ�����������
void testSwapShrinkToFit()
{
	string s;
	s.reserve(1000);
	s = "swapShrinkToFit";
	std::cout << "the capacity is " << s.capacity() << std::endl;//result is 1007
	string(s).swap(s);
	std::cout << "the capacity after swap is " << s.capacity() << std::endl;//result is 15
}
