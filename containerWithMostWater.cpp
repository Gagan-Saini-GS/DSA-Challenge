#include <iostream>
#include <vector>
using namespace std;

// Day 48 Container with Most Water

// TC O(N)
// SC O(1)
int maxArea(vector<int> &arr)
{
    // For Fast I/O
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    int ans = 0;
    int n = arr.size();

    int l = 0, h = n - 1;

    while (l < h)
    {
        int area = min(arr[l], arr[h]) * (h - l);
        ans = max(ans, area);

        // if(arr[l] < arr[h])
        //     l++;
        // else
        //     h--;
        arr[l] < arr[h] ? l++ : h--;
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

    int maximumArea = maxArea(arr);
    cout << "Maximum water area = " << maximumArea << endl;

    return 0;
}