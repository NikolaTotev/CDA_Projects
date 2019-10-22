#include <iostream>
using namespace std;

int partition(int* arr, int low, int high)
{
	int pivot = arr[high];
	int i = low;
	for (int j = i; j < high; ++j)
	{
		if(arr[i] <= pivot)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = arr[i];
			i++;
		}
	}
	int temp = arr[high];
	arr[high] = arr[i];
	arr[i] = temp;
	return i;
}
void quick_sort(int* arr, int low, int high)
{
	if(low < high)
	{
		int part = partition(arr, low, high);

		quick_sort(arr, low, part - 1);
		quick_sort(arr, part + 1, high);
	}
}
int main()
{
	int arr_1[10] = { 9, 8,7,6,5,4,3,2,1,0 };
	quick_sort(arr_1,0, 9);

	for (int i = 0; i < 10; ++i)
	{
		cout << arr_1[i]<< " ";
	}
}

