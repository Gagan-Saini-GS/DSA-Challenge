#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeInput()
{
    int data;
    cin >> data;

    Node *head = NULL;
    Node *temp = head;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
        cin >> data;
    }

    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
    Node *fh = NULL;
    Node *ft = NULL;
    Node *h1 = head1;
    Node *h2 = head2;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data <= h2->data)
        {
            if (fh == NULL && ft == NULL)
            {
                fh = h1;
                ft = h1;
            }
            else
            {
                ft->next = h1;
                ft = ft->next;
            }
            h1 = h1->next;
        }
        else
        {
            if (fh == NULL && ft == NULL)
            {
                fh = h2;
                ft = h2;
            }
            else
            {
                ft->next = h2;
                ft = ft->next;
            }
            h2 = h2->next;
        }
    }

    if (h1 != NULL)
    {
        if (fh == NULL && ft == NULL)
        {
            fh = h1;
            ft = h1;
        }
        else
        {
            ft->next = h1;
        }
    }

    if (h2 != NULL)
    {
        if (fh == NULL && ft == NULL)
        {
            fh = h2;
            ft = h2;
        }
        else
        {
            ft->next = h2;
        }
    }

    return fh;
}

int main()
{
    cout << "Enter first LL" << endl;
    Node *head1 = takeInput();
    print(head1);

    cout << "Enter second LL" << endl;
    Node *head2 = takeInput();
    print(head2);

    head1 = mergeTwoSortedLL(head1, head2);
    print(head1);

    return 0;
}