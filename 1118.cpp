#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;



int main()
	{
		char str[20];
		int i = 0, j = 0;
		char a;
		int temp = 0;
		int arr[20] = { 0 };
		gets(str);
		char*st = &str[0];
		int flag = 0;
		while ((a = *(st + i)) != '\0')
		{
			if (a <= '9'&&a >= '0')
			{
				temp = temp * 10 + (a - '0');
				flag = 1;
			}
			else
			{
				if (flag == 1)
				{
					arr[j] = temp;
					temp = 0;
					j++;

				}
				flag = 0;
			}
			i++;
		}	
		if (flag == 1)
		{
			arr[j++] = temp;
		}
		arr[j] = '\0';
		printf("There are %d numbers\n", j);
		int count = j;
		for (j = 0; j<count; j++)
		{
			printf("%4d", arr[j]);
		}
		return 0;
	}

