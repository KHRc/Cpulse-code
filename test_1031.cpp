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
		cout << "请输入长方体的长宽高!" << endl;
		cin >> x >> y >> z;
		m_length = x;
		m_width = y;
		m_hight = z;
	};
	void Print()
	{
		cout << "这个长方体的体积是：" << v << endl;
		cout << "这个长方体的面积是：" << s<< endl;
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
