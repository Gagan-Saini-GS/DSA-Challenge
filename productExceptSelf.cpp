#include <iostream>
#include <vector>
using namespace std;

// Day 28 Product of Array Except Self

// TC O(N+N+N) = O(N)
// SC O(N) for left + O(N) for right == O(N)
vector<int> productExceptSelf(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return {0};

    vector<int> ans(n);
    vector<int> left(n);
    vector<int> right(n);

    left[0] = 1;
    right[n - 1] = 1;

    for (int i = 1; i < n; i++)
        left[i] = left[i - 1] * arr[i - 1];

    for (int i = n - 2; i >= 0; i--)
        right[i] = right[i + 1] * arr[i + 1];

    for (int i = 0; i < n; i++)
        ans[i] = left[i] * right[i];

    return ans;
}

// Space Optimization
// TC O(N)
// SC O(1) Extra space -> Don't include ans because we have return it.
vector<int> productExceptSelf2(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1)
        return {0};

    vector<int> ans(n);
    int temp = 1;

    for (int i = 0; i < n; i++)
    {
        ans[i] = temp;
        temp *= arr[i];
    }

    temp = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= temp;
        temp *= arr[i];
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans = productExceptSelf(arr);
    vector<int> ans2 = productExceptSelf2(arr);

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << ans2[i] << " ";
    cout << endl;

    return 0;
}