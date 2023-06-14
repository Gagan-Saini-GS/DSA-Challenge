#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Day 23 Clone Graph

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// TC O(N)
// SC O(N) + O(N) for recursive in worst case

// DFS
Node *graphClone(Node *node, unordered_map<Node *, Node *> &mp)
{
    if (!node)
        return node;

    // means already visited
    if (mp.find(node) != mp.end())
        return mp[node];

    mp[node] = new Node(node->val);

    for (auto it : node->neighbors)
    {
        Node *temp = graphClone(it, mp);
        mp[node]->neighbors.push_back(temp);
    }

    return mp[node];
}

Node *cloneGraph(Node *node)
{
    unordered_map<Node *, Node *> mp;
    return graphClone(node, mp);
}

int main()
{
    return 0;
}