#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int monsterCount = 0;
	int blastPower = 0;

	cin >> monsterCount;

	cin >> blastPower;


	//vector<int> monsters;
	int* monsters = new int[monsterCount];

	int index = 0;
	for (int i = 0; i < monsterCount; ++i)
	{
		cin >> index;
		//monsters.push_back(index);
		monsters[i] = index;
	}

	int max = monsters[0];
	int numberOfShots = 0;
	while (max > 0)
	{
		max = 0;
		for (int i = 0; i < monsterCount; ++i)
		{
			if (monsters[i] > max)
			{
				max = monsters[i];
			}

		}

		for (int i = 0; i < monsterCount; ++i)
		{
			if (monsters[i] == max)
			{
				monsters[i] = 0;
			}
			monsters[i] -= blastPower;
		}

		numberOfShots++;
	}
	cout << numberOfShots - 1;


}
