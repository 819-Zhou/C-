#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "A dynamic array\n" << endl;
	int size = 0, counter = 0, step = 5, i;
	float x, *arr = NULL;

	cout << "Input number, suprise!\n"
			"Exit with any letter" << endl;

	while(cin >> x)
	{
		if(counter >= size)
		{
			float *p = new float[size + step];
			for(int i = 0; i < size; i++)
			{
				p[i] = arr[i];
			}
			delete [] arr;
			arr = p; size += step;
		}
		arr[counter++] = x;
	}
	if(counter == 0)
		cout << "Nothing was inputted!" << endl;
	else
	{
		float sum = 0.0;
		cout << "Your input: " << endl;
		for(int i = 0; i < counter; i++)
		{
			cout << setw(10) << arr[i];
			sum += arr[i];
		}
		cout << "\nAverage: " << sum / counter << endl;
	}
	delete [] arr;
	return 0;
}






