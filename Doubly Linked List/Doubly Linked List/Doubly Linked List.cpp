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
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insert_begin(node_ptr& first)
{
    int x;
    cout << "Enter value in new node\n";
    cin >> x;
    node_ptr p;
    p = make_new_node(x);
    p->next = first;
    first->prev = p;
    first = p;
}


void insert_last(node_ptr& first)
{
    int x;
    cout << "Enter value in new node \n";
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
        q->prev = p;
    }
}

//void insert_after(node_ptr& first, int n)
//{
//    int x;
//    cout << "Entr value in new node \n";
//    cin >> x;
//    node_ptr p, q;
//    int flag = 0;
//    if (first == NULL)
//    {
//        first = make_new_node(x);
//    }
//    else
//    {
//        p = first;
//        q = make_new_node(x);
//        while (p->next != NULL)
//        {
//            if (p->number == n)
//            {
//                q->next = p->next;
//                q->next->prev = q;
//                p->next = q;
//                q->prev = p;
//                flag = 1;
//            }
//            p = p->next;
//            cout << p;
//        }
//        if (flag == 0 && p->next == NULL && p->number == n)
//        {
//            p->next = q;
//            q->prev = p;
//            flag = 1;
//        }
//
//        else if (flag == 0 && p->next == NULL)
//        {
//            cout << "\n No number found\n";
//        }
//
//    }
//}

void insert_after(node_ptr& first, int n)
{
    int x;
    cout << "Enter value for new node: ";
    cin >> x;

    node_ptr p, q;
    int flag = 0;

    if (first == NULL)
    {
        first = make_new_node(x);
    }
    else
    {
        p = first;

        while (p != NULL)
        {
            if (p->number == n)
            {
                q = make_new_node(x);
                q->next = p->next;
                if (p->next != NULL)
                    //p->next->prev = q;
                p->next = q;
                q->prev = p;
                p->prev = q->next;
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
    if (first == NULL)
    {
        first = make_new_node(x);
    }
    else
    {
        q = make_new_node(x);
        p = first;

        if (p->number == n)
        {
            q->next = p;
            p->prev = q;
            first = q;
            flag = 1;
        }
        else
        {
            while (p->next != NULL && flag == 0)
            {
                if (p->number == n)
                {
                    q->next = p;
                    q->prev = p->prev;
                    p->prev->next = q;
                    p->prev = q;
                    flag = 1;
                }
                p = p->next;
            }
            if (flag == 0 && p->next == NULL && p->number == n)
            {
                q->next = p;
                q->prev = p->prev;
                p->prev->next = q;
                p->prev = q;
                flag = 1;
            }

            else if (flag == 0 && p->next == NULL)
            {
                cout << "\n No number found\n";
            }
        }
    }
}

void display_list(node_ptr& first)
{
    node_ptr p;
    if (first == NULL)
        cout << "NO, nodes founds>>>";
    else
    {
        cout << "\t The Data in the nodes are :\n";
        p = first;
        while (p != NULL)
        {
            cout << "Value of node ---> ";
            cout << p->number << endl;
            p = p->next;
        }
    }
}

void delete_node(node_ptr& first, int m)
{
    if (first == NULL)
    {
        cout << "No nodes found." << endl;
        return;
    }

    node_ptr p = first;
    int flag = 0;

    // Check if the first node is to be deleted
    if (p->number == m)
    {
        first = p->next;
        if (first != NULL)
            first->prev = NULL;
        delete p;
        flag = 1;
    }
    else
    {
        while (p->next != NULL && flag == 0)
        {
            if (p->number == m)
            {
                p->prev->next = p->next;
                if (p->next != NULL)
                    p->next->prev = p->prev;
                delete p;
                flag = 1;
                break;  // Exit the loop once deletion is done
            }
            p = p->next;
        }

        // Check if the last node is to be deleted
        if (flag == 0 && p->next == NULL && p->number == m)
        {
            p->prev->next = NULL;
            delete p;
            flag = 1;
        }
    }

    if (flag == 0)
    {
        cout << "No number found." << endl;
    }
}

void reverse(node_ptr& first) {

    node_ptr p = first;
    node_ptr prev = nullptr;
    node_ptr next = nullptr;

    while (p != nullptr) {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }

    first = prev;
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
    case 8:
        reverse(first);
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
