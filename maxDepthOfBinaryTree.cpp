#include <iostream>
#include <queue>
using namespace std;

// Day 18 Maximum Depth of Binary Tree

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

// TC O(N)
// SC O(Height of Tree) for recursive space
int findMaxDepth(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int left = findMaxDepth(root->left);
    int right = findMaxDepth(root->right);

    return 1 + max(left, right);
}

// TC O(N)
// SC O(N) for queue
int findMaxDepthIterative(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 1});

    int ans = INT32_MIN;
    while (q.size() != 0)
    {
        auto front = q.front();
        q.pop();

        ans = max(ans, front.second);

        if (front.first->left != NULL)
            q.push({front.first->left, front.second + 1});

        if (front.first->right != NULL)
            q.push({front.first->right, front.second + 1});
    }

    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);

    int ans = findMaxDepth(root);
    cout << "Maximum Depth of the binary tree is = " << ans << endl;

    int ans2 = findMaxDepthIterative(root);
    cout << "Maximum Depth of the binary tree is = " << ans << endl;

    return 0;
}