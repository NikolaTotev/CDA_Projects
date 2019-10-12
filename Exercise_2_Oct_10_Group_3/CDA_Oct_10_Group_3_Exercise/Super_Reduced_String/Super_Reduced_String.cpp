#include <iostream>
#include <vector>
#include <map>

int main()
{
	std::cout << "Hello World!\n";
}

std::string superReducedString(std::string s) {
	std::map<bool, char> neighbors;

	int stringLength = s.length();

	bool isReduced = false;
	for (int i = 0; i < stringLength; ++i)
	{
		if(s[i] == s[i+1])
		{
			neighbors[true] = s[i];
		}
		else
		{
			neighbors[false] = s[i];
		}
	}

	if(neighbors.find(true))
	
	for (int i = 0; i < stringLength; ++i)
	{
		
	}

}
