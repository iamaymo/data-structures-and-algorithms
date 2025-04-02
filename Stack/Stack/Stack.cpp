#include <iostream>
using namespace std;

struct node {
    int number;
    node* next;
};

typedef node* node_ptr;

node_ptr make_new_node(int x) {
    node_ptr p = new node;
    p->number = x;
    p->next = nullptr;
    return p;
}

void push(node_ptr& top) {
    int x;
    cout << "Enter value to push: ";
    if (!(cin >> x)) {
        cout << "Invalid input. Please enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    node_ptr p = make_new_node(x);
    p->next = top;
    top = p;
}

void pop(node_ptr& top) {
    if (top == nullptr) {
        cout << "Stack is empty. Cannot pop.\n";
        return;
    }

    node_ptr p = top;
    int r = p->number;
    top = top->next;
    delete p;
    cout << "Number of deleted node: " << r << endl;
}

void delete_stack(node_ptr& top) {
    while (top != nullptr) {
        node_ptr temp = top;
        top = top->next;
        delete temp;
    }
}

int peek(const node_ptr& top) {
    if (top == nullptr) {
        cout << "Stack is empty. Cannot peek.\n";
        return 0;
    }
    else {
        return top->number;
    }
}


int main() {
    cout << "********Welcome to my program********\n";
    node_ptr top = nullptr;
    int choice;

    do {
        cout << "\n\nWHAT DO YOU WANT TO DO?\n";
        cout << "*************************************\n";
        cout << "* 1- Push                           *\n";
        cout << "* 2- Pop                            *\n";
        cout << "* 3- Peek                           *\n";
        cout << "* 4- Exit program                   *\n";
        cout << "*************************************\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            push(top);
            break;
        case 2:
            pop(top);
            break;
        case 3:
            cout << "Top element of the stack: " << peek(top) << endl;
            break;
        case 4:
            cout << "Are you sure you want to exit? [y/n]: ";
            char response;
            cin >> response;
            if (response == 'y' || response == 'Y') {
                cout << "********Goodbye. See you later!********\n";
                delete_stack(top);
                return 0;
            }
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (true);

    return 0;
}
