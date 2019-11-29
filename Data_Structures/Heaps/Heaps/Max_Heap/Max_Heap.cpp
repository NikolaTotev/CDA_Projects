// Max_Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class MaxHeap
{
private:
	vector<int> heapArray;
	int capacity;
	int size=0;

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

		while(heapArray[pos] > heapArray[parentIndex])
		{
			swap(heapArray[pos], heapArray[parentIndex]);
			if(parentIndex <= 0)
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
				

		if(hasRight && (heapArray[0]<heapArray[leftChildIndex]||heapArray[pos] < heapArray[rightChildIndex]))
		{
			int swapWith = -1;
			if(heapArray[leftChildIndex] > heapArray[rightChildIndex])
			{
				swapWith = leftChildIndex;
			}
			swapWith = rightChildIndex;

			swap(heapArray[pos], heapArray[swapWith]);
			siftDown(swapWith);
		}
		else if(hasLeft && heapArray[pos]<heapArray[leftChildIndex])
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
	void insert(int value)
	{
	
		heapArray.push_back(value);
		if(heapArray.size()!=0)
		{
			siftUp(heapArray.size()-1);
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

int main()
{
	MaxHeap s;
	s.insert(1);
	s.insert(5);
	s.insert(3);
	s.insert(4);
	s.insert(2);

	cout << "Max element: " << s.getMax() << endl;
	s.insert(500);
	cout << "New max element: " << s.getMax() << endl;
	while (!s.isEmpty()) {
		cout << s.getMax() << " ";
		s.extractMax();
	}
	cout << "\n";
}

