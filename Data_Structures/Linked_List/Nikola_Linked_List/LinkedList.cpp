
#include <iostream>

class ListNode
{
public:

	int data;
	ListNode* next;
};
class LinkedList
{
public:
	ListNode* head;
	ListNode* tail;

	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	void insertAtStart(int nodeData)
	{
		ListNode* newHead = new ListNode();

		newHead->data = nodeData;
		newHead->next = head;
		head = newHead;
	}

	void insertAtPosition(int nodeData, int position)
	{
		ListNode* previous;
		ListNode* current;
		ListNode* newNode = new ListNode();
		current = head;
		newNode->data = nodeData;
		for (int i = 0; i < position; ++i)
		{
			previous = current;
			current = current->next;
		}

		previous->next = newNode;
		newNode->next = current;
	}

	void insertAtEnd(int nodeData)
	{
		ListNode* newNode = new ListNode();
		newNode->data = nodeData;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
		}
	}

	void deleteFirst()
	{
		ListNode* temp;
		temp = head;
		if (head != nullptr)
		{
			head = head->next;
			delete temp;
		}

	}

	void deleteAtposition(int position)
	{
		ListNode* current;
		ListNode* previous;
		ListNode* temp;
		current = head;
		for (int i = 0; i < position; ++i)
		{
			previous = current;
			current = current->next;
		}
		temp = current;
		previous->next = current->next;
		delete temp;
	}

	void deleteLast()
	{
		ListNode* current;
		ListNode* previous;

		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = nullptr;
		delete current;
	}
	void print()
	{
		ListNode* temp;
		temp = head;
		while (temp->next != nullptr)
		{
			std::cout << temp->data;
			temp = temp->next;
		}
	}

	bool searchList(int itemToFind)
	{
		ListNode* iterator = head;
		while (iterator->next != nullptr)
		{
			if (iterator->data == itemToFind)
			{
				return true;
			}
		}

		return false;
	}

	void reverseList()
	{
		if (head != nullptr)
		{

			ListNode* current = head->next;
			ListNode* last = head;
			head->next = nullptr;
			ListNode* nextOne;
			while (current->next != nullptr)
			{
				nextOne = current->next;
				current->next = nextOne->next;
				last = current;
				current = nextOne;
			}
		}
	}

};
