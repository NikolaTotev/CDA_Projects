#include <iostream>
using namespace std;

void printArr(int* mainArray, int start, int length)
{
	for (int i = start; i < length; ++i)
	{
		cout << mainArray[i] << " ";
	}
}
void merge(int* mainArray, int* helper, int start, int middle, int length)
{
	int left1 = start;
	int left2 = middle;
	int i = start;

	for (; left1 < middle && left2 < length; ++i)
	{
		if (mainArray[left1] <= mainArray[left2])
		{
			helper[i] = mainArray[left1++];
		}
		else
		{
			helper[i] = mainArray[left2++];
		}
	}

	while (left1 < middle)
	{
		helper[i++] = mainArray[left1++];

	}

	while (left2 < length)
	{
		helper[i++] = mainArray[left2++];
	}

	for (int j = 0; j < length; ++j)
	{
		//out << helper[j] << " ";
		mainArray[j] = helper[j];
	}
}
void merge_sort(int* mainArray, int* helper, int start, int length)
{
	if (start  < length)
	{
		int middle = (start + length) / 2;
		merge_sort(mainArray, helper, start, middle);
		printArr(mainArray, start, middle);

		merge_sort(mainArray, helper, middle+1, length);
		printArr(mainArray, middle+1, length);
		merge(mainArray, helper, start, middle, length);
	}
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
	printArr(mainArray, 0, length);

	for (int i = 0; i < length; ++i)
	{
		//cout << mainArray[i] << endl;
	}
	delete[]helper;
	return 0;
}

