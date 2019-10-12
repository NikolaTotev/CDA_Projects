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

	int numberOfRows = 0;
	std::cin >> numberOfRows;

	std::vector<std::vector <int>> sockInfo;
	sockInfo.reserve(numberOfRows);

	std::string line;
	std::getline(std::cin, line);

	for (int i = 0; i < numberOfRows; ++i)
	{
		int number;
		std::vector<int> sockPair;

		std::getline(std::cin, line);
		std::istringstream stream(line);
		while (stream >> number)
			sockPair.push_back(number);

		sockInfo.push_back(sockPair);
	}


	for (int i = 0; i < numberOfRows; ++i)
	{
		for (int j = 0; j < 1; ++j)
		{
			bool bothOdd = sockInfo[i][j] % 2 != 0 && sockInfo[i][j + 1] % 2 != 0;
			bool bothEven = sockInfo[i][j] % 2 == 0 && sockInfo[i][j + 1] % 2 == 0;
			bool rightOutOfBounds = sockInfo[i][j + 1] < 2 && sockInfo[i][j] > 0 || sockInfo[i][j+1] < 0;
			bool leftOutOfBounds = sockInfo[i][j] < 0;
			if(bothEven || bothOdd || rightOutOfBounds || leftOutOfBounds)
			{
				std::cout << "no" << std::endl;
			}
			else
			{
				std::cout << "yes" << std::endl;
			}
		}
	}

	
}

 