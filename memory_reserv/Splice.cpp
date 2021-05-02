#include <iostream>
#include <cstdlib>

#define MAX_LEN 10
#define MAX 10

using namespace std;

void display(int a[], int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << a[i] << ", ";
	}
	cout << "\n";
}

int* splice(int[], int, int[], int, int);

int main()
{
	srand(time(NULL));
	int a1[MAX_LEN], a2[MAX_LEN], *result = NULL;
	for(int i = 0; i < MAX; i++)
	{
		a1[i] = rand() % MAX;
		a2[i] = -(rand() % MAX);
	}

	cout << "1. array: \n";
	display(a1, MAX);
	cout << "2. array: \n";
	display(a2, MAX);
	int spliceInd = 0;
	cout << "Where shoule the 1. array be inserted in 2. array?\n"
		 << "Index: ";
	cin >> spliceInd;
	result = splice(a2, MAX, a1, MAX, spliceInd);
	cout << "\nResult: ";
	display(result, 2 * MAX);
	return 0;
}

int* splice(int *a1, int len1, int *a2, int len2, int pos)
{
	if(pos < 0 || pos > len1 + len2) return NULL;
	int *result = new int[len1 + len2];
	int i = 0;
	for(int j = 0; j < pos; j++, i++)
	{
		result[i] = a1[j];
	}
	for(int j = 0; j < len2; j++, i++)
	{
		result[i] = a2[j];
	}
	for(int j = pos; j < len1; j++, i++)
	{
		result[i] = a1[j];
	}
	return result;
}
