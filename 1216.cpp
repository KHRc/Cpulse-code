#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Teacher
{
public:
	Teacher(string n, int a, char s,
		string ad, string nu, string t);
	void display();
	~Teacher(){};

protected:
	string name;
	int age;
	char sex;
	string add;
	string num;
	string title;


};
Teacher::Teacher(string n, int a, char s, string ad, string nu, string t)
:name(n), age(a), sex(s), add(ad), num(nu), title(t){}
void Teacher::display()
{
	cout << "name:" << name << endl;
	cout << "age£º" << age << endl;
	cout << "sex:" << sex << endl;
	cout << "title:" << title << endl;
	cout << "address:" << add<< endl;
	cout << "tel:" << num << endl;
}

class Cadre
{
public:
	Cadre(string n, int a, char s, string ad, string nu, string p);
	void display();
	~Cadre(){};

protected:
	string name;
	int age;
	char sex;
	string add;
	string num;
	string post;
};
Cadre::Cadre(string n, int a, char s, string ad, string nu, string p) 
:name(n), age(a), sex(s), add(ad), num(nu), post(p){}
void Cadre::display()
{
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
	cout << "post:" << post << endl;
	cout << "address:" << add << endl;
	cout << "tel:" << num << endl;
}

class Teacher_Cadre:public Teacher ,public Cadre
{
public:
	Teacher_Cadre(string nam, int a, char s, string tit,
		string p, string ad, string t, float w);
	void show();
	~Teacher_Cadre(){};

private:
	float wages;
};
Teacher_Cadre::Teacher_Cadre
(string n, int a, char s, string t, string p, string ad, string nu, float w)
:Teacher(n, a, s, t, ad, nu), Cadre(n, a, s, p, ad, nu), wages(w){};
void Teacher_Cadre::show()
{
	Teacher::display();
	cout << "post:" << Cadre::post << endl;
	cout << "wages:" << wages << endl;
}

void main()
{
	Teacher_Cadre t1
		("Lihua", 50, 'f', "prof.", "president", 
		"135 Shanxi South Road,Shanghai", "(021)68871456", 1564.3);
	t1.show();
	
}