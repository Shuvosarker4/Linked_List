#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_normal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
};

void print_reverse(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
};

void insert_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        cout << endl
             << "Insert at Head" << endl
             << endl;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    cout << endl
         << "Insert at Head" << endl
         << endl;
}

void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        cout << endl
             << "Insert at Tail" << endl
             << endl;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
    cout << endl
         << "Insert at Tail" << endl
         << endl;
};

int size(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert_at_position(Node *head, int pos, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = temp;
    cout << endl
         << "Insert at Position " << pos << endl
         << endl;
};

void delete_from_position(Node *head, int pos)
{
    Node *temp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    temp->next->next->prev = temp;
    delete deleteNode;
    cout << endl
         << "Delete from position " << pos << endl
         << endl;
};

void delete_tail(Node *&head, Node *&tail)
{
    Node *deleteNode = tail;
    tail = tail->prev;
    delete deleteNode;
    if (tail == NULL)
    {
        head = NULL;
        return;
    }
    tail->next = NULL;
    cout << endl
         << "Delete Tail" << endl
         << endl;
};
void delete_head(Node *&head, Node *&tail)
{
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
    if (head == NULL)
    {
        tail = NULL;
        return;
    }
    head->prev = NULL;
    cout << endl
         << "Delete Head" << endl
         << endl;
};
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        cout << "1.Insert at Head" << endl;
        cout << "2.Print List in Normal and Reverse" << endl;
        cout << "3.Insert at Tail" << endl;
        cout << "4.Insert at Position" << endl;
        cout << "5.Delete at Position" << endl;
        cout << "6.Delete the Tail" << endl;
        cout << "7.Delete the Head" << endl;

        int op;
        cin >> op;
        if (op == 1)
        {
            int val;
            cout << "Enter Your Value: ";
            cin >> val;
            insert_head(head, tail, val);
        }
        else if (op == 2)
        {
            cout << "Your Normal Linked List is: ";
            print_normal(head);
            cout << endl;
            cout << "Your Reversed Linked List is: ";
            print_reverse(tail);
            cout << endl;
        }
        else if (op == 3)
        {
            int val;
            cout << "Enter Your Value: ";
            cin >> val;
            insert_tail(head, tail, val);
        }
        else if (op == 4)
        {
            int pos, val;
            cout << "Enter Your Position:";
            cin >> pos;
            cout << "Enter Your Value:";
            cin >> val;
            if (pos > size(head))
            {
                cout << "Invalid Index" << endl
                     << endl;
            }
            else if (pos == 0)
            {
                insert_head(head, tail, val);
            }
            else if (pos == size(head))
            {
                insert_tail(head, tail, val);
            }
            else
            {
                insert_at_position(head, pos, val);
            }
        }
        else if (op == 5)
        {
            int pos;
            cout << "Enter Your Position:";
            cin >> pos;
            if (pos >= size(head))
            {
                cout << "Invalid Index" << endl
                     << endl;
            }
            else if (pos == size(head) - 1)
            {
                delete_tail(head, tail);
            }
            else if (pos == 0)
            {
                delete_head(head, tail);
            }
            else
            {
                delete_from_position(head, pos);
            }
        }
        else if (op == 6)
        {
            delete_tail(head, tail);
        }
        else if (op == 7)
        {
            delete_head(head, tail);
        }
    }

    return 0;
}