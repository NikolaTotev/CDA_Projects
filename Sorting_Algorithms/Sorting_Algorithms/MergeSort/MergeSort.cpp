#include <iostream>
#include <algorithm>
using namespace std;
void merge(int* arr, int* helper, int start,   int mid, int end)
{
	
	int left1 = start;
	int left2 = mid;
	int i = start;

	for (; left1 < mid && left2<end; ++i)

	{
		if(arr[left1]<= arr[left2])
		{
			helper[i] = arr[left1++];
		}
		else
		{
			helper[i] = arr[left2++];
		}
	}

	while(left1 < mid)
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

void merge_sort(int* arr, int* helper,  int leftLim, int rightLim)
{
	if (leftLim + 1< rightLim)
	{

		int middle = (leftLim + rightLim) / 2;
		merge_sort(arr, helper, leftLim, middle);
		merge_sort(arr, helper, middle, rightLim);
		merge(arr, helper,  leftLim, middle, rightLim);
	}
	
}

int main()
{
	//int arr_1[10] = { 7,5,3,2,6,2,3,4,1,2 };
	int arr_1[10] = { 9, 8,7,6,5,4,3,2,1,0 };
	int mid = 10 / 2;
	int* helper = new int[10];

	merge_sort(arr_1, helper, 0, 10);
	delete[] helper;

	for (int i = 0; i < 10; ++i)
	{
		cout << arr_1[i] << endl;
	}
}