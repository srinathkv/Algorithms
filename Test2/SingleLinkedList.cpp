
#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class linkedList
{
private:
	Node* head;
public:
	linkedList():head(NULL){}

	void pushAtFront(int data)
	{
		Node* node = new Node();
		node->data = data;
		node->next = NULL;
		if (head)
		{
			node->next = head;			
		}
		head = node;

	}

	void pushAtEnd(int data)
	{
		Node* node = new Node();
		node->data = data;
		node->next = NULL;

		Node* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = node;
	}

	void reverse()
	{
		Node* prev = NULL, * curr = NULL, * next = NULL;
		curr = head;
		while (curr)
		{
			if (curr->next)
			{
				next = curr->next;					
			}
			curr->next = prev;
	
			prev = curr;
			curr = next;
			next = NULL;			
		}
		head = prev;
	}
	void print()
	{
		Node* temp = head;
		while (temp)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main()
{
	linkedList list;
	list.pushAtFront(20);
	list.pushAtFront(10);
	list.print();
	list.pushAtEnd(30);
	list.pushAtEnd(40);
	list.pushAtEnd(50);
	list.pushAtEnd(60);
	list.pushAtEnd(70);
	list.print();

	list.reverse();
	list.print();
	return 0;
}