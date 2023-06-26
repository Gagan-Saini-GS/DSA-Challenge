#include <iostream>
#include <vector>
using namespace std;

// Day 46 Unique Paths

// TC O(N*M)
// SC O(N*M)

int uniquePaths(int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // dp[n - 1][m - 1] = 0; // Does not need this because everything is already zero

    for (int i = 0; i < n; i++)
        dp[i][m - 1] = 1;

    for (int j = 0; j < m; j++)
        dp[n - 1][j] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
    }

    return dp[0][0];
}

int main()
{
    int n, m;
    cin >> n >> m;

    int ans = uniquePaths(n, m);
    cout << "Unique possible paths is = " << ans << endl;

    return 0;
}