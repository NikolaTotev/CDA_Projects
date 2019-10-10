#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::cout << "Hello World!\n";
}

std::string superReducedString(std::string s) {
	std::map<char, bool> neighbors;

	int stringLength = s.length();

	bool isReduced = false;
	for (int i = 0; i < stringLength; ++i)
	{
		if(s[i] == s[i+1])
		{
			neighbors[s[i]] = true;
		}
		else
		{
			neighbors[s[i]] = false;
		}
	}

	if(neighbors.find(true))
	
	for (int i = 0; i < stringLength; ++i)
	{
		
	}

}
