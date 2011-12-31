// aa.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class AA
{
public:
	int a;
	int b;
	void printab()
	{
		std::cout<<a<<b<<std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	std::cout<<sizeof(AA)<<endl;
	std::cout<<&(AA::a)<<endl;
	std::cout<<&(AA::b)<<endl;
	std::cout<<AA::printab<<std::endl;
	return 0;
}

