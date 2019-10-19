#include <iostream>
#include <algorithm>
using namespace std;
void merge(int* arr, int start, int mid, int end)
{
	int arr1Len = mid - start;
	int arr2Len = end - mid;
	int* arr1 = new int[arr1Len];
	int* arr2 = new int[arr2Len];

	int arr1Counter = 0;
	int arr2Counter = 0;
	int mainCounter = 0;

	while (arr1Counter < arr1Len && arr2Counter < arr2Counter)
	{
		arr[mainCounter] = min(arr1[arr1Counter], arr2[arr2Counter]);
		if (arr1[arr1Counter] < arr2[arr2Counter])
		{
			arr1Counter++;
		}
		else
		{
			arr2Counter++;
		}
		mainCounter++;
	}

	delete[]arr1;
	delete[]arr2;
}

void merge_sort(int* arr, int leftLim, int rightLim)
{
	if (leftLim < rightLim)
	{

		int middle = (leftLim + rightLim) / 2;
		merge_sort(arr, leftLim, middle);
		merge_sort(arr, middle + 1, rightLim);
		merge(arr, leftLim, middle, rightLim);
	}
	
}

int main()
{
	int arr_1[10] = { 7,5,3,2,6,2,3,4,1,2 };
	int mid = 10 / 2;

	merge_sort(arr_1, 0, 9);

	/*for (int i = 0; i < 10; ++i)
	{
		cout << arr_1[i] << endl;
	}*/
}