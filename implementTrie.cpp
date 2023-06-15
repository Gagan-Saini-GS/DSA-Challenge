#include <iostream>
using namespace std;

// Day 26 Implement Trie (Prefix Tree)

class Node
{
public:
    Node *links[26];
    bool flag;

    Node()
    {
        flag = false;
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }

    bool containsKey(char ch)
    {
        if (links[ch - 'a'] != NULL)
            return true;
        return false;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *newNode)
    {
        links[ch - 'a'] = newNode;
    }

    void setEnd()
    {
        flag = true;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    // TC O(length of word)
    void insert(string word)
    {
        int n = word.size();
        Node *temp = root;

        for (int i = 0; i < n; i++)
        {
            if (temp->containsKey(word[i]) == false)
                temp->put(word[i], new Node());

            // Moving to next reference trie
            temp = temp->get(word[i]);
        }

        temp->setEnd();
    }

    // TC O(length of word)
    bool search(string word)
    {
        int n = word.size();
        Node *temp = root;

        for (int i = 0; i < n; i++)
        {
            if (temp->containsKey(word[i]) == true)
                temp = temp->get(word[i]);
            else
                return false;
        }

        if (temp != NULL && temp->flag)
            return true;

        return false;
    }

    // TC O(length of prefix)
    bool startsWith(string prefix)
    {
        int n = prefix.size();
        Node *temp = root;

        for (int i = 0; i < n; i++)
        {
            if (temp->containsKey(prefix[i]) == true)
                temp = temp->get(prefix[i]);
            else
                return false;
        }

        if (temp != NULL)
            return true;

        return false;
    }
};

int main()
{

    Trie *t = new Trie();
    t->insert("gagan");
    t->insert("saini");

    if (t->search("gagan"))
        cout << "Word Exist" << endl;
    else
        cout << "Word Does Not Exist" << endl;

    if (t->startsWith("san"))
        cout << "Word Exist starts with = sai" << endl;
    else
        cout << "Word Does Not Exist that starts with = sai" << endl;

    return 0;
}