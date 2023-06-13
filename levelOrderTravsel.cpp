#include <iostream>
#include <queue>
using namespace std;

// Day 22 Level Order Travsel of Binary Tree
// Each level nodes should be in different vector

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

vector<vector<int>> levelOrder(TreeNode<int> *root)
{
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    queue<TreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        vector<int> temp;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode<int> *front = q.front();
            temp.push_back(front->data);
            q.pop();

            if (front->left != NULL)
                q.push(front->left);

            if (front->right != NULL)
                q.push(front->right);
        }

        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);

    vector<vector<int>> ans = levelOrder(root);
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        int m = ans[i].size();
        cout << "Level " << i + 1 << ": ";
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " ";

        cout << endl;
    }

    return 0;
}