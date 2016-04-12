#pragma once

void selectionsort(int num, int* input);
void bubblesort(int num, int* input);
void insertionsort(int num, int input[]);

/************************************************************************/
/* This function does the actual merging                                */
/************************************************************************/
template < class T>
void merge(T arr, int low, int high, T temp)
{
	if (low == high - 1)
	{
		return;
	}
	int middle = (low + high) / 2;

	merge(arr, low, middle, temp);
	merge(arr, middle, high, temp);

	int i = low;
	int j = low;
	int k = middle;

	for (int a = low; a < high; a++)
	{
		if ((j < middle) && (k >= high || arr[j] <= arr[k]))
		{
			temp[i] = arr[j];
			j++;
		}
		else
		{
			temp[i] = arr[k];
			k++;
		}
		i++;
	}

	for (int a = low; a < high; a++)
	{
		arr[a] = temp[a];
	}
}

/************************************************************************/
/*arr - input array pointer
size - size of the array*/
/************************************************************************/
template < class T>
void mergesort(T arr, int size)
{
	T temp = (T)malloc(sizeof(T) * size);

	merge(arr, 0, size, temp);

	free(temp);
}

//function to check the program
int sorting_main();