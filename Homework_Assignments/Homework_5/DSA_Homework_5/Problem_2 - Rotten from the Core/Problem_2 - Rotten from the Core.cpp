#include <iostream>
#include <queue>
using  namespace std;

struct Apple
{
	bool isRotten = false;
	int dayID;
	int coord_X;
	int coord_Y;
};
void print(Apple** apples, int numberOfRows, int numberOfColumns)
{
	for (int i = numberOfRows - 1; i >= 0; --i)
	{
		for (int j = 0; j < numberOfColumns; ++j)
		{
			if (apples[i][j].isRotten)
			{
				cout << "[" << "=" << ", " << "=" << "]";
			}
			else
			{
				cout << "[" << apples[i][j].coord_X << ", " << apples[i][j].coord_Y << "]";
			}

		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
int main()
{
	int numberOfRows;
	int numberOfColumns;
	int numberOfDays;
	cin >> numberOfRows;
	cin >> numberOfColumns;
	cin >> numberOfDays;
	int totalAmountOfApples = numberOfRows * numberOfColumns;

	Apple** apples = new Apple * [numberOfRows];
	for (int i = 0; i < numberOfRows; ++i)
	{
		apples[i] = new Apple[numberOfColumns];
	}

	for (int i = 0; i < numberOfRows; ++i)
	{
		for (int j = 0; j < numberOfColumns; ++j)
		{
			Apple newApple;
			newApple.isRotten = false;
			newApple.coord_X = i;
			newApple.coord_Y = j;
			newApple.dayID = 1;
			apples[i][j] = newApple;
		}
	}




	Apple rottenApple_1;
	rottenApple_1.dayID = 1;
	rottenApple_1.isRotten = true;
	Apple rottenApple_2;
	rottenApple_2.dayID = 1;
	rottenApple_2.isRotten = true;




	int coordX;
	int coordY;
	int day = 1;

	queue<Apple> rottenApples;
	while (cin >> coordX >> coordY)
	{
		if (day != 1)
		{
			rottenApple_2.coord_X = coordX;
			rottenApple_2.coord_Y = coordY;
			apples[coordX][coordY] = rottenApple_2;
			rottenApples.push(rottenApple_1);
			totalAmountOfApples--;
		}
		rottenApple_1.coord_X = coordX;
		rottenApple_1.coord_Y = coordY;
		apples[coordX][coordY] = rottenApple_1;
		totalAmountOfApples--;
		day++;
	}

	print(apples, numberOfRows, numberOfColumns);

	Apple currentApple;
	int currentDay = 1;
	while (!rottenApples.empty())
	{
		currentApple = rottenApples.front();
		if (currentApple.dayID > currentDay)
		{
			currentDay = currentApple.dayID;
		}


		///Rot to the top OK
		if (currentApple.coord_X + 1 <= numberOfRows)
		{
			Apple& topApple = apples[currentApple.coord_X+1][currentApple.coord_Y];

			if (!topApple.isRotten)
			{
				topApple.isRotten = true;
				topApple.dayID = currentDay + 1;
				totalAmountOfApples--;

				if (currentDay <= numberOfDays)
				{
					rottenApples.push(topApple);
				}
			}
			print(apples, numberOfRows, numberOfColumns);
			
		}

		///Rot to the bottom OK
		if (currentApple.coord_X -1 >0)
		{
			Apple& bottomApple = apples[currentApple.coord_X-1][currentApple.coord_Y];

			if (!bottomApple.isRotten)
			{
				bottomApple.isRotten = true;
				bottomApple.dayID = currentDay + 1;
				totalAmountOfApples--;

				if (currentDay <= numberOfDays)
				{
					rottenApples.push(bottomApple);
				}
			}
			print(apples, numberOfRows, numberOfColumns);

		}

		///Rot to the left; // goes up instead
		if (currentApple.coord_Y - 1 >= 0)
		{
			Apple& leftApple = apples[currentApple.coord_X][currentApple.coord_Y-1];

			if (!leftApple.isRotten)
			{
				leftApple.isRotten = true;
				leftApple.dayID = currentDay + 1;
				totalAmountOfApples--;

				if (currentDay <= numberOfDays)
				{
					rottenApples.push(leftApple);
				}
			}
			print(apples, numberOfRows, numberOfColumns);

		}

		///Rot to the right; 
		if (currentApple.coord_X + 1 <= numberOfColumns)
		{
			Apple& rightApple = apples[currentApple.coord_X][currentApple.coord_Y+1];

			if (!rightApple.isRotten)
			{
				rightApple.isRotten = true;
				rightApple.dayID = currentDay + 1;
				totalAmountOfApples--;

				if (currentDay <= numberOfDays)
				{
					rottenApples.push(rightApple);
				}
			}
			print(apples, numberOfRows, numberOfColumns);

		}
		rottenApples.pop();

		print(apples, numberOfRows, numberOfColumns);

	}
	cout << totalAmountOfApples;

}

