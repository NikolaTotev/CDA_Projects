#include <iostream>

int main()
{
	std::cout << "Hello World!\n";
	/*
	 *Swap head and tail, then reverse the ones in between.
	 *In order to reverse the ones in between we need a total of 3 pointers.
	 *
	 *We start from the second element of the initial list.
	 *Store somewhere what the prev and next element are, then we rev the arrow.
	 *
	 *
	 *
	 */
}
struct Node
{
	int info;
	Node* next;
};

Node* reverse(Node* head)
{
	if(head == nullptr)
	{
		return head;
	}
	Node* current = head->next;
	Node* last = head;

	head->next = nullptr;

	while (current!= nullptr)
	{
		Node* next = current->next;
		current->next = last;
		last = current;
		current = next;
	}
	return last;
}

