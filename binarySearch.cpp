#include <iostream>
#include <vector>
using namespace std;

// Day 6
// TC O(logN) and SC O(1)

int search(vector<int> &arr, int k)
{
    int n = arr.size();
    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
            h--;
        else
            l++;
    }

    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = search(arr, k);
    if (ans == -1)
        cout << "Element is not present in array!" << endl;
    else
        cout << "Element is present at index " << ans << endl;

    return 0;
}