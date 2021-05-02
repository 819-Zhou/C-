#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void display(int a[], int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << a[i] << ", ";
	}
	cout << "\n";
}

void selectionSort(int arr[], int len);
int *merge(int a1[], int len1, int a2[], int len2);

int main()
{
	int i, len1 = 10, len2 = 20;
	srand((unsigned)time(NULL));
	int *a1 = new int[len1],
		*a2 = new int[len2];
	for(i = 0; i < len1; i++)
		a1[i] = rand() % 100;
	for(i = 0; i < len2; i++)
        a2[i] = rand() % 100;
    selectionSort(a1, len1);
    selectionSort(a2, len2);

    cout << "1. array:" << endl;
    display(a1, len1);
    cout << "2. array:" << endl;
    display(a2, len2);

	int *a3, len3;
	a3 = merge(a1, len1, a2, len2);
	len3 = len1 + len2;
	cout << "After mix: " << endl;
	display(a3, len3);

	delete[] a1; delete[] a2; delete[] a3;
	return 0;
}

inline void swap(int &a, int &b)
{ int temp = a; a = b; b = temp; }

void selectionSort(int *arr, int len)
{
	register int *p, *minp;
	int *last = arr + len;
	for(; arr < last; ++arr)
	{
		minp = arr;
		for(p = arr + 1; p < last; ++p)
		{
			if(*p < *minp)
				minp = p;
		}
		swap(*arr, *minp);
	}
}
int *merge(int a1[], int len1, int a2[], int len2)
{
	int i = 0, i1 = 0, i2 = 0;
	int *a = new int[len1 + len2];

	for(i = 0; i1  < len1 && i2 < len2; ++i)
	{
		if(a1[i] <= a2[i2])
			a[i] = a1[i1++];
		else
			a[i] = a2[i2++];
	}
	if(i1 < len1)
		while(i1 < len1)
			a[i++] = a1[i1++];
	else
		while(i2 < len2)
			a[i++] = a2[i2++];
	return a;
}
