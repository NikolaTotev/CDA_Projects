#include <iostream>
using namespace std;

int ternarySearch(int* mainArray, int left, int right, int itemToFind)
{
	while (left <= right)
	{

		//Calculating the first and second middle. This is what divides the array into three parts.
		int middle1 = left + (right - left) / 3;
		int middle2 = right - (right - left) / 3;

		//If the item we are looking for is at the first middle we just return that position;
		if (mainArray[middle1] == itemToFind)
		{
			return middle1;
		}
		//If the item we are looking for is at the second middle we just return that position;
		if (mainArray[middle2] == itemToFind)
		{
			return  middle2;
		}
		//if the item is smaller than the second middle, then its obvious that all the elements after the first middle
		//will be bigger than the element we are looking for;
		if (itemToFind < mainArray[middle1])
		{
			right = middle1 - 1;
		}
		//If the item is bigger than the second middle, then obviously all other elements before the second middle
		//are not the key;
		else if (itemToFind > mainArray[middle2])
		{
			left = middle2 + 2;
		}
		//If neither one of the two previous conditions are true that means the key in between
		//the first and second middle;
		else
		{
			left = middle1 + 1;
			right = middle2 - 1;
		}
	}

	//If we don't find the element we are looking for we return -1;
	return -1;
}

int main()
{
	int mainArray[10] = { 0,1,2,3,4,5,6,7,8,9 };
	cout << "Number 5 is at " << ternarySearch(mainArray, 0, 9, 5) << " position." << endl;
}
