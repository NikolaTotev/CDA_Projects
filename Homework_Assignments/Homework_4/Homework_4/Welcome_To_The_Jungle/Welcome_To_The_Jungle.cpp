#include <iostream>
typedef  long long longBoi;
using namespace std;
int main()
{
	longBoi numberOfTrees;
	cin >> numberOfTrees;
	longBoi* treeheights = new longBoi[numberOfTrees];

	longBoi input;
	for (int i = 0; i < numberOfTrees; ++i)
	{
		cin >> input;
		treeheights[i] = input;
	}

	std::cout << "Hello World!\n";
}

