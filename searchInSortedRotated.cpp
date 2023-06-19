#include <iostream>
#include <vector>
using namespace std;

// Day 33 Search Element in sorted rotated array.
// Must be in logN time

// Best Apporach
// TC O(logN)
// SC O(logN) due to recursion
int searchElem(vector<int> &arr, int l, int h, int target)
{
    if (l > h)
        return -1;

    int mid = l + (h - l) / 2;
    if (arr[mid] == target)
        return mid;

    if (arr[l] <= arr[mid])
    {
        if (arr[mid] >= target && arr[l] <= target)
            return searchElem(arr, l, mid - 1, target);
        else
            return searchElem(arr, mid + 1, h, target);
    }
    else
    {
        if (arr[mid] <= target && arr[h] >= target)
            return searchElem(arr, mid + 1, h, target);
        else
            return searchElem(arr, l, mid - 1, target);
    }
}

int search(vector<int> &arr, int target)
{
    int n = arr.size();
    return searchElem(arr, 0, n - 1, target);
}

// TC O(N)
// SC O(1)
int linearSearch(vector<int> &arr, int target)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;

    return -1;
}

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int idx = search(arr, target);
    if (idx == -1)
        cout << "Element not present" << endl;
    else
        cout << "Element present at index = " << idx << endl;

    return 0;
}