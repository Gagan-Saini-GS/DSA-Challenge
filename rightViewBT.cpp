#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data ";
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }

    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();

        int leftData, rightData;
        cout << "Enter left data of " << frontNode->data << " ";
        cin >> leftData;

        if (leftData != -1)
        {
            TreeNode<int> *leftNode = new TreeNode<int>(leftData);
            frontNode->left = leftNode;
            pendingNodes.push(leftNode);
        }

        cout << "Enter right data of " << frontNode->data << " ";
        cin >> rightData;

        if (rightData != -1)
        {
            TreeNode<int> *rightNode = new TreeNode<int>(rightData);
            frontNode->right = rightNode;
            pendingNodes.push(rightNode);
        }
    }

    return root;
}

void printTreeLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();

        cout << frontNode->data << ": ";
        if (frontNode->left != NULL)
        {
            cout << "L" << frontNode->left->data;
            pendingNodes.push(frontNode->left);
        }
        if (frontNode->right != NULL)
        {
            cout << "R" << frontNode->right->data;
            pendingNodes.push(frontNode->right);
        }
        cout << endl;
    }
}

// Day 44 -> Right View of Binary Tree

// Using map as an extra space
// TC O(N)
// SC (N + logN) N for map and logN for recusion.
void rightView(TreeNode<int> *root, int level, map<int, int> &mp, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (mp.count(level) != 1)
    {
        mp[level] = root->data;
        ans.push_back(root->data);
    }

    rightView(root->right, level + 1, mp, ans);
    rightView(root->left, level + 1, mp, ans);
}

// Without Using map
// TC O(N)
// SC O(logN) for recursion.
void rightView2(TreeNode<int> *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);

    rightView2(root->right, level + 1, ans);
    rightView2(root->left, level + 1, ans);
}

vector<int> rightSideView(TreeNode<int> *root)
{
    vector<int> ans;
    // map<int,int> mp;
    // rightView(root,0,mp,ans);

    rightView2(root, 0, ans);

    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    cout << "Right View of Binary Tree is: ";
    vector<int> rightNodes = rightSideView(root);
    for (int i = 0; i < rightNodes.size(); i++)
        cout << rightNodes[i] << " ";

    cout << endl;
    return 0;
}