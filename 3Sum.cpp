#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

// Day 21 3Sum
// Find all triplet whose sum == 0
// And duplicate are not allowed and also i != j != k.

// TC O(NlogN) + O(N*N*N) and SC O(N)
vector<vector<int>> threeSum(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    set<vector<int>> st;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                    st.insert({arr[i], arr[j], arr[k]});
            }
        }
    }

    for (auto it : st)
        ans.push_back(it);

    return ans;
}

// Optimal
// TC O(N*N*logN) (near about)
// SC O(number of unique triplet)

vector<vector<int>> threeSum2(vector<int> &arr)
{
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        unordered_map<int, bool> mp;
        for (int j = i + 1; j < n; j++)
        {
            int sum = -(arr[i] + arr[j]);
            if (mp.count(sum) == 1)
            {
                vector<int> temp = {arr[i], arr[j], sum};
                sort(temp.begin(), temp.end());

                st.insert(temp);
            }

            mp[arr[j]] = true;
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Optimized
// TC O(NlogN) + O(N*N) near about O(N*N).
// SC O(1) no extra space and ans is not counted because we have to return it.
vector<vector<int>> threeSum3(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                // Skiping the duplicates
                while (j < k && arr[j] == arr[j - 1])
                    j++;

                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
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

    // vector<vector<int>> ans = threeSum(arr);
    // vector<vector<int>> ans = threeSum2(arr);
    vector<vector<int>> ans = threeSum3(arr);
    int len = ans.size();

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << ans[i][j] << " ";

        cout << endl;
    }

    return 0;
}