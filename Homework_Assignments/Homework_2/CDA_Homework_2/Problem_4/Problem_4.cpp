#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	long long numberOfActivities = 0;
	cin >> numberOfActivities;

	vector<vector <long long>> activityInfo;

	string line;
	getline(cin, line);

	for (int i = 0; i < numberOfActivities; ++i)
	{
		int number;
		vector<long long> activityPair;

		getline(std::cin, line);
		istringstream stream(line);
		while (stream >> number)
			activityPair.push_back(number);

		activityInfo.push_back(activityPair);
	}

	int activityCounter = 1;
	int currentSum  = activityInfo[0][1] + activityInfo[0][0];;
	for (int i = 0; i < numberOfActivities-1; ++i)
	{
		
		if (currentSum <= activityInfo[i + 1][0])
		{
			currentSum = activityInfo[i+1][0] + activityInfo[i+1][1];
			activityCounter++;
		}
	}

	cout << activityCounter;
}


