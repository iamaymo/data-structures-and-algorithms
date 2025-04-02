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
    p->next = NULL;
    return p;
}

void insert_last(node_ptr& first)
{
    int x;cout << "\t\t";
    cout << "enter value in new node: ";
    cin >> x;
    node_ptr p, q;
    if (first == NULL)
    {
        first = make_new_node(x);
    }
    else
    {
        p = first;
        while (p->next != NULL)
        {
            p = p->next;
        }
        q = make_new_node(x);
        p->next = q;
    }
}

void insert_begin(node_ptr& first)
{
    int x;
    cout << "\t\t";
    cout << "enter value in begining: ";
    cin >> x;
    node_ptr p;
    p = make_new_node(x);
    p->next = first;
    first = p;
}

void insert_middle(node_ptr& first, int n)
{
    int x;
    cout << "\t\t";
    cout << "enter value in new node: ";
    cin >> x;
    node_ptr p, q;
    if (first == NULL)
    {
        first = make_new_node(x);
    }
    else
    {
        p = first;
        while (p->number != n && p->next != NULL)
        {
            p = p->next;
        }
        q = make_new_node(x);
        q->next = p->next;
        p->next = q;
    }
}

void delete_first(node_ptr& first) {
    if (first == NULL) {
        cout << "\t\t";
        cout << "No, nodes found .\n";
    }
    else {
        node_ptr p;
        p = first;
        first = first->next;
        delete p;
    }
}

void delete_last(node_ptr& first) {
    node_ptr p, d;
    p = first;
    if (first == NULL) {
        cout << "\t\t";
        cout << "No nodes found .\n";
    }
    else {
        while (p->next->next != NULL) {
            p = p->next;
        }
        d = p->next;
        p->next = NULL;
        delete d;
    }
}

void delete_middle(node_ptr& first, int m) {
    node_ptr p, d;
    p = first;
    while (p->next->number != m && p->next->next != NULL) {
        p = p->next;
    }
    if (p->next->number != m)
    {
        cout << "\t\t";
        cout << "No node found .\n";
    }
    else
    {
        d = p->next;
        p->next = d->next;
        delete d;
    }
}


void q1(node_ptr& first) {
    if (first && first->next && first->next->next && first->next->next->next && first->next->next->next->next) {
        
        node_ptr p = first->next->next->next->next;

        first->next->next->next->next = p->next;

        p->next = first;

        first = p;
    }
}

void edit_node(node_ptr& first, int s)
{
    int x;
    cout << "\t\t";
    cout << "Enter the new number of node : ";
    cin >> x;
    node_ptr p;
    p = first;
    while (p->number != s && p->next != NULL) {
        p = p->next;
    }
    if (p->number == s) {
        p->number = x;
    }
    else {
        cout << "The number no found\n";
    }
}

int count_of_nodes(node_ptr& first)
{
    node_ptr p;
    p = first;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int sum_numbers_of_nodes(node_ptr& q) {
    node_ptr p;
    p = q;
    int sum = 0;
    while (p != NULL) {
        sum += p->number;
        p = p->next;
    }
    return sum;
}

void display_list(node_ptr first)
{
    node_ptr p;
    if (first == NULL) {
        cout << "\t\t";
        cout << "No, nodes foundds !!";
    }
    else
    {
        cout << "\t\t";
        cout << "nodes : \n";
        p = first;
        int number_of_node = 1;
        while (p != NULL)
        {
            cout << "\t\t";
            cout << "node [" << number_of_node << "] : ";
            cout << p->number << endl;
            p = p->next;
            number_of_node++;
        }
    }
}

int main()
{
    node_ptr first;
    first = NULL;
    int choose;
    int n, m;
done:
    cout << "\n\n\t\tWHAT DO YOU WANT TO DO ??\n\n"
        << "\t*************************************\n"
        << "\t*\t 1- Create alist \t    *\n"
        << "\t*\t 2- Display list \t    *\n"
        << "\t*\t 3- Insert_first \t    *\n"
        << "\t*\t 4- Insert_end \t\t    *\n"
        << "\t*\t 5- Insert_position \t    *\n"
        << "\t*\t 6- Delete_first \t    *\n"
        << "\t*\t 7- Delete_end \t\t    *\n"
        << "\t*\t 8- Delete_position \t    *\n"
        << "\t*\t 9- Edit node \t\t    *\n"
        << "\t*\t10- Numbers of Nodes \t    *\n"
        << "\t*\t11- Summation of nodes \t    *\n"
        << "\t*\t 12- Exit program \t    *\n"
        << "\t*************************************\n";
    cout << "\t\t" << "choose ||";
    cin >> choose;
    cout << endl;
    switch (choose)
    {
    case 1:
        cout << "\t\t";
        cout << "Enter number of nodes to create: ";
        cin >> n;
        first = make_new_node(n);
        goto done;
        break;
    case 2:
        display_list(first);
        goto done;
        break;
    case 3:
        insert_begin(first);
        goto done;
        break;
    case 4:
        insert_last(first);
        goto done;
        break;
    case 5:
        cout << "\t\t";
        cout << "Enter position number: ";
        cin >> n;
        insert_middle(first, n);
        goto done;
        break;


    case 6:
        delete_first(first);
        cout << "\t\t";
        cout << "deleted successfully";
        goto done;
        break;
    case 7:
        delete_last(first);
        cout << "\t\t";
        cout << "deleted successfully";
        goto done;
        break;
    case 8:
        cout << "\t\t";
        cout << "Enter value of node to delete : ";
        cin >> m;
        delete_middle(first, m);
        goto done;
        break;
    case 9:
        cout << "\t\t";
        cout << "Enter number of node to edit : ";
        cin >> m;
        edit_node(first, m);
        goto done;
        break;
    case 10:
        cout << "\t\t";
        cout << "Numbers of Nodes is : " << count_of_nodes(first);
        goto done;
        break;
    case 11:
        cout << "\t\t";
        cout << "Nodes Summation is :";
        cout << "\t\t";
        cout << sum_numbers_of_nodes(first) << "\n";
        goto done;
        break;
    case 100:
        q1(first);
        goto done;
        break;

    default:
        char ok;
    retry:
        cout << "\t\t";
        cout << "Are you sure you want to exit [y / n ] : ";
        cin >> ok;
        if (ok == 'n')
        {
            goto done;
        }
        else if (ok == 'y')
        {
            system("cls");
        }
        else
        {
            cout << "\t\t";
            cout << "You are not press acorrect character ,please Retry do\n";
            cout << "\t\t" << "choose ||";
            cout << "Press [y] to continue or press [n] to exit program\n";
            goto retry;
        }
        break;
    }
    
}