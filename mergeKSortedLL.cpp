#include <iostream>
#include <queue>
using namespace std;

// Day 59 Merge K Sorted Linked List

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

ListNode *takeInput()
{
    int data;
    cin >> data;

    ListNode *head = NULL;
    ListNode *temp = head;
    while (data != -1)
    {
        ListNode *newListNode = new ListNode(data);
        if (head == NULL)
        {
            head = newListNode;
            temp = head;
        }
        else
        {
            temp->next = newListNode;
            temp = temp->next;
        }
        cin >> data;
    }

    return head;
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int length(ListNode *head)
{
    ListNode *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

ListNode *mergeKLists(vector<ListNode *> &arr)
{
    ListNode *FH = nullptr;
    ListNode *FT = nullptr;
    int n = arr.size();

    int totalLen = 0;
    for (int i = 0; i < n; i++)
        totalLen += length(arr[i]);

    for (int i = 0; i < totalLen; i++)
    {
        ListNode *minNode = nullptr;
        int minNodeIndex;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] != nullptr)
            {
                if (minNode == nullptr)
                {
                    minNode = arr[j];
                    minNodeIndex = j;
                }
                else if (arr[j]->data < minNode->data)
                {
                    minNode = arr[j];
                    minNodeIndex = j;
                }
            }
        }

        if (FH == nullptr && FT == nullptr)
        {
            FH = minNode;
            FT = minNode;
        }
        else if (FT != nullptr)
        {
            FT->next = minNode;
            FT = FT->next;
        }

        minNode = minNode->next;
        arr[minNodeIndex] = minNode;
    }

    return FH;
}

// Using Priority Queue
ListNode *mergeKLists2(vector<ListNode *> &arr)
{
    ListNode *head = new ListNode(0);
    ListNode *curr = head;

    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;

    for (auto &list : arr)
    {
        if (list != nullptr)
            pq.push({list->data, list});
    }

    while (pq.size() != 0)
    {
        ListNode *node = new ListNode(pq.top().first);
        ListNode *next = pq.top().second->next;

        if (next != nullptr)
            pq.push({next->data, next});

        pq.pop();
        curr->next = node;
        curr = curr->next;
    }

    return head->next;
}

int main()
{
    int n;
    cin >> n;

    vector<ListNode *> arr(n);
    for (int i = 0; i < n; i++)
    {
        ListNode *head = takeInput();
        arr[i] = head;
    }

    // ListNode *ans1 = mergeKLists(arr);
    // print(ans1);

    ListNode *ans2 = mergeKLists2(arr);
    print(ans2);

    return 0;
}