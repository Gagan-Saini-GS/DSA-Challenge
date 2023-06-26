#include <iostream>
#include <vector>
using namespace std;

// Day 43 Subsets -> Generate all possible subsets from a array.
// Array element are unique to generate unique subsets.

// TC O(2^N)
// SC O(N) recursion go down till n elements.
void generateSubsets(vector<int> &arr, int n, int i, vector<vector<int>> &ans)
{
    if (i >= n)
    {
        vector<int> temp;
        ans.push_back(temp);
        return;
    }

    int curr = arr[i];
    generateSubsets(arr, n, i + 1, ans);

    int len = ans.size();
    for (int j = 0; j < len; j++)
    {
        vector<int> temp = ans[j];
        temp.push_back(curr);

        ans.push_back(temp);
    }
}

vector<vector<int>> subsets(vector<int> &arr)
{
    vector<vector<int>> ans;
    int n = arr.size();

    generateSubsets(arr, n, 0, ans);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> ans = subsets(arr);

    // First subset is [].
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";

        cout << endl;
    }

    return 0;
}