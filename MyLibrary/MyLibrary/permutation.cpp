#include <iostream>
#include "permutation.h"
#include "sorting.h"

using namespace std;


/************************************************************************/
/* Permutation using recursive method
a - input array
n - size of the array
stage - index at which the swap takes place
*/
/************************************************************************/
template < class T>
void SwapElements(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

/*
Do permutation with repetition
*/
template < class T>
void PermutateWithRepetition(T a, int size, int index)
{
	if (size == index)
	{
		cout << a << endl;
	}
	else
	{
		for (int i = index; i < size; i++)
		{
			SwapElements(a[index], a[i]);
			PermutateWithRepetition(a, size, index + 1);
			SwapElements(a[index], a[i]);
		}
	}
}

/************************************************************************/
/* Permutation without repetition
arg1 - sorted array
arg2 - size of the array
arg3 - current position of the permutation
*/
/************************************************************************/
template < class T>
void PermutateWithoutRepetition(T a, int size, int index)
{
	if (size == index)
	{
		cout << a << endl;
	}
	else
	{
		bool dontPermutate = false;
		for (int i = index; i < size; i++)
		{
			if (i > index && a[i] == a[i-1])
			{
				dontPermutate = true;
			}

			if (!dontPermutate)
			{
				SwapElements(a[index], a[i]);
				PermutateWithoutRepetition(a, size, index + 1);
				SwapElements(a[index], a[i]);
			}
			dontPermutate = false;
		}
	}
}


void Permutate_main()
{
	char array[] = { "Hello" };
	
	//!< Sort Array before doing permutation to eliminate the repetition
	mergesort(array, strlen(array));
	PermutateWithoutRepetition(array, strlen(array), 0);
}