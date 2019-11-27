#include <iostream>

#define max(a, b)((a)>(b)?(a):(b))

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

struct AVL_Node
{
	int data;
	int height;
	AVL_Node* leftChild;
	AVL_Node* rightChild;

	AVL_Node() = default;

	AVL_Node(int input)
	{
		data = input;
	}

	AVL_Node(AVL_Node const& rhs)
	{
		data = rhs.data;
		if (rhs.rightChild)
		{
			rightChild = rhs.rightChild;
		}
		if (rhs.leftChild)
		{
			leftChild = rhs.leftChild;
		}
	}

	~AVL_Node()
	{
		delete leftChild;
		delete rightChild;
	}

	AVL_Node& operator = (const AVL_Node& rhs)
	{
		if (this != &rhs)
		{
			delete rightChild;
			delete leftChild;

			data = rhs.data;
			if (rhs.rightChild)
			{
				rightChild = rhs.rightChild;
			}
			if (rhs.leftChild)
			{

				leftChild = rhs.leftChild;
			}
		}
		return *this;
	}

	void calculateHeight()
	{
		height = 0;
		if (leftChild)
		{
			height = max(height, leftChild->height + 1);
		}
		if (rightChild)
		{
			height = max(height, rightChild->height + 1);
		}
	}

	int leftHeight()
	{
		if (leftChild)
		{
			return  leftChild->height + 1;
		}
		return 0;
	}

	int rightHeight()
	{
		if (rightChild)
		{
			return  rightChild->height + 1;
		}
		return 0;
	}

	int balance()
	{
		return  leftHeight() - rightHeight();
	}

	void rotateRight()
	{
		if (!leftChild)
		{
			return;
		}
		AVL_Node* leftRight = this->leftChild->rightChild;
		AVL_Node* oldRight = this->rightChild;

		swap(this->data, this->leftChild->data);
		this->rightChild = this->leftChild;
		this->leftChild = this->leftChild->leftChild;
		this->rightChild->leftChild = leftRight;
		this->rightChild->rightChild = oldRight;

	}

	void rotateLeft()
	{
		if (!rightChild)
		{
			return;
		}
		AVL_Node* rightLeft = this->rightChild->leftChild;
		AVL_Node* oldLeft = this->leftChild;

		swap(this->data, this->rightChild->data);
		this->leftChild = this->rightChild;
		this->rightChild = this->rightChild->rightChild;
		this->leftChild->leftChild = oldLeft;
		this->leftChild->rightChild = rightLeft;
	}

	void recalculateHeights()
	{
		if (leftChild)
		{
			leftChild->calculateHeight();
		}
		if (rightChild)
		{
			rightChild->calculateHeight();
		}
		this->calculateHeight();
	}

	void fixTree() {
		if (balance() < -1) { // Right is heavier
			if (rightChild->balance() <= -1) { // RR
				this->rotateLeft();
				recalculateHeights();
			}
			if (rightChild->balance() >= 1) { // RL
				rightChild->rotateRight();
				this->rotateLeft();
				recalculateHeights();
			}
		}
		if (balance() > 1) { // Left is heavier
			if (leftChild->balance() >= 1) { // LL
				this->rotateRight();
				recalculateHeights();
			}
			if (leftChild->balance() <= -1) { // LR
				leftChild->rotateLeft();
				this->rotateRight();
				recalculateHeights();
			}
		}
	}


};

class AVL_Tree
{
private:
	AVL_Node* root = nullptr;

	bool _checkExistance(int value, AVL_Node* current)
	{
		if (current)
		{
			if (current->data == value)
			{
				return true;
			}
			if (current->data < value)
			{
				return _checkExistance(value, current->rightChild);
			}
			if (current->data > value)
			{
				return _checkExistance(value, current->leftChild);
			}
		}
		return false;
	}

	AVL_Node* _insert(int value, AVL_Node* current)
	{
		if (!current)
		{
			return new AVL_Node(value);
		}
		if (value > current->data)
		{
			current->rightChild = _insert(value, current->rightChild);
		}
		if (value < current->data)
		{
			current->leftChild = _insert(value, current->leftChild);
		}

		current->calculateHeight();
		current->fixTree();
		return  current;
	}

	AVL_Node* _remove(int value, AVL_Node* current)
	{
		if (!current)
		{
			return nullptr;
		}
		if (value < current->data)
		{
			current->leftChild = _remove(value, current->leftChild);
		}
		if (value > current->data)
		{
			current->rightChild = _remove(value, current->rightChild);
		}
		if (value == current->data)
		{
			if (!current->rightChild && current->leftChild)
			{
				free(current);
				return nullptr;
			}
			if (!current->rightChild)
			{
				AVL_Node* tempRight = current->leftChild;
				free(current);
				return  tempRight;
			}
			if (!current->leftChild)
			{
				AVL_Node* tempLeft = current->rightChild;
				free(current);
				return  tempLeft;
			}
			AVL_Node* swapWith = current->rightChild;
			while (swapWith->leftChild)
			{
				swapWith = swapWith->leftChild;
			}
			current->data = swapWith->data;
			current->rightChild = _remove(swapWith->data, current->rightChild);

		}

		current->calculateHeight();
		current->fixTree();
		return current;
	}
public:
	bool DoesNodeExist(int value)
	{
		return _checkExistance(value, root);
	}
	void InsertNode(int value)
	{
		root = _insert(value, root);
	}
	void RemoveNode(int value)
	{
		root = _remove(value, root);
	}
};

int main()
{
	std::cout << "Hello World!\n";
}

