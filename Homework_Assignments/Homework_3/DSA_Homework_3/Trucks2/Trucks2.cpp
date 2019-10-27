#include <iostream>
typedef long long longBoi;
using namespace std;
struct truckInfo
{
	longBoi offset;
	longBoi numberOfDrinksToMove;
};

void merge(truckInfo* arr, truckInfo* helper, longBoi start, longBoi mid, longBoi end)
{

	longBoi left1 = start;
	longBoi left2 = mid;
	longBoi i = start;

	for (; left1 < mid && left2 < end; ++i)

	{
		if (arr[left1].offset <= arr[left2].offset)
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

void merge_sort(truckInfo* arr, truckInfo* helper, longBoi leftLim, longBoi rightLim)
{
	if (leftLim + 1 < rightLim)
	{

		longBoi middle = (leftLim + rightLim) / 2;
		merge_sort(arr, helper, leftLim, middle);
		merge_sort(arr, helper, middle, rightLim);
		merge(arr, helper, leftLim, middle, rightLim);
	}

}
int main()
{
	longBoi numberOfTrucks;
	cin >> numberOfTrucks;

	truckInfo* info = new truckInfo[numberOfTrucks];
	truckInfo* helper = new truckInfo[numberOfTrucks];

	longBoi offset = 0;
	longBoi numberOfDrinks;

	for (longBoi i = 0; i < numberOfTrucks; ++i)
	{
		cin >> offset;
		cin >> numberOfDrinks;
		info[i].offset = offset;
		info[i].numberOfDrinksToMove = numberOfDrinks;
	}

	merge_sort(info, helper, 0, numberOfTrucks);

	longBoi tempMin = 0;
	longBoi currentMin = 0;
	longBoi currentOffset = 0;

	for (int i = 0; i < numberOfTrucks; ++i)
	{

		for (int j = i + 1; j < numberOfTrucks; ++j)
		{
			currentOffset = abs(info[j].offset - info[i].offset);

			if (i == 0)
			{
				tempMin += currentOffset * info[j].numberOfDrinksToMove;
			}
			if (tempMin > currentMin)
			{
				break;
			}
		}

		if (i == 0)
		{
			currentMin = tempMin;
		}
		else
		{
			if (tempMin < currentMin)
			{
				currentMin = tempMin;
			}
		}
	}
	cout << currentMin;

}
