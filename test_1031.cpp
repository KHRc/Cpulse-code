#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Cuboid
{
public:
	void Calculation()
	{
		v = m_length*m_width*m_hight;
		s = (m_length*m_width + m_hight*m_width + m_length*m_hight) * 2;
	};
	void Input()
	{
		int x = 0;
		int y = 0;
		int z = 0;
		cout << "�����볤����ĳ����!" << endl;
		cin >> x >> y >> z;
		m_length = x;
		m_width = y;
		m_hight = z;
	};
	void Print()
	{
		cout << "��������������ǣ�" << v << endl;
		cout << "��������������ǣ�" << s<< endl;
	};
	~Cuboid(){};

private:
	int m_length;
	int m_width;
	int m_hight;
	int v;
	int s;
};
void main()
{
again:
	Cuboid C1;
	C1.Input();
	C1.Calculation();
	C1.Print();
	goto again;
}
