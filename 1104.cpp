#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//ʵ����
#if 0
void swap(int x)
{
	cout << "ֵ����" << "\n" << x << endl;
}
void swap1(int& x)
{
	cout << "����" << "\n" << x << endl;
}
void swap(int* x)
{
	cout << "ָ��" <<"\n"<< *x << endl;
}

void main()
{
	int a = 10;
	swap(a);
	swap1(a);
	swap(&a);
}
#endif
//ʵ����

class Animals
{
public:
	Animals(int age = 0, int weight = 0) :A_age(age), A_weight(weight)
	{};
	void Age()
	{
		cout << "�����ǣ�" << A_age << " years" << endl;
	}
	void Weight()
	{
		cout << "�����ǣ�" << A_weight << " kg" << endl;
	};
	~Animals(){};

private:
	int A_age;
	int A_weight;

};
class Cats:public Animals
{
public:
	Cats(int age = 0, int weight = 0,char * color = "abc", char* food= "abs") :Animals(age,weight)
	{
		C_color = new char[strlen(color) + 1];
		C_food = new char[strlen(food) + 1];
		strcpy(C_color, color);
		strcpy(C_food, food);
	};
	void food()
	{
		cout << "Cats's food:" << C_food << endl;
	}
	void color()
	{
		cout << "Cats'color:" << C_color << endl;
	}
	~Cats()
	{
		delete[] C_color;
		delete[] C_food;
};

private:
	char* C_color;
	char* C_food;

};
void main()
{
	Cats cat(5,4,"Black", "meat");
	cat.Age();
	cat.Weight();
	cat.color();
	cat.food();
}


