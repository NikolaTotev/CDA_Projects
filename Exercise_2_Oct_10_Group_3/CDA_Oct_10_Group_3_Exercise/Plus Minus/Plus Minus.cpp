#include <iostream>
#include <vector>
#include <iomanip>


void plusMinus(std::vector<int> arr) {
	int numberOfPositives = 0;
	int numberOfZeros = 0;
	int numberOfNegatives = 0;
	int arrLen = arr.size();

	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] > 0)
		{
			numberOfPositives++;
		}
		else if (arr[i] == 0)
		{
			numberOfZeros++;
		}
		else if (arr[i] < 0)
		{
			numberOfNegatives++;
		}
	}

	float posPerc = numberOfPositives / arrLen;
	float zerPerc = numberOfZeros / arrLen;
	float negPerc = numberOfNegatives / arrLen;

	std::cout << std::fixed << std::setprecision(6) << posPerc << std::endl;
	std::cout << std::fixed << std::setprecision(6) << zerPerc << std::endl;
	std::cout << std::fixed << std::setprecision(6) << negPerc << std::endl;
}

int main()
{

}

