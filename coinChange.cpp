#include <iostream>
#include <vector>
using namespace std;

// Day 27 Coin Change -> Return the number of coins

// Recursive Method
// TC O(N*amount)
// SC O(Amount) + Recusive Space

int findNumberOfCoins(vector<int> &arr, int n, int amount, vector<int> &dp)
{
    if (dp[amount] != -1)
        return dp[amount];

    int coins = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= amount)
        {
            int temp = findNumberOfCoins(arr, n, amount - arr[i], dp);

            if (temp != INT32_MAX && temp + 1 < coins)
                coins = temp + 1;
        }
    }

    return dp[amount] = coins;
}

int coinChange(vector<int> &arr, int amount)
{
    int n = arr.size();
    vector<int> dp(amount + 1, -1);

    // Base case
    dp[0] = 0;

    int ans = findNumberOfCoins(arr, n, amount, dp);
    if (ans == INT32_MAX)
        return -1;

    return ans;
}

// Iterative Method
// TC O(N*amount)
// SC O(amount)

int coinChange2(vector<int> &arr, int amount)
{
    int n = arr.size();
    vector<long long> dp(amount + 1, INT32_MAX);

    // base case;
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] <= i)
            {
                int temp = dp[i - arr[j]];
                if (temp != INT32_MAX && temp + 1 < dp[i])
                    dp[i] = temp + 1;
            }
        }
    }
    if (dp[amount] == INT32_MAX)
        return -1;

    return dp[amount];
}

int main()
{
    int n, amount;
    cin >> n >> amount;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = coinChange(arr, amount);
    cout << ans << endl;

    int ans2 = coinChange2(arr, amount);
    if (ans2 == -1)
        cout << "Changing is not possible" << endl;
    else
        cout << "Number of coins = " << ans2 << endl;

    return 0;
}