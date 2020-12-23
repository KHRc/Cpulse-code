#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<fstream>

#include<stdio.h>
#include<stdlib.h>
using namespace std;
//c++°æ

void main()
{
	ifstream sfile
		("C:\\Users\\Administrator\\Desktop\\a.cpp");
	ofstream dfile
		("C:\\Users\\Administrator\\Desktop\\b.txt");
	char ch;
	if (!sfile)
	{ cout << "Can't open a.cpp" << endl; exit(0); }
	if (!dfile)
	{ cout << "Can't open b.cpp" << endl; exit(1); }
	sfile.unsetf(ios::skipws);
	while (sfile >> ch)
		dfile << ch;
	sfile.close();
	dfile.close();

}

//c°æ
//int main()
//{
//	FILE *pSource = NULL, *pDestination = NULL;
//	char ch;
//	pSource = fopen
//		("C:\\Users\\Administrator\\Desktop\\c.txt", "r+");
//	pDestination = fopen
//		("C:\\Users\\Administrator\\Desktop\\b.txt","w+");
//
//	if ((NULL == pDestination)||(NULL == pSource))
//	{
//		puts("Can't open file!");
//		return 0;
//	}
//	while ((ch=(fgetc(pSource))!=EOF))
//	{
//		fputc(ch, pDestination);
//
//	}
//	fclose(pSource);
//	fclose(pDestination);
//	puts("Copy file successful!");
//	return 0;
//}