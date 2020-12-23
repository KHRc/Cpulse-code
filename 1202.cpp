#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//实验10 静态

class Student
{
public:
	Student(int n, int a, float s)
		:num(n), age(a), score(s)
	{};
	void total()
	{
		sum += score;
		count++;
	};
	static float average()
	{
		return (sum / count);
	}
	~Student(){};
private:
	int num;
	int age;
	float score;
	static float sum;
	static int count;
};
float Student::sum = 0;
int Student::count = 0;
int main()
{
	Student stu[3] = { Student(201, 15, 82.7),
		Student(202, 18, 93.6), 
		Student(203, 19, 95.7) };
	int n;
	cout << "请输入学生的总个数：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		stu[i].total();
	};
	cout << "学生的总数为：" << n << "平均分为：" 
		<< Student::average() << endl;
	return 0;
}


#if 0
class Date
{
public:
	Date(){};
	void Input();//从输入端获取日期数据到数组中
	void Inputs()//将数组中的int对应到 year month day变量中
	{
		int*a = &d[0];
		year = *a;
		month = *(a + 1);
		day = *(a + 2);
		
	}
	void Judg();//判断你输入的 year month day是否合理
	void calculate();//计算天数
	void Print()
	{
		cout << "距离天数为：" << sum << endl;
	}
	~Date(){};

private:
	int year;
	int month;
	int day;
	int d[3];
	int sum;
};


void Date::Input()
{
	char date[11];
	gets(date);
	int i = 0;
	int n=9;
	int j = 0;
	char a;
	char*st = &date[0];
	int temp=0;
	while ((a = *(st + i)) != '\0')
	{
		if (a <= '9'&&a >= '0')
		{
			temp = temp * 10 + (a - '0');

		}
		else
		{
			d[j] = temp;
			if (j == 2)
			{
				break;
			}
			
			j++;
			temp = 0;
			
		}
		i++;
	}
	d[j] = temp;
}
void Date::Judg()
{
	 if (month > 12 || day > 31)
	{
		cout << "输入错误，请重试！" << endl;
		exit(0);
	}
	 if (month==2&&day>29)
	 {
		 cout << "输入错误，请重试！" << endl;
		 exit(0);
	 }
	 if (day>30 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
	 {
		 cout << "输入错误，请重试！" << endl;
		 exit(0);
	 }
}
void Date::calculate()
{
	//寻找之前有多少个闰年
	int n = 0;
	for (int y = 0; y < (year + 1); y += 4)
		n += (y % 4 == 0 && y % 100 || y % 400 == 0);
	printf("之前一共有%d个闰年\n", n);
	//月份与天数的关系
	switch (month)
	{
	case 1:
		sum = month * 31;
		break;
	case 2:
		sum = 59;
		break;
	case 3:
		sum = 90;
		break;
	case 4:
		sum = 120;
		break;
	case 5:
		sum = 151;
		break;
	case 6:
		sum = 181;
		break;
	case 7:
		sum = 181;
		break;
	case 8:
		sum = 212;
		break;
	case 9:
		sum = 242;
		break;
	case 10:
		sum = 273;
		break;
	case 11:
		sum = 303;
		break;
	case 12:
		sum = 334;
		break;
	default:
		break;
	}
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		printf("%d年为闰年！\n", year);
		sum++;
	}
	//把天数和年的部分加起来
	sum += day  + (year * 365+n);
}

void main()
{
	Date d;
	d.Input();
	d.Inputs();
	d.Judg();
	d.calculate();
	d.Print();

}
#endif
