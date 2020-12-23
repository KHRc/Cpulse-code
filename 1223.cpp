#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//实验十五

//class RMB
//{
//public:
//	RMB(int y, int j, int f) :yuan(y), jiao(j), fen(f)
//	{};
//	void Print()
//	{
//		cout << yuan << "." << jiao << fen << endl;
//	};
//	RMB operator+(RMB&t)
//	{
//		RMB s(0,0,0);
//		s.yuan = yuan + t.yuan;
//		s.jiao = jiao + t.jiao;
//		s.fen = fen + t.fen;
//		return s;
//	};
//	~RMB(){};
//
//private:
//	int yuan;
//	int jiao;
//	int fen;
//
//};
//void main()
//{
//	RMB s1(5, 4, 2);
//	s1.Print();
//	RMB s2(9, 2, 4);
//	RMB s3 = s1 + s2;
//	s3.Print();
//}
//

//实验16
class Worker
{
public:
	Worker(string n, float b, float m) :name(n), base_pay(b), merit_pay(m){};
	void total()
	{
		wage += base_pay + merit_pay;
		count++;
	};
	void print()
	{
		cout << "姓名："<<name << "基本工资："
			<<base_pay<<"绩效工资："
			<<merit_pay <<"工资："
			<<base_pay+merit_pay <<"\n"<<endl;
	};
	static float average()
	{
		return wage / count;
	};
	~Worker(){};

private:
	string name;
	float base_pay;
	float merit_pay;
	static float wage;
	static int count;

};

float Worker::wage = 0;
int Worker::count =0;

void main()
{
	Worker w[3] = { Worker("zhangsan", 8000.0, 2456.2), 
		Worker("lisi", 9000, 5632.4), 
		Worker("wangwu", 8500, 3562.4) };
	
	for (int i = 0; i < 3; i++)
	{
		w[i].total();
		w[i].print();
	}
	cout << "平均工资："<<Worker::average() << endl;
}