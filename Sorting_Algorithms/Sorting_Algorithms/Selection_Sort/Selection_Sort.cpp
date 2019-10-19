#include <iostream>
using namespace std;
int main()
{
	int arr_1[10] = { 7,5,3,2,6,2,3,4,1,2 };

	int arrEnd = 10;
	int max = arr_1[0];
	int temp = 0;
	int maxIndex = 0;
	for (int i = 0; i < 10; ++i)
	{
		for (int i = 0; i < arrEnd; ++i)
		{
			if (arr_1[i] > max)
			{
				max = arr_1[i];
				maxIndex = i;
			}
		}
		temp = arr_1[arrEnd-1];
		arr_1[arrEnd - 1] = max;
		arr_1[maxIndex] = temp;
		arrEnd--;
		max = 0;
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << arr_1[i] << endl;
	}
}
