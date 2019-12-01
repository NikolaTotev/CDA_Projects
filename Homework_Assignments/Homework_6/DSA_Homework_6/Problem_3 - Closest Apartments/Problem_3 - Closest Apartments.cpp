#include <iostream>
#include <vector>
using namespace std;
struct point
{
	point()
	{
		coordX = 0;
		coordY = 0;
		distToFMI = 0;
	}
	point& operator = (point &rhs)
	{
		if (this != &rhs)
		{
			coordX = rhs.coordX;
			coordY = rhs.coordY;
			distToFMI = rhs.distToFMI;
		}
		return *this;
	}
	point(double x, double y, double dist)
	{
		coordX = x;
		coordY = y;
		distToFMI = dist;
	}
	double coordX;
	double coordY;
	double distToFMI;
};


class MaxHeap
{
private:
	std::vector<point> heapArray;
	int capacity;
	int size = 0;

	int parent(int i) { return((i - 1) / 2); }
	int leftChild(int i) { return (2 * i) + 1; }
	int rightChild(int i) { return (2 * i) + 2; }

	void swap(point& A, point& B)
	{
		point temp = A;
		A = B;
		B = temp;
	}


	void siftUp(int pos)
	{
		int parentIndex = parent(pos);

		while (heapArray[pos].distToFMI > heapArray[parentIndex].distToFMI)
		{

			swap(heapArray[pos], heapArray[parentIndex]);
			if (parentIndex <= 0)
			{
				return;
			}
			parentIndex = parent(parentIndex);
			pos = parent(pos);
		}


	}

	void siftDown(int pos)
	{
		int leftChildIndex = leftChild(pos);
		int rightChildIndex = rightChild(pos);

		bool hasLeft = leftChildIndex < heapArray.size();
		bool hasRight = rightChildIndex < heapArray.size();


		if (hasRight && (heapArray[pos].distToFMI < heapArray[leftChildIndex].distToFMI
			|| heapArray[pos].distToFMI < heapArray[rightChildIndex].distToFMI))
		{
			int swapWith = -1;
			if (heapArray[leftChildIndex].distToFMI < heapArray[rightChildIndex].distToFMI)
			{
				swapWith = rightChildIndex;
			}
			else
			{
				swapWith = leftChildIndex;
			}

			swap(heapArray[pos], heapArray[swapWith]);
			siftDown(swapWith);
		}
		else if (hasLeft && heapArray[pos].distToFMI < heapArray[leftChildIndex].distToFMI)
		{
			swap(heapArray[pos], heapArray[leftChildIndex]);
			siftDown(leftChildIndex);
		}
	}

public:
	bool isEmpty()
	{
		return heapArray.size() == 0;
	}
	int heapSize()
	{
		return heapArray.size();
	}
	void insert(point value)
	{

		heapArray.push_back(value);
		if (heapArray.size() != 0)
		{
			siftUp(heapArray.size() - 1);
		}

	}
	point getMax()
	{
		return heapArray[0];
	}
	void extractMax()
	{
		if (isEmpty())
		{
			return;
		}
		swap(heapArray[0], heapArray[heapArray.size() - 1]);
		heapArray.pop_back();
		siftDown(0);
	}
};
void merge(point* arr, point* helper, int start, int mid, int end)
{

	int left1 = start;
	int left2 = mid;
	int i = start;

	for (; left1 < mid && left2 < end; ++i)

	{
		if (arr[left1].distToFMI <= arr[left2].distToFMI)
		{
			if (arr[left1].distToFMI == arr[left2].distToFMI)
			{
				if (arr[left1].coordX < arr[left2].coordX)
				{
					helper[i] = arr[left1++];
					
				}
				else
				{
					helper[i] = arr[left2++];
				}
			}
			else {
				helper[i] = arr[left1++];
			}
			/*if (arr[left1].distToFMI <= arr[left2].distToFMI)
			{
				helper[i] = arr[left1++];
			}
			else
			{
				helper[i] = arr[left2++];
			}*/
		}
		else
		{
			helper[i] = arr[left2++];
		}
	}

	while (left1 < mid)
	{
		helper[i++] = arr[left1++];
	}

	while (left2 < end)
	{
		helper[i++] = arr[left2++];
	}

	for (int j = start; j < end; ++j)
	{
		arr[j] = helper[j];
	}

}

void merge_sort(point* arr, point* helper, int leftLim, int rightLim)
{
	if (leftLim + 1 < rightLim)
	{

		int middle = (leftLim + rightLim) / 2;
		merge_sort(arr, helper, leftLim, middle);
		merge_sort(arr, helper, middle, rightLim);
		merge(arr, helper, leftLim, middle, rightLim);
	}

}
double calculateDistance(double coordX, double coordY)
{
	return sqrt(pow(coordX, 2) + pow(coordY, 2));
}
int main()
{
	MaxHeap maxHeap;

	int numberOfApartments;
	int apartmentsToFind;
	cin >> numberOfApartments >> apartmentsToFind;


	double inputX;
	double inputY;
	for (int i = 0; i < numberOfApartments; ++i)
	{
		cin >> inputX >> inputY;
		double dist = calculateDistance(inputX, inputY);
		point pointToInsert(inputX, inputY, dist);
		if (maxHeap.heapSize() == apartmentsToFind)
		{
			if (maxHeap.getMax().distToFMI > dist)
			{
				maxHeap.extractMax();
				maxHeap.insert(pointToInsert);
			}
		}
		else
		{
			maxHeap.insert(pointToInsert);
		}
	}
	point* finalVect = new point[maxHeap.heapSize()];
	point* helper = new point[maxHeap.heapSize()];
	int size = maxHeap.heapSize();
	for (int i = 0; i < size; ++i)
	{
		point p = maxHeap.getMax();
		finalVect[i] = p;
		maxHeap.extractMax();
	}

	merge_sort(finalVect , helper, 0, size);

	for (int i = 0; i < apartmentsToFind; i++)
	{
		cout << finalVect[i].coordX << " " << finalVect[i].coordY << endl;
	}
}


