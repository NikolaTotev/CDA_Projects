#include <iostream>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode* leftChild = nullptr;
	TreeNode* rightChild = nullptr;

	TreeNode() = default;

	TreeNode(int _data)
	{
		data = _data;
	}

	~TreeNode()
	{
		delete leftChild;
		delete rightChild;
	}

	//Copy constructor
	TreeNode(TreeNode& rhsNode)
	{
		data = rhsNode.data;
		if (rhsNode.leftChild)
		{
			leftChild = new TreeNode(*rhsNode.leftChild);
		}
		if (rhsNode.rightChild)
		{
			rightChild = new TreeNode(*rhsNode.rightChild);
		}
	}

	TreeNode& operator = (const TreeNode& rhsNode)
	{
		if (this != &rhsNode)
		{
			delete rightChild;
			delete leftChild;

			data = rhsNode.data;

			if (rhsNode.leftChild)
			{
				leftChild = new TreeNode(*rhsNode.leftChild);
			}
			if (rhsNode.rightChild)
			{
				rightChild = new TreeNode(*rhsNode.rightChild);
			}
		}
		return *this;
	}
};

struct BinarySearchTree
{
private:
	TreeNode* root = nullptr;

	bool doesNodeExist(int value, TreeNode* currentNode)
	{
		if (currentNode)
		{
			if (currentNode->data == value)
			{
				return true;
			}
			if (value > currentNode->data)
			{
				return doesNodeExist(value, currentNode->rightChild);
			}
			return doesNodeExist(value, currentNode->leftChild);
		}
		return false;
	}

	TreeNode* insertNewNode(int value, TreeNode* current)
	{
		if (!current)
		{
			return new TreeNode(value);
		}
		if (value < current->data)
		{
			current->leftChild = insertNewNode(value, current->leftChild);
		}
		if (value > current->data)
		{
			current->rightChild = insertNewNode(value, current->rightChild);
		}
		return current;
	}

	TreeNode* removeNode(int value, TreeNode* current)
	{
		if (!current)
		{
			return nullptr;
		}
		if (value < current->data)
		{
			current->leftChild = removeNode(value, current->leftChild);
		}
		if (value > current->data)
		{
			current->rightChild = removeNode(value, current->rightChild);
		}
		if (value == current->data)
		{
			if (!current->leftChild && !current->rightChild)
			{
				free(current);
				return nullptr;
			}
			if (!current->leftChild)
			{
				TreeNode* tempRight = current->rightChild;
				free(current);
				return  tempRight;
			}
			if (!current->rightChild)
			{
				TreeNode* tempLeft = current->leftChild;
				free(current);
				return tempLeft;
			}

			TreeNode* swapWith = current->rightChild;
			while (swapWith->leftChild)
			{
				swapWith = swapWith->leftChild;
			}

			current->data = swapWith->data;
			current->rightChild = removeNode(swapWith->data, current->rightChild);
		}
		return current;
	}

	void printInOrder(TreeNode* current)
	{
		if (current)
		{
			printInOrder(current->leftChild);
			cout << current->data << ", ";
			printInOrder(current->rightChild);
		}
	}

public:
	BinarySearchTree() = default;
	BinarySearchTree(const BinarySearchTree* rhsTree)
	{
		root = new TreeNode(*rhsTree->root);
	}

	BinarySearchTree& operator=(const BinarySearchTree& rhsTree)
	{
		if (this != &rhsTree)
		{
			delete root;
			root = new TreeNode(*rhsTree.root);
		}
		return *this;
	}

	~BinarySearchTree()
	{
		delete root;
	}

	bool DoesNodeExist(int value)
	{
		return doesNodeExist(value, root);
	}

	void Insert(int value)
	{
		if (!doesNodeExist(value, root))
		{
			root = insertNewNode(value, root);
		}
	}

	void Remove(int value) {
		if (doesNodeExist(value, root))
		{
			root = removeNode(value, root);
		}
	}

	void PrintInOrder()
	{
		printInOrder(root);
		cout << '\n';
	}
};

int main()
{
	BinarySearchTree newTree;

	newTree.Insert(41);
	newTree.Insert(20);
	newTree.Insert(11);
	newTree.Insert(29);
	newTree.Insert(32);
	newTree.Insert(65);
	newTree.Insert(50);
	newTree.Insert(91);
	newTree.Insert(72);
	newTree.Insert(99);

	newTree.PrintInOrder();

	newTree.Remove(65);

	newTree.PrintInOrder();
}

