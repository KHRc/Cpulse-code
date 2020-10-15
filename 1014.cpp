#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int y, int m, int d) : m_Year(y), m_Month(m), m_Day(d){};
	void print()
	{
		cout << "Birth:" << m_Year<< m_Month << m_Day << endl;
	}
	~Date()
	{}
	

private:
	int m_Year;
	int m_Month; 
	int m_Day;

};

class Students
{
public:
	Students(int n = 0, char*name ="", char sex='M', int m_Year = 0, int m_Month = 0, int m_Day = 0) :num(n), sex(sex), b( m_Year, m_Month, m_Day)
	{
		m_name = new char[5];
		strcpy(m_name,name);

	}
	void Print()
	{
		cout << "num:" << num << "\n" << "name:" << *m_name << "\n" << "sex:" << sex << "\n" << endl;
		b.print();
	};
	~Students()
	{
		delete[] m_name;
		m_name = NULL;
	}

private:
	int num = 0;
	char*m_name;
	char sex;
	Date b;


};

void main()
{
	Students S1(10, "a", 'm', 2000, 12, 12);
	S1.Print();
		
}