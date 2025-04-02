#include <iostream>
using namespace std;
struct node
{
    int number;
    node* next;
    node* prev;
};
typedef node* node_ptr;

node_ptr make_new_node(int x)
{
    node_ptr p;
    p = new node;
    p->number = x;
    p->next = p;
    p->prev = p;
    return p;
}

void insert_begin(node_ptr& first)
{
    int x;
    cout << "Enter value in new node\n";
    cin >> x;

    node_ptr p;
    p = make_new_node(x);

    if (first == nullptr) {
        first = p;
    }
    else {
        p->next = first;
        p->prev = first->prev;
        first->prev->next = p;
        first->prev = p;
        first = p;
    }
}


void insert_last(node_ptr& first)
{
    int x;
    cout << "Enter value in new node \n";
    cin >> x;

    node_ptr p, q;
    if (first == nullptr)
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
        q->prev = p;
        q->next = first;
        first->prev = q;
    }
}

void insert_after(node_ptr& first, int n)
{
    int x;
    cout << "Enter value for new node: ";
    cin >> x;

    node_ptr p, q;
    int flag = 0;

    if (first == nullptr)
    {
        first = make_new_node(x);
    }
    else
    {
        p = first;

        while (p != first)
        {
            if (p->number == n)
            {
                q = make_new_node(x);
                q->next = p->next;
                q->prev = p;
                p->next->prev = q;
                p->next = q;
                flag = 1;
                break;
            }
            p = p->next;
        }

        if (flag == 0)
        {
            cout << "\n Number not found\n";
        }
    }
}


void insert_before(node_ptr& first, int n)
{
    int x;
    cout << "Entr value in new node \n";
    cin >> x;

    node_ptr p, q;
    int flag = 0;

    if (first == nullptr)
    {
        first = make_new_node(x);
    }
    else 
    {
        p = first;

        do {
            if (p->number == n) {
                q = make_new_node(x);
                q->next = p;
                q->prev = p->prev;
                p->prev->next = q;
                p->prev = q;

                if (p == first) {
                    first = q;
                }

                flag = 1;
                break;
            }
            p = p->next;
        } while (p != first);

        if (flag == 0) {
            cout << "\nNumber not found\n";
        }
    }
}

void display_list(node_ptr& first)
{
    node_ptr p;
    if (first == nullptr)
        cout << "NO, nodes founds>>>";
    else
    {
        cout << "\t The Data in the nodes are :\n";
        p = first;
        while (p != first)
        {
            cout << "Value of node ---> ";
            cout << p->number << endl;
            p = p->next;
        }
    }
}

void delete_node(node_ptr& first, int m)
{
    if (first == nullptr)
    {
        cout << "No nodes found." << endl;
        return;
    }

    node_ptr p = first;
    int flag = 0;

   if (p->number == m) {
       if (p->next == p) {
           delete p;
           first = nullptr;
       }
       else {
           first = p->next;
           first->prev = p->prev;
           p->prev->next = first;
           delete p;
       }
       flag = 1;
   }
   else {
       do {
           if (p->number == m) {
               p->prev->next = p->next;
               p->next->prev = p->prev;
               delete p;
               flag = 1;
           }
           p = p->next;
       } while (p != first);
   }

   if (flag == 0) {
       cout << "No number found." << endl;
   }
}



int main()
{
    node_ptr first;
    first = NULL;
    int choose;
    int n, m;
done:
    cout << "\n\n\t\t WHAT DO YOU WANT TO DO ??\n\n"
        << "\t*************************************\n"
        << "\t*\t 1- Create alist *\n"
        << "\t*\t 2- Display list *\n"
        << "\t*\t 3- Insert_first *\n"
        << "\t*\t 4- Insert_end *\n"
        << "\t*\t 5- Insert_after *\n"
        << "\t*\t 6- Insert_before *\n"
        << "\t*\t 7- Delete_node *\n"
        << "\t*\t 8- Exit program *\n"
        << "\t*************************************\n";

    cin >> choose;
    switch (choose)
    {
    case 1:
        cout << "\t Enter number of nodes to create\n";
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
        cout << "Enter position number after node:\n";
        cin >> n;
        insert_after(first, n);
        goto done;
        break;
    case 6:
        cout << "Enter position number before node:\n";
        cin >> n;
        insert_before(first, n);
        goto done;
        break;
    case 7:
        cout << "\t Enter value of node to delete\n";
        cin >> m;
        delete_node(first, m);
        goto done;
        break;
    default:
        char ok;
    retry:
        cout << "Are you sure you want to exit [y / n ]\n";
        cin >> ok;
        if (ok == 'n')
        {
            goto done;
        }
        else if (ok == 'y')
        {
        }
        else
        {
            cout << "You are not press acorrect character ,please Retry do\n";
            cout << "Press [y] to continue or press [n] to exit program\n";
            goto retry;
        }
        break;
    }
}


