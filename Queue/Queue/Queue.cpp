#include <iostream>
using namespace std;

struct node
{
	int number;
	node* next;
};
typedef node* node_ptr;

node_ptr make_new_node(int x)
{
	node_ptr p;
	p = new node;
	p->number = x;
	p->next = nullptr;
	return p;
}
void push(node_ptr& first) {
	int x;
	if (first == NULL) {
		cout << "Enter value in First Queue\n";
		cin >> x;
		first = make_new_node(x);
	}
	else {
		cout << "Enter value in Queue\n";
		cin >> x;
		node_ptr p;
		p = make_new_node(x);
		p->next = first;
		first = p;
	}
}

void pop(node_ptr& first) {
	node_ptr p, q;
	p = first;
	int r;
	if (first == nullptr)
	{
		cout << "No Nodes Found!!\n";
	}
	else if (p->next == nullptr) {
		r = p->number;
		first = nullptr;
		delete p;
		cout << "Number Of Deleted Node ->" << r << endl;
	}
	else {
		while (p->next->next != nullptr)
		{
			p = p->next;
		}
		q = p->next;
		r = q->number;
		p->next = nullptr;
		delete q;
		cout << "Number Of Deleted Node ->" << r << endl;
	}
}

void display(const node_ptr& first) {
	if (first == nullptr) {
		cout << "Queue is empty.\n";
		return;
	}

	cout << "Elements in the queue: ";
	node_ptr current = first;
	while (current != nullptr) {
		cout << current->number << " ";
		current = current->next;
	}
	cout << endl;
}


int main()
{
	cout << "\t\t\t\t\t ********Welcomr to my program******** \n";
	node_ptr first = NULL;
	int r;
queue:
	cout << "\n\n\t WHAT DO YOU WANT TO DO ??\n\n"
		<< "\t*************************************\n"
		"\t*\t 1- Push *\n"
		<< "\t*\t 2- Pop *\n"
		<< "\t*\t 3- Display queue *\n"
		<< "\t*\t 4- Exit program *\n"
		<< "\t*************************************\n";
	cin >> r;
	switch (r)
	{
	case 1:
		push(first);
		goto queue;
		break;
	case 2:
		pop(first);
		goto queue;
		break;
	case 3:
		display(first);
		goto queue;
		break;
	default:
		char ok;
	done:
		cout << "Are you sure you want to exit [y / n ]\n";
		cin >> ok;
		if (ok == 'n')
		{
			goto queue;
		}
		else if (ok == 'y')
		{
		}
		else
		{
			cout << "You are not press acorrect character ,please Retry do\n";
			cout << "Press [y] to continue or press [n] to exit program\n";
			goto done;
		}
		cout << "\t\t\t\t\t ********Goodbay see you later******** \n";
		break;
	}

}