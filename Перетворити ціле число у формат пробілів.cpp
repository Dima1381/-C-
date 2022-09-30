#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h> 



using namespace std;

int binary_number(int num)
{
	int bin = 0;
	for (int temp = num; temp > 0; temp = temp / 2)
	{
		if (temp & num)
		{
			bin = bin * 10;
			bin += 1;
		}
		else
		{
			bin = bin * 10;
			bin += 0;
		}
	}
	return bin;
}

void foo_reincarnation(int bin_num, char* str)
{
	int count = -1; 
	for (int i = bin_num; i != 0; i /= 10)
	{
		count++;
	}

	int bit_rate = 1; 
	for (int i = 1; i <= count; i++)
	{
		bit_rate *= 10;
	}

	int temp;
	while (bit_rate >= 1)
	{
		temp = bin_num / bit_rate;

		if (temp == 1)
		{
			strcat(str, "/t");
		}
		if (temp == 0)
		{
			strcat(str, " ");
		}
		bin_num = bin_num % bit_rate;
		bit_rate /= 10;
	}
}

int main()
{
	int num;
	cin >> num;
	char str[30] = {};
	int second_num = num;

	if (second_num < 0)
	{
		second_num = second_num * (-1);
		strcat(str, "/t");
	}
	else if (second_num > 0)
	{
		strcat(str, " ");
	}
	else if (second_num == 0)
	{
		strcat(str, "/n");
		cout << str;
		return 0;
	}

	int bin_num = binary_number(second_num);

	foo_reincarnation(bin_num, str);

	strcat(str, "/n");

	cout << str;
	return 0;
}
