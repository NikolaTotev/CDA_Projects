

#include <iostream>
#include <vector>
using  namespace  std;
int counter = 0;
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
			counter += mid - left1;
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

void merge_sort(int* arr, int* helper,  int leftLim, int rightLim)
{
	if (leftLim + 1 < rightLim)
	{

		int middle = (leftLim + rightLim) / 2;
		merge_sort(arr, helper,  leftLim, middle);
		merge_sort(arr, helper,  middle, rightLim);
		merge(arr, helper, leftLim,  middle, rightLim);
	}

}

int main()
{
	int numberOfBuildings = 0;
	cin >> numberOfBuildings;
	int* heights = new int[numberOfBuildings];
	//std::vector<int> heights;

	int index = 0;

	int* helper = new int[10];

	for (int i = 0; i < numberOfBuildings; ++i)
	{
		cin >> index;
		heights[i] = index;
	}
	merge_sort(heights, helper, 0, numberOfBuildings);
	cout << counter;
	delete[] helper;


}

