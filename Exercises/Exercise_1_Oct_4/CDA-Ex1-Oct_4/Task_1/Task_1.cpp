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

///Task 4
int findNumberOfPairs(int* numbers, int length,  int sum)
{
	int right = numbers[length-1];
	int left = numbers[0];

	int leftCounter = 0;
	int rightCounter = length-1;
	
	int numberOfPairs = 0;
	while(left!=right)
	{
		std::cout << left << " " << right << std::endl;
		if((left+right)>sum)
		{
			rightCounter -= 1;
			right = numbers[rightCounter];
		}
		if((left+right) == sum)
		{
			numberOfPairs++;
			leftCounter += 1;
			left = numbers[leftCounter];

			rightCounter -= 1;
			right = numbers[rightCounter];
		}
		if ((left + right) < sum)
		{
			leftCounter += 1;
			left = numbers[leftCounter];
		}

	}

	return numberOfPairs;
	
}
///
int main()
{
	//char input[4] = { 'd', 'a', 'd', 0 };
	int input[5] = {1, 2, 3,4,5};
	int sum = 21;
	std::cout << findNumberOfPairs(input, 5, 6) << std::endl;
	//std::cout << isPalindrome(input, strlen(input)-1);
}