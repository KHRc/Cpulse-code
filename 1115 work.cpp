#include<iostream>
using namespace std;
class Matrix
{
public:
	Matrix()
	{
		for ( i = 0; i < 2; i++)
		{
			for (j = 0; j < 3; j++)
			{
				arr[i][j]=0 ;
			}
		}
	};
	void Input()
	{
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 3; j++)
			{
				cin>> arr[i][j];
			}
		}

	};
	Matrix operator +(Matrix&b)
	{
		Matrix c;
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 3; j++)
			{
				c.arr[i][j]= arr[i][j]+b.arr[i][j];
			}
		}
		return c;
	
	}
	void Print()
	{
		for (i = 0; i < 2; cout << endl, i++)
		for (j = 0; j<3; cout <<  arr[i][j] << ' ', j++);

	}
	~Matrix(){};

private:
	int arr[2][3];
	int i;
	int j;
};
int main()
{
	Matrix a, b, c;
	a.Input();
	b.Input();
	c = a + b;
	c.Print();
	system("pause");
	return 0;
}

