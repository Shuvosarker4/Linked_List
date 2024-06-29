#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        cout << endl
             << "Insert At Head" << endl
             << endl;
        return;
    }
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    cout << endl
         << "Insert At Tail" << endl
         << endl;
};

void print_linked_list(Node *head)
{
    cout << endl;
    cout << "Your Linked List: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
};

void insert_at_position(Node *head, int pos, int v)
{
    Node *newNode = new Node(v);
    Node *temp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << endl
                 << "Invalid Index" << endl
                 << endl;
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << endl
         << "Inserted at position" << " " << pos << endl
         << endl;
};

void delete_from_position(Node *head, int pos)
{
    Node *temp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << endl
             << "Invalid Position" << endl
             << endl;
    }

    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    cout << endl
         << "Node is Deleted at " << pos << endl
         << endl;
};

void delete_head(Node *&head)
{
    Node *deleteNode = head;
    if (head == NULL)
    {
        cout << endl
             << "No Node Available" << endl
             << endl;
    }
    head = head->next;
    delete deleteNode;
    cout << endl
         << "Head Node Deleted" << endl
         << endl;
};

void insert_at_head(Node *&head, int v)
{
    Node *newNode = new Node(v);
    Node *temp = head;
    newNode->next = head;
    head = newNode;
    cout << endl
         << "Inserted At Head" << endl
         << endl;
};
int main()
{
    Node *head = NULL;

    while (true)
    {
        cout << "1: Insert At Tail" << endl;
        cout << "2: Print Linked List" << endl;
        cout << "3: Insert At any Position" << endl;
        cout << "4: Insert At Head" << endl;
        cout << "5: Delete From Position" << endl;
        cout << "6: Delete Head" << endl;
        cout << "7: Terminated" << endl;

        int op;
        cin >> op;
        if (op == 1)
        {
            cout << "Please Enter Value: ";
            int v;
            cin >> v;
            insert_at_tail(head, v);
        }
        else if (op == 2)
        {
            print_linked_list(head);
        }
        else if (op == 3)
        {
            int pos, v;
            cout << "Enter Position: ";
            cin >> pos;
            cout << "Enter Value: ";
            cin >> v;
            insert_at_position(head, pos, v);
        }
        else if (op == 4)
        {
            int v;
            cout << "Enter your value: ";
            cin >> v;
            insert_at_head(head, v);
        }
        else if (op == 5)
        {
            int pos;
            cout << "Enter Position: ";
            cin >> pos;
            if (pos == 0)
            {
                delete_head(head);
            }
            else
            {
                delete_from_position(head, pos);
            }
        }
        else if (op == 6)
        {
            delete_head(head);
        }
        else if (op == 7)
        {
            break;
        }
    }
    return 0;
}