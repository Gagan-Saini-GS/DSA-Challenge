#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Day 36 Merge Intervals

// Leaning static functions use too much space
// Check the space in first submission with static function

bool comp(const vector<int> &a, const vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];

    return a[0] < b[0];
}

// TC O(NlogN) in sorting + O(N)
// SC O(1) no extra space (ans is not counted we have to return this)

vector<vector<int>> merge(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), comp);

    vector<vector<int>> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i][0] <= ans.back()[1])
        {
            // merge these intervals
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
        else
        {
            // new interval
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1];

    vector<vector<int>> ans = merge(arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i][0] << " " << ans[i][1] << endl;

    return 0;
}