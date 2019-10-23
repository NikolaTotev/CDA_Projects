#include <iostream>
//Insertion
using namespace std;
int main()
{
	int arr_1[10] = { 7,5,3,2,6,2,3,4,1,2 };

	int max = arr_1[0];
	int min = arr_1[0];
	for (int i = 0; i < 10; ++i)
	{
		int currentElement = arr_1[i];
		int j = i - 1;
		while (j>=0 && currentElement > arr_1[j])
		{
			arr_1[j + 1] = arr_1[j];
			j--;
		}

		arr_1[j + 1] = currentElement;
	}


	for (int i = 0; i < 10; ++i)
	{
		cout << arr_1[i] << endl;
	}
}

