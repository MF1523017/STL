#pragma once
#include"common.h"
#include<iostream>
#include<iterator>
#include<fstream>
#include<string>
#include<vector>
using std::vector;
using std::string;
using std::ifstream;
using std::istream_iterator;
void istreambuf_iter()
{
	ifstream inputFile("test.txt");
	//istream_iterator 会将空白符，转移符等忽略掉
#if 0
	string fileData((istream_iterator<char>(inputFile)), istream_iterator<char>());
	std::cout << fileData << std::endl;
#endif
#if 1
	//istreambuf_iterator会将空白符也读取
	string fileData((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
	std::cout << fileData << std::endl;
#endif
	std::ofstream outputFile("result.txt");
	std::ostreambuf_iterator<char> oi(std::cout);
	std::copy(fileData.begin(), fileData.end(), oi);
	
}
void istream_iter()
{
	double value1, value2;
	std::cout << "Please, insert two values: ";

	std::istream_iterator<double> eos;              // end-of-stream iterator
	std::istream_iterator<double> iit(std::cin);   // stdin iterator

	if (iit != eos) value1 = *iit;
	
	++iit;
	
	if (iit != eos) value2 = *iit;

	std::cout << value1 << "*" << value2 << "=" << (value1*value2) << '\n';
}
void inputIstream()
{
	int N;
	std::cin >> N;
	//std::istream_iterator<int> eos;
		std::istream_iterator<int> input(std::cin);
		vector<int> tmp;
		int i = 0;
		while (i < N)
		{
			tmp.push_back(*input);
			++input;
			++i;
		}
		display(tmp);
	
}