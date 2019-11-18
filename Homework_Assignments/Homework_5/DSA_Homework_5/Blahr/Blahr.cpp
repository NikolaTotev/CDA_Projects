#include <iostream>
#include <queue>
using namespace std;
bool rottenMap[10001][10001];
struct Apple
{
	bool isRotten = false;
	int dayID;
	int coord_X;
	int coord_Y;
};
void print(bool apples, int numberOfRows, int numberOfColumns)
{
	for (int i = numberOfRows - 1; i >= 1; --i)
	{
		for (int j = 1; j < numberOfColumns; ++j)
		{
			
			cout  << rottenMap[i][j] ;
			

		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
bool isValid(int coord_X, int coord_Y)
{
	if (coord_X > 10001 || coord_X < 0)
	{
		return false;
	}

	if(coord_Y > 10001 || coord_Y < 0)
	{
		return false;
	}
	if(rottenMap[coord_X][coord_Y])
	{
		return false;
	}
	return true;
}
int main()
{
	bool printIt = true;
	int numberOfRows;
	int numberOfColumns;
	int numberOfDays;
	cin >> numberOfRows;
	cin >> numberOfColumns;
	cin >> numberOfDays;
	int totalAmountOfApples = numberOfRows * numberOfColumns;

	
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
		if (day == 1)
		{
			rottenApple_1.coord_X = coordX-1;
			rottenApple_1.coord_Y = coordY-1;
			rottenMap[coordX][coordY] = true;
			rottenApples.push(rottenApple_1);
			totalAmountOfApples--;
		}
		else
		{
			rottenApple_2.coord_X = coordX-1;
			rottenApple_2.coord_Y = coordY-1;
			rottenMap[coordX][coordY] = true;
			rottenApples.push(rottenApple_2);
			totalAmountOfApples--;
		}
		
		day++;
	}
	if(printIt)
	{
		print(rottenMap, numberOfRows, numberOfColumns);
	}

	Apple currentApple;
	int currentDay = 1;
	while (!rottenApples.empty()&&currentDay<=numberOfDays)
	{
		currentApple = rottenApples.front();
		if (currentApple.dayID > currentDay)
		{
			currentDay = currentApple.dayID;
		}


		///Rot to the top OK
		
			Apple topApple;
			topApple.coord_X = currentApple.coord_X + 1;
			topApple.coord_Y = currentApple.coord_Y;

			if (isValid(topApple.coord_X, topApple.coord_Y))
			{
				rottenMap[topApple.coord_X][topApple.coord_Y] = true;
				topApple.dayID = currentDay + 1;
				totalAmountOfApples--;

				if (currentDay < numberOfDays)
				{
					rottenApples.push(topApple);
				}
			}
			if (printIt)
			{
				print(rottenMap, numberOfRows, numberOfColumns);
			}

	

		///Rot to the bottom OK
		
			Apple bottomApple;
			bottomApple.coord_X = currentApple.coord_X - 1;
			bottomApple.coord_Y = currentApple.coord_Y;
			if (isValid(bottomApple.coord_X, bottomApple.coord_Y))
			{
				rottenMap[bottomApple.coord_X][bottomApple.coord_Y] = true;
				bottomApple.dayID = currentDay + 1;
				totalAmountOfApples--;

				if (currentDay < numberOfDays)
				{
					rottenApples.push(bottomApple);
				}
			}
			if (printIt)
			{
				print(rottenMap, numberOfRows, numberOfColumns);
			}

		

		///Rot to the left; 
		
			Apple leftApple;
			leftApple.coord_X = currentApple.coord_X;
			leftApple.coord_Y = currentApple.coord_Y-1;
			if (isValid(leftApple.coord_X, leftApple.coord_Y))
			{
				rottenMap[leftApple.coord_X][leftApple.coord_Y] = true;
				leftApple.dayID = currentDay + 1;
				totalAmountOfApples--;

				if (currentDay < numberOfDays)
				{
					rottenApples.push(leftApple);
				}
			}
			if (printIt)
			{
				print(rottenMap, numberOfRows, numberOfColumns);
			}

		

		///Rot to the right; 
		
			Apple rightApple;
			rightApple.coord_X = currentApple.coord_X;
			rightApple.coord_Y = currentApple.coord_Y+1;

			if (isValid(rightApple.coord_X, rightApple.coord_Y))
			{
				rottenMap[rightApple.coord_X][rightApple.coord_Y] = true;				
				rightApple.dayID = currentDay + 1;
				totalAmountOfApples--;

				if (currentDay < numberOfDays)
				{
					rottenApples.push(rightApple);
				}
			}
			if (printIt)
			{
				print(rottenMap, numberOfRows, numberOfColumns);
			}
		
		rottenApples.pop();

		if (printIt)
		{
			print(rottenMap, numberOfRows, numberOfColumns);
		}

	}

	int sum = 0;

	for (int i = numberOfRows-1; i >0; --i)
	{
		for (int j = 0; j < numberOfColumns; ++j)
		{
			if(!rottenMap[j][i])
			{
				sum++;
			}
		}
	}
	cout << sum;

}

