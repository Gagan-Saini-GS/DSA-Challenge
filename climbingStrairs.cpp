#include <iostream>
#include <vector>
using namespace std;

// Day 13
// Climbing Strairs -> Only 1 or 2 steps are allowed at a time.
// And order matters here. means {1,2} and {2,1} are different.

// We should use long long instead of int to get greater answers as well
// Because if we use int then variable get overload for >= 46.

// Recursive Method
// TC O(N)
// SC O(N) for dp + Recursive Space
long long findSteps(long long n, vector<long long> &dp)
{
    if (n <= 0)
        return 0;
    if (n == 1 || n == 2)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = findSteps(n - 1, dp) + findSteps(n - 2, dp);
}

long long climbStairs(long long n)
{
    vector<long long> dp(n + 1, -1);
    return findSteps(n, dp);
}

// Iterative Method
// TC O(N)
// SC O(N)
long long climbStairs2(long long n)
{
    vector<long long> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for (long long i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

// Iterative method space optimization
// TC O(N)
// SC O(1)
long long climbStairs3(long long n)
{
    long long first = 1, second = 1;
    long long ans = 1;

    for (long long i = 2; i <= n; i++)
    {
        ans = first + second;
        long long temp = first;
        first = second;
        second = ans;
    }

    return ans;
}

int main()
{
    long long n;
    cin >> n;

    long long ans = climbStairs(n);
    cout << "Number of ways is = " << ans << endl;

    long long ans2 = climbStairs2(n);
    cout << "Number of ways is = " << ans2 << endl;

    long long ans3 = climbStairs3(n);
    cout << "Number of ways is = " << ans3 << endl;

    return 0;
}