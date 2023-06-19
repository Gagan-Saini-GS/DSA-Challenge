#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Day 34 Combination Sum

// Not the part of actual question
// To get all possible ways (Not unique) [1,2] and [2,1] is different
void findSum(vector<int> &arr, int k, vector<int> &temp, vector<vector<int>> &ans)
{
    // Base case is k < 0 and this is handeled inside for loop if
    if (k == 0)
    {
        ans.push_back(temp);
        return;
    }

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            temp.push_back(arr[i]);
            findSum(arr, k - arr[i], temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &arr, int k)
{
    vector<vector<int>> ans;
    vector<int> temp;

    findSum(arr, k, temp, ans);

    return ans;
}

// To find Unique combination
void findSum(vector<int> &arr, int start, int k, vector<int> &temp, vector<vector<int>> &ans)
{
    // Base case is k < 0 and this is handeled inside for loop if
    if (k == 0)
    {
        ans.push_back(temp);
        return;
    }

    int n = arr.size();
    if (start >= n)
        return;

    for (int i = start; i < n; i++)
    {
        if (arr[i] <= k)
        {
            temp.push_back(arr[i]);
            findSum(arr, start, k - arr[i], temp, ans);
            start++;

            // Backtrack
            temp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;

    findSum(arr, 0, k, temp, ans);

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // cout << "================================================" << endl;
    // vector<vector<int>> ans = combinationSum(arr, k);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //         cout << ans[i][j] << " ";

    //     cout << endl;
    // }
    // cout << "================================================" << endl;

    vector<vector<int>> ans2 = combinationSum2(arr, k);

    for (int i = 0; i < ans2.size(); i++)
    {
        for (int j = 0; j < ans2[i].size(); j++)
            cout << ans2[i][j] << " ";

        cout << endl;
    }

    return 0;
}