#include <iostream>
#include <vector>
#include <stack>
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

// Day 53 Kth Smallest Element in a BST

// TC O(N)
// SC O(N) for inorder array + O(logN) for resursion
void getInorder(TreeNode<int> *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    getInorder(root->left, inorder);
    inorder.push_back(root->data);
    getInorder(root->right, inorder);
}

// Iterative way without using inorder
// TC O(N)
// SC O(N)
int getKthSmallest(TreeNode<int> *root, int k)
{
    stack<TreeNode<int> *> st;

    while (root != NULL || st.size() != 0)
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();

        k--;
        if (k == 0)
            return root->data;

        root = root->right;
    }

    return -1;
}

int kthSmallest(TreeNode<int> *root, int k)
{
    // Method 1
    // vector<int> inorder;
    // getInorder(root, inorder);
    // return inorder[k - 1];

    // Method 2
    return getKthSmallest(root, k);
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int k;
    cout << "Enter k = ";
    cin >> k;

    printTreeLevelWise(root);

    int ans = kthSmallest(root, k);
    cout << "Kth smallest element is = " << ans << endl;

    return 0;
}