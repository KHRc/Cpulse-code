#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Teacher
{
public:
	Teacher(const char*name = "", int a = 0, const char*t = "");
	void display();
	~Teacher();

protected:
	mutable char*name;
	int age;
	char* title;

};

Teacher::Teacher(const char*nam, int a, const char*t) :age(a)
{
	name = new char[strlen(nam) + 1];
	strcpy(name, nam);
	title = new char[strlen(t) + 1];
	strcpy(title, t);
}
void Teacher::display()
{
	cout << "name:" << *name << endl;
	cout << "age:" << age << endl;
	cout << "title:" << *title << endl;
}
Teacher::~Teacher()
{
	if (name != NULL)
	{
		delete[] name;
		name = NULL;
	}
	if (title != NULL)
	{
		delete[] title;
		title = NULL;
	}
}

class Student
{
public:
	Student(const char*name = "", char s = 'm', float sco = 0.0);
	~Student();
	void display();

protected:
	mutable char*namel;
	char sex;
	float score;

};

Student::Student(const char*name, char s, float sco) :score(sco)
{
	namel = new char[strlen(name) + 1];
	strcpy(namel, name);
	sex = s;
}
void Student::display()
{
	cout << "name:" << *namel << endl;
	cout << "sex:" << sex << endl;
	cout << "score:" << score << endl;
};

Student::~Student()
{
	if (namel != NULL)
	{
		delete[] namel;
		namel = NULL;
	}
}

class Graduate:public Teacher,public Student
{
public:
	Graduate(const char* nam = " ", int a = 0, const char s = 'm',
		const char *t = " ", float sco = 0.0, float w = 0.0)
		:Teacher(nam, a, t), Student(nam, s, sco), wages(w)
	{
	}
	~Graduate(){};
	void show();

private:
	float wages;
};
void Graduate::show()
{
	cout << "name:" << name << endl;
	cout << "age:" << age << endl; 
	cout << "sex:" << sex << endl;
	cout << "score:" << score << endl;
	cout << "title:" << title << endl;
	cout << "wages:" << wages<< endl;
}

int main()
{
	Graduate gradl("Wang_li", 24, 'f', "assistant", 89.5, 1200);
	gradl.show();
	return 0;
}
