#include <iostream>

///Task One
///We need to sort to begin with.
int numberCounter(int* numbers, int length)
{
	int* numArr = new int[length];

	for (int i = 0; i < length; ++i)
	{
		numArr[i] = 0;
	}

	for (int i = 0; i < length; ++i)
	{
		numArr[numbers[i] - 1]++;
	}

	int max = 0;

	for (int i = 0; i < length; ++i)
	{
		if(numArr[i] > max)
		{
			max = numArr[i];
		}
	}
	return max;
}
///

///Task Two
bool isPalindrome (char* input, int length)
{
	if(length ==0 || length == 1)
	{
		return true;
	}

	if(input[0] == input[length])
	{
		return isPalindrome(input + 1, length - 2);
	}
	return false;
}


void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

///
///Task Three
int sumMax(int* numbers, int length, int k)
{
	bool isSorted = true;

		for (int i = 0; i < length-1; ++i)
		{
			for (int j = 0; j < length-i-1; ++j)
			{
				if(numbers[j] > numbers[j+1])
				{
					swap(&numbers[j], &numbers[j + 1]);
				}
			}
		}


		int sum = 0;
	for (int i = length-1; i > length-1-k; i--)
	{
		sum += numbers[i];
	}
	return sum;
}
///
int main()
{
	//char input[4] = { 'd', 'a', 'd', 0 };
	int input[5] = {1, 5, 2, 4, 3};
	std::cout << sumMax(input, 5,2);/*
	for (int i = 0; i < 5; ++i)
	{
		std::cout << input[i]<< std::endl;
	}*/
	//std::cout << isPalindrome(input, strlen(input)-1);
}