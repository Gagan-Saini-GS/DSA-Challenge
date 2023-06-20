#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Day 35 Permutations

// This is question
// Works only when all the array element are unique

// TC O(N! * N)
// SC O(N)

void findPermutations(vector<int> &arr, int l, int h, vector<vector<int>> &ans)
{
    if (l == h)
    {
        ans.push_back(arr);
        return;
    }

    // From l to h range we have to do this
    for (int i = l; i <= h; i++)
    {
        swap(arr[l], arr[i]);
        findPermutations(arr, l + 1, h, ans);

        // Backtracking
        swap(arr[l], arr[i]);
    }
}

vector<vector<int>> permute(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;

    findPermutations(arr, 0, n - 1, ans);

    return ans;
}

// Extra question
// When the array elements are not unique and have to return unique permutations

// TC O(N! * N)
// SC O(N! * N)

void findPermutations(vector<int> &arr, int n, vector<int> &temp, vector<bool> &visited, vector<vector<int>> &ans)
{

    if (temp.size() == n)
        ans.push_back(temp);

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        if (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1])
            continue;

        temp.push_back(arr[i]);
        visited[i] = true;

        findPermutations(arr, n, temp, visited, ans);

        // Backtracking
        temp.pop_back();
        visited[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int n = arr.size();
    vector<int> temp;
    vector<bool> visited(n, false);

    findPermutations(arr, n, temp, visited, ans);

    return ans;
}

void printAns(vector<vector<int>> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> ans = permute(arr);
    printAns(ans);

    cout << "================================" << endl;

    vector<vector<int>> ans2 = permuteUnique(arr);
    printAns(ans2);

    return 0;
}