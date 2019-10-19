#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	string wordOne;
	string wordTwo;
	long long wordLenth;

	cin >> wordLenth;
	cin >> wordOne;
	cin >> wordTwo;

	//vector<long long> wordArr1;
	//vector<long long> wordArr2;

	long long wordArr1[26];
	long long wordArr2[26];

	if (wordLenth == 0)
	{
		cout << "yes";
		return 0;
	}
	
	if (wordOne == wordTwo) {
		cout << "yes";
		return 0;
	}

	for (int i = 0; i < 26; i++)
	{
		/*wordArr1.push_back(0);
		wordArr2.push_back(0);*/
		wordArr1[i] = 0;
		wordArr2[i] = 0;
	}

	for (long long i = 0; i < wordLenth; ++i)
	{
		int indexOne = wordOne[i] - 'a';
		wordArr1[indexOne]++;
	}

	for (int i = 0; i < wordLenth; ++i)
	{
		int indexTwo = wordTwo[i] - 'a';
		wordArr2[indexTwo]++;
	}

	for (int i = 0; i < 26; ++i)
	{
		if (wordArr1[i] != wordArr2[i])
		{
			cout << "no";
			return 0;
		}
	}

	cout << "yes";
	return 0;
}

