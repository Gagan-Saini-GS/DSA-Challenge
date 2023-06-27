#include <iostream>
#include <queue>
using namespace std;

// Day 47 Construct Binary Tree from Preorder and Inorder Traversal

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

// TC O(N)
// SC O(logN) recusion

TreeNode<int> *treeBuild(vector<int> &pre, int ps, int pe, vector<int> &in, int is, int ie)
{
    if (ps > pe || is > ie)
        return NULL;

    int rootData = pre[ps];
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int rootIndex = -1;
    for (int i = is; i <= ie; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int lIS = is;
    int lIE = rootIndex - 1;
    int lPS = ps + 1;
    int lPE = lIE - lIS + lPS;

    int rIS = rootIndex + 1;
    int rIE = ie;
    int rPS = lPE + 1;
    int rPE = pe;

    root->left = treeBuild(pre, lPS, lPE, in, lIS, lIE);
    root->right = treeBuild(pre, rPS, rPE, in, rIS, rIE);

    return root;
}

TreeNode<int> *buildTree(vector<int> &pre, vector<int> &in)
{
    int n = pre.size();
    return treeBuild(pre, 0, n - 1, in, 0, n - 1);
}

int main()
{
    int n;
    cout << "Enter number of nodes = ";
    cin >> n;

    vector<int> pre(n);
    vector<int> in(n);

    cout << "Enter Preorder: ";
    for (int i = 0; i < n; i++)
        cin >> pre[i];

    cout << "Enter Inorder: ";
    for (int i = 0; i < n; i++)
        cin >> in[i];

    TreeNode<int> *root = buildTree(pre, in);
    printTreeLevelWise(root);

    return 0;
}