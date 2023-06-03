#include <iostream>
#include <vector>
using namespace std;

// TC O(N*N) and SC O(1)
int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    int mini = INT32_MAX;
    int maxi = INT32_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            mini = min(mini, arr[j]);
        }
        maxi = max(maxi, arr[i] - mini);
        mini = INT32_MAX;
    }

    if (maxi < 0)
        return 0;

    return maxi;
}

// Optimal Solution
// TC O(N+N+N) = O(N) and SC O(N+N) = O(N)
int maxProfit2(vector<int> &arr)
{
    int n = arr.size();
    int ans = INT32_MIN;

    vector<int> mini(n, INT32_MAX);
    vector<int> maxi(n, INT32_MIN);

    mini[0] = arr[0];
    for (int i = 1; i < n; i++)
        mini[i] = min(mini[i - 1], arr[i]);

    maxi[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        maxi[i] = max(maxi[i + 1], arr[i]);

    for (int i = 0; i < n; i++)
        ans = max(ans, maxi[i] - mini[i]);

    if (ans < 0)
        return 0;

    return ans;

    // Space Optimization
    // Not working because  maxElem is from last.
    // int minElem = INT32_MAX;
    // int maxElem = INT32_MIN;

    // for (int i = 0; i < n; i++)
    // {
    //     minElem = min(minElem, arr[i]);
    //     maxElem = max(maxElem, arr[n - 1 - i]);
    //     cout << minElem << " " << maxElem << endl;

    //     ans = max(ans, maxElem - minElem);
    // }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = maxProfit2(arr);
    cout << ans << endl;

    return 0;
}