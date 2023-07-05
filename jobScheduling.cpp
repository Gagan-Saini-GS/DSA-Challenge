#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Day 58 Maximum Profit in Job Scheduling

// TC O(N) for loop + O(NlogN) sorting + O(N) recursion == O(NlogN)
// Sc O(3*N) for arr + O(N) for dp + recursive space == O(N)

int maxProfit(vector<vector<int>> &arr, int n, int s, int e, vector<int> &dp)
{
    if (s >= n)
        return 0;

    if (arr[s][0] < e)
        return maxProfit(arr, n, s + 1, e, dp);

    if (dp[s] != -1)
        return dp[s];

    return dp[s] = max(maxProfit(arr, n, s + 1, e, dp), arr[s][2] + maxProfit(arr, n, s + 1, arr[s][1], dp));
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    vector<vector<int>> arr;
    int n = startTime.size();

    for (int i = 0; i < n; i++)
        arr.push_back({startTime[i], endTime[i], profit[i]});

    sort(arr.begin(), arr.end());
    int ans = 0;
    vector<int> dp(n, -1);

    return maxProfit(arr, n, 0, 0, dp);
}

int main()
{
    int n;
    cin >> n;

    vector<int> startTime(n), endTime(n), profit(n);

    for (int i = 0; i < n; i++)
        cin >> startTime[i];

    for (int i = 0; i < n; i++)
        cin >> endTime[i];

    for (int i = 0; i < n; i++)
        cin >> profit[i];

    int ans = jobScheduling(startTime, endTime, profit);
    cout << "Maximum profit from job scheduling is = " << ans << endl;

    return 0;
}