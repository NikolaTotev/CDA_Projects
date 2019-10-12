// Problem_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <vector>

int main()
{

	std::string line;
	int number;
	std::vector<int> numbers;

	std::getline(std::cin, line);
	std::istringstream stream(line);
	while (stream >> number)
		numbers.push_back(number);

	int passing_grade = numbers[0];
	int max_grade = 0;
	int min_grade = numbers[1];

	for (int i = 1; i < numbers.size(); ++i)
	{
		if(numbers[i] > max_grade)
		{
			max_grade = numbers[i];
		}
		if(numbers[i] < min_grade)
		{
			min_grade = numbers[i];
		}
	}

	std::cout << max_grade << " " << min_grade << " " << passing_grade << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
