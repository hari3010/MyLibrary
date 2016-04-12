
#include <iostream>
#include "sorting.h"

#define NUM 10
using namespace std;

void selectionsort(int num, int* input)
{
	for (int i = 0; i < num; i++)
	{
		int minValueIndex = i;
		for (int j = i; j < num; j++)
		{
			if (input[minValueIndex] > input[j])
			{
				minValueIndex = j;
			}
		}

		if (minValueIndex != i)
		{
			int temp = input[i];
			input[i] = input[minValueIndex];
			input[minValueIndex] = temp;
		}
	}
}

void bubblesort(int num, int* input)
{
	for (int i = 0; i < num; i++)
	{
		int flag = 0;
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (input[j] > input[j + 1])
			{
				int temp = input[j + 1];
				input[j + 1] = input[j];
				input[j] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

void insertionsort(int num, int input[])
{
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j > 0 && input[j] < input[j - 1]; j--)
		{
			int temp = input[j - 1];
			input[j - 1] = input[j];
			input[j] = temp;
		}
	}
}

int sorting_main()
{
	int input1[NUM] = { 12, 334, 56, 23, 563, 665, 88, 445, 23, 10 };


	//bubblesort(NUM, input1);

	//selectionsort(NUM, input1);

	//insertionsort(NUM, input1);

	mergesort(input1, NUM);

	for (int j = 0; j < NUM; j++)
	{
		cout << input1[j] << "   ";
	}
	cout << endl;
	getchar();
	return 0;
}