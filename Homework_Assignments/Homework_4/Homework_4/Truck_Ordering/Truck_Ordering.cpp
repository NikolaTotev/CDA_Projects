#include <iostream>
#include <stack>
#include <vector>
typedef long long longBoi;
using namespace std;

struct testCase
{
	longBoi numberOfTrucks;
	longBoi* truckNumbers;
};
int main()
{

	longBoi numberOfCases;
	cin >> numberOfCases;

	testCase* cases = new testCase[numberOfCases];

	longBoi numberOfTrucksPerCase;
	longBoi truckNumber;
	for (longBoi i = 0; i < numberOfCases; ++i)
	{
		cin >> numberOfTrucksPerCase;
		cases[i].numberOfTrucks = numberOfTrucksPerCase;
		cases[i].truckNumbers = new longBoi[numberOfTrucksPerCase];

		for (longBoi j = 0; j < numberOfTrucksPerCase; ++j)
		{
			cin >> truckNumber;
			cases[i].truckNumbers[j] = truckNumber;
		}
	}

#pragma  region  Input verification
	///Input verification test
	/*cout << "Number of cases: " << numberOfCases << endl;
	for (int i = 0; i < numberOfCases; ++i)
	{
		cout << cases[i].numberOfTrucks << endl;
		for (int j = 0; j < cases[i].numberOfTrucks; ++j)
		{
			cout << cases[i].truckNumbers[j] << " ";
		}
		cout << endl;
	}*/
#pragma endregion 
	bool isPossible = true;

	stack<longBoi> temp;
	longBoi lastPushed = 0;
	for (longBoi i = 0; i < numberOfCases; ++i)
	{
		for (longBoi j = 0; j < cases[i].numberOfTrucks - 1; ++j)
		{
			if (cases[i].truckNumbers[j] > cases[i].truckNumbers[j + 1])
			{
				if (j != 0)
				{
					if (cases[i].truckNumbers[j] > lastPushed)
					{
						cout << "no" << endl;
						isPossible = false;
					}
				}
				lastPushed = cases[i].truckNumbers[j];
				temp.push(lastPushed);
			}

		}
		if (isPossible)
		{
			cout << "yes" << endl;			
		}
		isPossible = true;
		while(!temp.empty())
		{
			temp.pop();
		}
	}
	return 0;
}
