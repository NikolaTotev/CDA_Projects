#include <iostream>
#include <vector>
#include<cmath>
#include <iomanip>
using namespace std;


class MaxHeap
{
private:
	vector<int> heapArray;
	int capacity;
	int size = 0;

	int parent(int i) { return((i - 1) / 2); }
	int leftChild(int i) { return (2 * i + 1); }
	int rightChild(int i) { return (2 * i + 2); }

	void swap(int& A, int& B)
	{
		int temp = A;
		A = B;
		B = temp;
	}


	void siftUp(int pos)
	{
		int parentIndex = parent(pos);

		while (heapArray[pos] > heapArray[parentIndex])
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


		if (hasRight && (heapArray[pos] < heapArray[leftChildIndex] || heapArray[pos] < heapArray[rightChildIndex]))
		{
			int swapWith = -1;
			if (heapArray[leftChildIndex] < heapArray[rightChildIndex])
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
		else if (hasLeft && heapArray[pos] < heapArray[leftChildIndex])
		{

			swap(heapArray[pos], heapArray[leftChildIndex]);
			siftDown(leftChildIndex);
		}
	}
	void deleteValue(int value)
	{

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
	void insert(int value)
	{

		heapArray.push_back(value);
		if (heapArray.size() != 0)
		{
			siftUp(heapArray.size() - 1);
		}

	}
	int getMax()
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
class MinHeap
{
private:
	vector<int> heapArray;
	int capacity;
	int size = 0;

	int parent(int i) { return((i - 1) / 2); }
	int leftChild(int i) { return (2 * i + 1); }
	int rightChild(int i) { return (2 * i + 2); }

	void swap(int& A, int& B)
	{
		int temp = A;
		A = B;
		B = temp;
	}


	void siftUp(int pos)
	{
		int parentIndex = parent(pos);

		while (heapArray[pos] < heapArray[parentIndex])
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


		if (hasRight && (heapArray[pos] > heapArray[leftChildIndex] || heapArray[pos] > heapArray[rightChildIndex]))
		{
			int swapWith = -1;
			if (heapArray[leftChildIndex] > heapArray[rightChildIndex])
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
		else if (hasLeft && heapArray[pos] > heapArray[leftChildIndex])
		{

			swap(heapArray[pos], heapArray[leftChildIndex]);
			siftDown(leftChildIndex);
		}
	}
	void deleteValue(int value)
	{

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
	void insert(int value)
	{

		heapArray.push_back(value);
		if (heapArray.size() != 0)
		{
			siftUp(heapArray.size() - 1);
		}

	}
	int getMin()
	{
		return heapArray[0];
	}
	void extractMin()
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
double checkResult(MaxHeap max, MinHeap min, int currentNumberOfCitizens)
{
	if (max.heapSize() == 1 && min.heapSize() == 1)
	{
		return max.getMax();

	}
	int halfwayMark = currentNumberOfCitizens / 2;
	int i = 0;
	while (i < ceil(halfwayMark)) {

		min.extractMin();
		i++;
	}

	while (i < currentNumberOfCitizens) {

		max.extractMax();
		i++;
	}

	
	double minTop = min.getMin();
	double maxTop = max.getMax();
	if (currentNumberOfCitizens % 2 != 0)
	{
		return minTop;
	}
	double result = (minTop + maxTop) / 2;
	return result;
}
int main()
{
	MinHeap minHeap;
	MaxHeap maxHeap;

	int numberOfCitizens;
	cin >> numberOfCitizens;
	vector<double> results;
	int input;
	int numberOfCitizensAdded = 0;
	for (int i = 0; i < numberOfCitizens; ++i)
	{
		cin >> input;
		minHeap.insert(input);
		maxHeap.insert(input);
		numberOfCitizensAdded++;
		results.push_back(checkResult(maxHeap, minHeap, numberOfCitizensAdded));
	}

	for (int i = 0; i < numberOfCitizens; ++i)
	{
		cout <<fixed<< setprecision(2) << results[i] << endl;
	}
}

