#include <iostream>
using namespace std;

void printArr(int* mainArray, int start, int length)
{
	for (int i = start; i < length; ++i)
	{
		cout << mainArray[i] << " ";
	}
}

void merge(int* arr, int* helper, int start, int mid, int end)
{

	int left1 = start;
	int left2 = mid;
	int i = start;

	for (; left1 < mid && left2 < end; ++i)

	{
		if (arr[left1] <= arr[left2])
		{
			helper[i] = arr[left1++];
		}
		else
		{
			helper[i] = arr[left2++];
		}
	}

	while (left1 < mid)
	{
		helper[i++] = arr[left1++];
	}

	while (left2 < end)
	{
		helper[i++] = arr[left2++];
	}

	for (int j = start; j < end; ++j)
	{
		arr[j] = helper[j];
	}

}

void merge_sort(int* arr, int* helper, int leftLim, int rightLim)
{
	if (leftLim + 1 < rightLim)
	{

		int middle = leftLim + (leftLim - rightLim) / 2;
		merge_sort(arr, helper, leftLim, middle);
		merge_sort(arr, helper, middle, rightLim);
		merge(arr, helper, leftLim, middle, rightLim);
	}
	printArr(arr, leftLim, rightLim);
}
int main()
{
	int length = 0;
	cin >> length;
	int* mainArray = new int[length];
	int* helper = new int[length];
	int element = 0;
	for (int i = 0; i < length; ++i)
	{
		cin >> element;
		mainArray[i] = element;
	}

	merge_sort(mainArray, helper, 0, length);
	for (int i = 0; i < length; ++i)
	{
		//cout << mainArray[i] << endl;
	}
	delete[]helper;
	return 0;
}

