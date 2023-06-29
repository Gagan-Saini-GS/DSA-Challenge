#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Day 51 -> Task Schedular

// TC O(N)
// SC O(1)
int leastInterval(vector<char> &arr, int k)
{
    int n = arr.size();

    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++)
        freq[arr[i] - 'A']++;

    // Constant Time because size of freq is fixed 26.
    sort(freq.begin(), freq.end());

    int idle = (freq[25] - 1) * k;

    for (int i = 24; i >= 0; i--)
        idle -= min(freq[25] - 1, freq[i]);

    // Because don't want to idle negative
    // idle becomes negative then we don't need it.
    idle = max(0, idle);

    return n + idle;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<char> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int totalTime = leastInterval(arr, k);
    cout << totalTime << endl;

    return 0;
}