#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
namespace N
{
	int a = 10;
	int b = 20;
}
namespace M
{
	int a = 50;
	int b = 100;
}
using namespace std;
void main()
{
	cout << M::a <<"\n"<< N::a << endl;
}