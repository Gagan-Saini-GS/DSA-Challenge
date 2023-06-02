// DAY-1

#include <bits/stdc++.h>
using namespace std;

// arr is not sorted
// TC O(N*N)
vector<int> twoSum(vector<int> &arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                return {i, j};
            }
        }
    }

    return {-1};
}

// arr is not sorted
// TC O(N) for sorting.
// SC O(N) for map.

vector<int> twoSum(vector<int> &arr, int n, int k)
{
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        if (mp.count(arr[i]) == 1)
        {
            return {i, mp[arr[i]]};
        }
        else
        {
            mp[k - arr[i]] = i;
        }
    }

    return {-1};
}

// arr is sorted
// TC O(logN)
vector<int> twoSum3(vector<int> &arr, int n, int k)
{
    vector<int> ans;

    int l = 0, h = n - 1;
    while (l <= h)
    {
        int sum = arr[l] + arr[h];
        if (sum == k)
        {
            return {l, h};
        }
        else if (sum > k)
        {
            h--;
        }
        else if (sum < k)
        {
            l++;
        }
    }

    return {-1};
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // vector<int> ans = twoSum(arr, n, k);
    vector<int> ans = twoSum3(arr, n, k);
    cout << "[" << ans[0] << "," << ans[1] << "]" << endl;

    return 0;
}