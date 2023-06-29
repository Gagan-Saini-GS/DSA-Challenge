#include <iostream>
#include <unordered_map>
using namespace std;

// Day 52 LRU Cache
// Using Doubly Linked List

class Node
{
public:
    int key, value;
    Node *next;
    Node *prev;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUCache
{
    int cap;
    unordered_map<int, Node *> mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    void addNode(Node *newnode)
    {
        Node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode; // problem
    }

    void deleteNode(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *resNode = mp[key];
            int res = resNode->value;
            mp.erase(key);

            deleteNode(resNode);
            addNode(resNode);

            mp[key] = head->next;
            return res;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            mp.erase(key);

            deleteNode(temp);
        }

        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

int main()
{
    return 0;
}