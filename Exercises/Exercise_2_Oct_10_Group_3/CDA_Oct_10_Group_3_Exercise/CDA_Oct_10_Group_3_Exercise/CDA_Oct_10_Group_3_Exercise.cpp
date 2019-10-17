#include <iostream>


bool arr[100];

void genBoolPerm(int i, int n) // 2^n complexity 
{
	if (i == n)
	{
		for (int i = 0; i < n; ++i)
		{
			std::cout << arr[i];
		}
		std::cout << std::endl;
		return;
	}

	arr[i] = 0;
	genBoolPerm(i + 1, n);
	arr[i] = 1;
	genBoolPerm(i + 1, n);
}

int main()
{

	genBoolPerm(0, 2);
}
