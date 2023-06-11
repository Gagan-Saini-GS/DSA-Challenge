#include <iostream>
using namespace std;

// Day 17 Middle of Linked List

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

int length(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    return len;
}

// TC O(N) + O(N) (for finding length and one while loop)
// SC O(1)
Node *middleNode(Node *head)
{
    int len = length(head);
    int count = len / 2;

    Node *temp = head;
    while (temp != NULL && count > 0)
    {
        temp = temp->next;
        count--;
    }

    return temp;
}

// TC O(N)
// SC O(1)
Node *middleNode2(Node *head)
{
    // slow fast pointer
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == NULL)
        return slow;

    return slow->next;
}

int main()
{
    Node *head = takeInput();
    print(head);

    Node *midNode = middleNode(head);
    cout << "Middle Node of LL is = " << midNode->data << endl;

    Node *midNode2 = middleNode2(head);
    cout << "Middle Node of LL is = " << midNode2->data << endl;

    return 0;
}