#include <iostream>
using namespace  std;
typedef  long long longBoi;
int main()
{
	longBoi numberOfDays;
	longBoi numberOfBaloons;

	cin >> numberOfDays;
	cin >> numberOfBaloons;

	longBoi* baloonsPerDay = new longBoi[numberOfDays];
	longBoi* numberOfCanidesForBaloon = new longBoi[numberOfDays];

	longBoi input;
	for (longBoi i = 0; i < numberOfDays; ++i)
	{

		cin >> input;
		baloonsPerDay[i] = input;
	}

	for (longBoi i = 0; i < numberOfDays; ++i)
	{
		cin >> input;
		numberOfCanidesForBaloon[i] = input;
	}

	longBoi* worstCaseForCandies = new longBoi[numberOfDays];
	for (longBoi i = 0; i < numberOfDays; ++i)
	{
		worstCaseForCandies[i] = baloonsPerDay[i] * numberOfCanidesForBaloon[i];
	}

	longBoi currentMax = worstCaseForCandies[0];
	longBoi index = 0;
	for (longBoi i = 0; i < numberOfBaloons; ++i)
	{
		for (longBoi i = 0; i < numberOfDays; ++i)
		{
			if(worstCaseForCandies[i]> currentMax)
			{
				currentMax = worstCaseForCandies[i];
				index = i;
			}
			
		}
		currentMax -= numberOfCanidesForBaloon[index];
		worstCaseForCandies[index] = currentMax;
	}

	
	for (int i = 0; i < numberOfDays; ++i)
	{
		if(worstCaseForCandies[i] > currentMax)
		{
			currentMax = worstCaseForCandies[i];
		}
	}
	cout << currentMax;
}

