#include <iostream>
using namespace std;

// Not the part of code this function is given by leetcode
// to check a version is bad or not.
// Any version >= to bad version is also bad.

int bad = -1;
bool isBadVersion(int b)
{
    return b >= bad;
}

// Day 11 First Bad Version
// TC O(logN)
// SC O(1)
int firstBadVersion(int n)
{
    int l = 1, h = n;
    int ans = -1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (isBadVersion(mid))
        {
            ans = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }

    return ans;

    // Bruth Force -> TLE
    // TC O(N)
    // for(int i=1;i<=n;i++){
    //     if(isBadVersion(i)){
    //         return i;
    //     }
    // }
    // return -1;
}

int main()
{

    int n, b;
    cin >> n >> b;

    bad = b;
    int ans = firstBadVersion(n);
    cout << "First bad version is " << ans << endl;

    return 0;
}