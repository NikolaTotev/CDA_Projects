#include <stdio.h>
#include <cstring>


void CountingSort(char* word, int len, int range)
{
	char* help = new char[len+1];

	for (int i = 0; i < len; i++)
	{
		help[i] = word[i];
	}
	help[len] = 0;

	int* count = new int[range + 1];

	for (int i = 0; i < range + 1; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < len; i++)
	{
		count[word[i]] = count[word[i]] + 1;
	}

	for (int i = 1; i < range; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = len - 1; i >= 0; i--)
	{
		word[count[help[i]] - 1] = help[i];
		count[help[i]] = count[help[i]] - 1;
	}

	delete[] count;
	delete[] help;

}

int main()
{
	int N = 0; 
	scanf("%d", &N);

	char* Word1 = new char[N];
	char* Word2= new char[N];
	
	char word1[100];
	char word2[100];

	scanf("%s", &word1);
	scanf("%s", &word2);

	int len1 = strlen(word1);
	int len2 = strlen(word2);

	for (int x = 0; x < len1; x++)
	{
		Word1[x] = word1[x];
	}
	Word1[len1] = 0;

	for (int y = 0; y < len2; y++)
	{
		Word2[y] = word2[y];
	}
	Word2[len2] = 0;

	if (len1 != len2)
	{
		printf("no");
	}
	else
	{
		/*
		printf("%s", Word1);
		printf(" ");
		printf("%s", Word2);

		printf("\n");
		*/

		CountingSort(Word1, len1, N);
		CountingSort(Word2, len2, N);
/*
		printf("%s", Word1);
		printf("\n");
		printf("%s", Word2);
		*/

		int count = 0;

		for (int i = 0; i < len1; i++)
		{
			if (Word1[i] == Word2[i])
			{
				count++;
			}
		}

		if (count == len2)
		{
			printf("yes");
		}
		else
		{
			printf("no");
		}

	}

	delete[] Word1;
	delete[] Word2;

	return 0;
}