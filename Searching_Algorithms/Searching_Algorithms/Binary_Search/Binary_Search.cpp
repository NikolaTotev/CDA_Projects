// Binary_Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	std::cout << "Hello World!\n";
}

  int binarySearch (int* mainArray, int left, int right, int arrSize, int thingToFind)
{
	  int right = arrSize;
	  int left = 0;
	  int middle = (right + left) / 2;

	
	while(left <= right)
	{
		middle = (right + left) / 2;

		if (mainArray[middle] == thingToFind)
		{
			return middle;
		}
		if(thingToFind < mainArray[middle])
		{
			right = middle-1;
		}
		else if (thingToFind > mainArray[middle])
		{
			left = middle+1;
		}
	}
	return -1;
}