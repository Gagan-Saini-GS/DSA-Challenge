#include <iostream>
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

// Day 30 Validate Binary Search Tree
// TC O(N)
// SC O(logN) or (Height of Tree) due to recursive space

bool checkBST(TreeNode<int> *root, long long int min, long long int max)
{
    if (root == NULL)
        return true;

    if (root->data <= min || root->data >= max)
        return false;

    bool left = checkBST(root->left, min, root->data);
    bool right = checkBST(root->right, root->data, max);

    return left && right;
}

bool validateBST(TreeNode<int> *root)
{
    long long min = INT64_MAX;
    long long max = INT64_MIN;

    return checkBST(root, min, max);
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);

    if (validateBST(root))
        cout << "It is BST" << endl;
    else
        cout << "It is not BST" << endl;
    return 0;
}