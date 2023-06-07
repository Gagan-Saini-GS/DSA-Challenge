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

// To create Cycle (Not the part of actual question)
Node *createCycle(Node *head, int pos)
{
    int count = 0;

    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    Node *positionNode = head;

    while (count != pos && positionNode != NULL)
    {
        count++;
        positionNode = positionNode->next;
    }

    tail->next = positionNode;
    return head;
}

// Day 10 check Linked List has a loop or not.

bool hasCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return false;

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
            return true;

        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}

// Not the part of actual question but important
// Removing loop from LL.
Node *removeCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
            break;

        slow = slow->next;
        fast = fast->next->next;
    }

    slow = head;
    while (fast->next != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
    return head;
}

int main()
{
    Node *head = takeInput();
    int pos;
    cin >> pos;
    head = createCycle(head, pos);
    // print(head);

    if (hasCycle(head))
        cout << "LL has a cycle." << endl;
    else
        cout << "LL does not have a cycle." << endl;

    head = removeCycle(head);
    print(head);

    return 0;
}