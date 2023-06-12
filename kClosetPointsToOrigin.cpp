#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// Day 19 K Closet Points To Origin

bool comp(pair<int, double> a, pair<int, double> b)
{
    return a.second < b.second;
}

// TC O(N) + O(NlogN) => for loop and sorting
// SC O(N) for dist array

vector<vector<int>> kClosest(vector<vector<int>> &arr, int k)
{
    vector<vector<int>> ans(k);
    vector<pair<int, double>> dist;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        double x = arr[i][0];
        double y = arr[i][1];

        double distance = sqrt(x * x + y * y);
        dist.push_back({i, distance});
    }

    sort(dist.begin(), dist.end(), comp);

    for (int i = 0; i < k; i++)
    {
        int index = dist[i].first;
        ans[i] = arr[index];
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    vector<vector<int>> ans = kClosest(arr, k);
    for (int i = 0; i < k; i++)
        cout << "[" << ans[i][0] << " " << ans[i][1] << "]" << endl;

    return 0;
}