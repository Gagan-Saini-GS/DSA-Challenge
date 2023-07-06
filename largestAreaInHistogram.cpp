#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Day 60 Largest Rectangle in Histogram

// Bruth Force
// TC O(N*N)
// SC O(1)
int largestRectangleArea(vector<int> &arr)
{
    int n = arr.size();
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        // leftSmaller Index
        int leftIndex = 0, rightIndex = n - 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                leftIndex = j + 1;
                break;
            }
        }

        // rightSmaller Index
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                rightIndex = j - 1;
                break;
            }
        }

        maxArea = max(maxArea, arr[i] * (rightIndex - leftIndex + 1));
    }

    return maxArea;
}

// Optimal
// TC ~ O(N)
// SC ~ O(N) == O(N) + O(N) + O(N)

int largestRectangleArea2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> leftSmall(n);
    vector<int> rightSmall(n);

    stack<int> st; // Store indexes

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (st.empty())
            leftSmall[i] = 0;
        else
            leftSmall[i] = st.top() + 1;

        st.push(i);
    }

    // Clear stack to reuse
    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (st.empty())
            rightSmall[i] = n - 1;
        else
            rightSmall[i] = st.top() - 1;

        st.push(i);
    }

    int maxArea = 0;

    for (int i = 0; i < n; i++)
        maxArea = max(maxArea, (rightSmall[i] - leftSmall[i] + 1) * arr[i]);

    return maxArea;
}

// Most Optimized
// TC O(N)
// SC O(N)

int largestRectangleArea3(vector<int> &arr)
{
    int n = arr.size();
    int maxArea = 0;
    stack<int> st;

    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || arr[st.top()] >= arr[i]))
        {
            int height = arr[st.top()];
            st.pop();

            int width;

            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, width * height);
        }

        st.push(i);
    }

    return maxArea;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = largestRectangleArea(arr);
    cout << ans << endl;

    int ans2 = largestRectangleArea2(arr);
    cout << ans2 << endl;

    int ans3 = largestRectangleArea3(arr);
    cout << ans3 << endl;

    return 0;
}