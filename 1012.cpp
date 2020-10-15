#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Test
{
public:
	Test(int i, int j)
	{
		cout << "Test" << endl;
		m_i = i;
		m_j = j;

	};
	void Print()
	{
		cout << "Print" << m_i << m_j << endl;
	};
	~Test()
	{
		cout << "~Test" << endl;
	};

private:
	int m_i;
	int m_j;

};

void main()
{
	Test a(1,2);
	Test b(3,4);
	Test*p = NULL;
	Test arr[3] = { Test(1, 2), Test(3, 4), Test(0, 0) };
	for (int i = 0; i <=2 ; i++)
	{
		arr[i].Print();
	}
	p = &a;
	p->Print();
	p = arr;
}

#if 0
void main()
{
	int*p = NULL;
	p = new int;
	*p = 6;
	delete p;
	p = NULL;

	p = new int[5];
	delete[]p;
	p = NULL;
}

#endif

