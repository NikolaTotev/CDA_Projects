#include <iostream>
typedef long long longBoi;
using namespace std;
struct truckInfo
{
	longBoi offset;
	longBoi numberOfDrinksToMove;
};

int main()
{
	longBoi numberOfTrucks;
	cin >> numberOfTrucks;

	truckInfo* info = new truckInfo[numberOfTrucks];
	truckInfo* helper = new truckInfo[numberOfTrucks];

	longBoi offset = 0;
	longBoi numberOfDrinks;
	longBoi numberOfDrinksM1=0;
	longBoi numberOfDrinksM2=0;

	for (longBoi i = 0; i < numberOfTrucks; ++i)
	{
		cin >> offset;
		cin >> numberOfDrinks;
		info[i].offset = offset;
		info[i].numberOfDrinksToMove = numberOfDrinks;
	}

	longBoi maxOffset = info[0].offset;
	longBoi minOffset = info[0].offset;

	for (int i = 1; i < numberOfTrucks; ++i)
	{
		if(info[i].offset > maxOffset)
		{
			maxOffset = info[i].offset;
		}
		if(info[i].offset < minOffset)
		{
			minOffset = info[i].offset;
		}
	}

	longBoi left = minOffset;
	longBoi right = maxOffset;
	longBoi currentMin = 0;
	while(right >=left)
	{
		longBoi middle1 = (2*left+right) / 3;
		longBoi middle2 = (left+2*right) / 3;

		for (int i = 0; i < numberOfTrucks; ++i)
		{
			if(middle1 > 0 && middle2>0)
			{				
			numberOfDrinksM1 += (info[i].offset - middle1) * info[i].numberOfDrinksToMove;
			numberOfDrinksM2 += (info[i].offset - middle2) * info[i].numberOfDrinksToMove;
			}
		}

		if(numberOfDrinksM1 < numberOfDrinksM2)
		{
			right = middle1 - 1;
			currentMin = numberOfDrinksM1;
		}
		else if(numberOfDrinksM1 > numberOfDrinksM2)
		{
			left = middle2 + 1;
			currentMin = numberOfDrinksM2;
		}
		else
		{
			left = middle1 + 1;
			right = middle2 + 1;
		}
	}
	cout << currentMin;
}
