#include <iostream>
#include <queue>
using namespace std;

// Day 16 Diameter of Binary Tree

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

// The time complexity of this is O(n)
// Where n is number of Nodes

pair<int, int> heightDiameter(TreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> ans;
        ans.first = 0;
        ans.second = 0;

        return ans;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    pair<int, int> ans;
    ans.first = height;
    ans.second = diameter;

    return ans;
}

// TC O(N)
// SC O(logN) for recursion

int findDiameter(TreeNode<int> *root, int &ans)
{
    if (root == NULL)
        return -1;
    if (root->left == NULL && root->right == NULL)
        return 0;

    int left = 1 + findDiameter(root->left, ans);
    int right = 1 + findDiameter(root->right, ans);

    ans = max(ans, left + right);
    return max(left, right);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int ans = 0;
    int temp = findDiameter(root, ans);

    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);

    pair<int, int> ans = heightDiameter(root);
    cout << "Height of Binary Tree = " << ans.first << endl;
    cout << "Diameter of Binary Tree = " << ans.second << endl;

    int diameter = diameterOfBinaryTree(root);
    cout << "Diameter of Binary Tree = " << diameter << endl;

    delete root;
    return 0;
}