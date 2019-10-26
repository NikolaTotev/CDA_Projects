#include <iostream>
#include <algorithm>
using namespace  std;
typedef long long longBoi;

void merge(longBoi* arr, longBoi* helper, longBoi start, longBoi mid, longBoi end)
{

	longBoi left1 = start;
	longBoi left2 = mid;
	longBoi i = start;

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

	for (longBoi j = start; j < end; ++j)
	{
		arr[j] = helper[j];
	}

}

void merge_sort(longBoi* arr, longBoi* helper, longBoi leftLim, longBoi rightLim)
{
	if (leftLim + 1 < rightLim)
	{

		longBoi middle = (leftLim + rightLim) / 2;
		merge_sort(arr, helper, leftLim, middle);
		merge_sort(arr, helper, middle, rightLim);
		merge(arr, helper, leftLim, middle, rightLim);
	}

}

int binarySearchNumber(longBoi* mainArray, longBoi start, longBoi end, longBoi numberToFind)
{
	while (start <= end)
	{
		longBoi middle = (start + end) / 2;
		if (mainArray[middle] == numberToFind)
		{
			return middle;
		}
		if (mainArray[middle] < numberToFind)
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}
	return -1;
}

int binarySearch(longBoi* mainArray, longBoi start, longBoi end, longBoi referenceNum)
{
	longBoi middle = 0;
	while (start <= end)
	{
		middle = start + (end - start) / 2;

		if (mainArray[middle] < referenceNum)
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}
	longBoi thingToReturn = 0;

	if (mainArray[middle] < referenceNum)
	{
		return middle;
	}
	return middle - 1;

}

int findClosest(longBoi* mainArray, longBoi start, longBoi end, longBoi referenceNum)
{
	longBoi position = binarySearchNumber(mainArray, start, end, referenceNum);
	if (position != -1)
	{
		//return mainArray[position];
		return position;
	}

	longBoi left = binarySearch(mainArray, start, end, referenceNum);
	longBoi right = left + 1;

	longBoi distToLeft = referenceNum - mainArray[left];
	longBoi distToRight = mainArray[right] - referenceNum;

	longBoi minDist = 0;
	if (distToLeft < distToRight)
	{
		return left;
	}

	return right;
}

int main()
{
	longBoi numberOfHouses;
	longBoi numberOfCows;

	cin >> numberOfHouses;
	cin >> numberOfCows;

	longBoi* houseCords = new longBoi[numberOfHouses];
	longBoi* helper = new longBoi[numberOfHouses];
	longBoi input;
	for (longBoi i = 0; i < numberOfHouses; ++i)
	{
		cin >> input;
		houseCords[i] = input;
	}
	merge_sort(houseCords, helper, 0, numberOfHouses);

	longBoi min = houseCords[numberOfHouses - 1] - houseCords[0];
	longBoi temp = 0;
	for (int i = 0; i < numberOfHouses - 1; ++i)
	{
		temp = houseCords[i + 1] - houseCords[i];
		if(temp < min)
		{
			min = temp;
		}
	}

	if(numberOfCows == 2)
	{
		cout << houseCords[numberOfHouses - 1] - houseCords[0];
		return 0;
	}

	if(numberOfCows  == numberOfHouses)
	{
		cout << min;
		return 0;
	}
	longBoi tempNumOfCows = numberOfCows;
	longBoi currentAverage = 0;
	longBoi currentStart = 0;
	longBoi currentEnd = numberOfHouses - 1;
	longBoi currentClosest = 0;
	bool* availablePositions = new bool[numberOfHouses];
	availablePositions[0] = true;
	availablePositions[numberOfHouses - 1] = true;
	currentAverage = (houseCords[currentEnd] - houseCords[currentStart]) /  (tempNumOfCows - 1);
	if(currentAverage < min)
	{
		cout << min;
		return 0;
	}
	while (tempNumOfCows > 1 )
	{
		currentClosest = findClosest(houseCords, currentStart, currentEnd, currentAverage+1);
		availablePositions[currentClosest] = true;
		currentStart = currentClosest;
		tempNumOfCows--;
	}

	longBoi maxDist = 0;
	longBoi tempLeftIndex = 0;
	longBoi left = houseCords[tempLeftIndex];
	longBoi right = 0;
	longBoi temp = 0;
	for (longBoi i = 1; i < numberOfHouses-1; ++i)
	{
		if(availablePositions[i] == true)
		{
			left = houseCords[tempLeftIndex];
			temp = houseCords[i] - left;
			tempLeftIndex = i;
			if( temp > maxDist)
			{
				maxDist = temp;
			}
		}
	}

	cout << maxDist;

}

