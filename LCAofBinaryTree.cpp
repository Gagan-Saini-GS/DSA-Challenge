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

// Day 37 LCA in Binary Tree

// Same as LCA in BST
TreeNode<int> *lca(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
{
    if (root == NULL)
        return NULL;

    if (root->data == p->data || root->data == q->data)
        return root;

    TreeNode<int> *left = lca(root->left, p, q);
    TreeNode<int> *right = lca(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;
    else if (left != NULL && right == NULL)
        return left;
    else if (left == NULL && right != NULL)
        return right;
    else
        return NULL;
}

TreeNode<int> *lowestCommonAncestor(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
{
    return lca(root, p, q);
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int pData, qData;
    cin >> pData >> qData;

    TreeNode<int> *p = new TreeNode<int>(pData);
    TreeNode<int> *q = new TreeNode<int>(qData);
    TreeNode<int> *ans = lowestCommonAncestor(root, p, q);

    if (ans)
        cout << "LCA is " << ans->data << endl;
    else
        cout << "NULL" << endl;

    return 0;
}