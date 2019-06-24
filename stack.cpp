/* 
Hamed Mirlohi
Full Implementation of STACK (LIFO)
Using SMART POINTERS
*/

#include <iostream>
#include <memory>

typedef enum 
{
	POP = 2,
	PUSH,
	EXIT
}SELECTIONS;

using namespace std;

template<class T>
class Stack
{
	struct node
	{
		T data;
		shared_ptr<node> next;
	};

	shared_ptr<node> head;		// hold the address of the first node
	uint16_t size;

public:
	Stack(uint16_t length) : size(length)
	{
		if (length < 1)		// no node creation required
			return;

		head = make_shared<node>();	// at least one node requested, create one
		head->next = nullptr;
		head->data = 0;
		shared_ptr<node> tmp = head;
		int count = 1;

		while (length > 1)
		{
			tmp->next = make_shared<node>();
			tmp = tmp->next;
			tmp->next = nullptr;
			tmp->data = count;
			count++;
			--length;
		}

	}

	virtual ~Stack()
	{
		// nothing to delete since smart pointers are used
	}

	void display_stack()
	{
		shared_ptr<node> tmp = head;
		while (tmp != nullptr)
		{
			cout << tmp << ": " << tmp->data << endl;
			tmp = tmp->next;
		}
	}

	// LIFO(Last In First Out)
	void pop_stack()
	{
		
		if (head == nullptr)
		{
			cout << "nothing to pop" << endl;
			return;
		}

		shared_ptr<node> tmp = head;
		head = head->next;
		//delete tmp;
		return;
	}

	void push_stack()
	{
		shared_ptr<node> tmp = head;
		head = make_shared<node>();
		head->next = tmp;
	}

};

int main()
{
	Stack<int> s1(3);

	int choice;
	
	while (true)
	{
		s1.display_stack();
	
		cout << "\n2. Pop: " << endl;
		cout << "3. Push: " << endl;
		cout << "4. Exit " << endl;
		cout << "--------------------------" << endl;

		cin >> choice;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(20);
			continue;
		}

		switch (choice)
		{
		case(POP):
			s1.pop_stack();
			break;
		case(PUSH):
			s1.push_stack();
			break;
		case(EXIT):
			return 0;
		default:
			cout << "incorrect input" << endl;
		}
	}
}