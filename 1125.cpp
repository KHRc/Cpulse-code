#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
//≥ÈœÛ¿‡
#if 0
class Shape
{
public:
	virtual float Area() const { return 0.0; };

};

class Circle:public Shape
{
public:
	Circle(int r) :m_r(r)
	{
		cout << "Circle" << endl;
		cout << m_r*m_r*3.14 << endl;
	};
	virtual float Area()const{ return m_r*m_r*3.14; }
	~Circle(){};
private:
	int m_r;
	float area;
};
class Square:public Shape
{
public:
	Square(int a) :m_a(a)
	{
		cout << "Square" << endl;
		cout << m_a*m_a << endl;
	};
	virtual float Area()const
	{
		return m_a*m_a;
	}
	~Square(){};

private:
	int m_a;

};
class Rectangle:public Shape
{
public:
	Rectangle(int a, int b) :len(a), wid(b)
	{
		cout << "Rectangle" << endl;
		cout << len*wid << endl;
	};
	~Rectangle(){};
	virtual float Area()const
	{
		return len*wid;
	}
private:
	int len;
	int wid;
	
};

class Trapezoid:public Shape
{
public:
	Trapezoid(int a, int b, int c) :top(a), botten(b), height(c)
	{
		cout << "Trapezoid" << endl;
	
		cout << (top + botten)*height / 2 << endl;
	};
	~Trapezoid(){};
	virtual float Area()const
	{
		return (top + botten)*height / 2;
	}

private:
	int top;
	int botten;
	int height;

};

class Triangle:public Shape
{
public:
	Triangle(int a, int b) :botten(a), height(b)
	{
		cout << "Triangle" << endl;
		cout << botten*height / 2 << endl;
	};
	~Triangle(){};
	virtual float Area()const
	{
		return  botten*height / 2;
	}
private:
	int botten;
	int height;
	
};



void main()
{
	Circle x(1);
	Square y(2);
	Rectangle z(2, 3);
	Trapezoid a(2, 3, 4);
	Triangle b(3, 4);
	Shape *p[5] = { &x, &y, &z, &a, &b };
	double sum = 0.0;
	for (int i = 0; i < 4; i++)
	{
		sum += p[i]->Area();
	}
	cout << "All area is:" << sum << endl;

	
}

#endif

//µ˜”√≈≈–Ú

#if 0
void main()
{
	int arr[] = { 1, 2, 3, 5, 2, 1, 4, 8, 6, 3 ,8,6,4,7,9};
	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr,arr+n );
	for (int i = 0; i<n; i++)
		cout<< arr[i] << " ";
}
#endif

//√∞≈›≈≈–Ú

template<class T>
void Sort(T*a,int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n-i-1; j++)
		{
			if (a[j]>a[j+1])
			{
				T temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				
			}
		}
	}
}

void main()
{
	double arr[] = { 11.5, 21.6, 3.4, 38.9, 2.4, 11.2, 4.3,
		82.3, 6.4, 53.8, 8.5, 63.6, 74.4, 73.8, 98.7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Sort(arr, n);
	for (int i = 0; i<n; i++)
		cout<< arr[i] << "\n ";
}


//—°‘Ò≈≈–Ú
#if 0
template<class T>
void Sort(T*a,int n)
{
	int i, j;
	int min = 0;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		T temp = a[i];
		a[i] = a[min];
		a[i] = temp;
	}
}
void main()
{
	double arr[] = { 1.5, 2.8, 3.4, 5.6, 2.4, 1.2, 
		4.3, 8.3, 6.4, 3.8, 8.5, 6.6, 4.4, 7.8, 9.7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Sort(arr, n);
	for (int i = 0; i<n; i++)
		cout << arr[i] << "\n ";
}
#endif