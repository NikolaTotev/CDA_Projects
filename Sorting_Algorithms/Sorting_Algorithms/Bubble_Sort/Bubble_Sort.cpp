#include <iostream>
//Bubble
using namespace std;
int main()
{
	int arr_1[10] = {7,5,3,2,6,2,3,4,1,2};


	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10-i-1; ++j)
		{
			if(arr_1[j]>arr_1[j+1])
			{
				int temp = arr_1[j + 1];
				arr_1[j + 1] = arr_1[j];
				arr_1[j] = temp;
			}
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << arr_1[i] << endl;
	}
}
