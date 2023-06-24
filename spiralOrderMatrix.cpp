#include <iostream>
#include <vector>
using namespace std;

// Day 42 Spiral Matrix

// TC O(N*M)
// SC O(1) ans is not counted because I have to return it.
vector<int> spiralOrder(vector<vector<int>> &arr)
{
    vector<int> ans;

    int r = arr.size();
    int c = arr[0].size();

    int top = 0, down = r - 1;
    int left = 0, right = c - 1;

    int dir = 0;

    while (top <= down && left <= right)
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(arr[top][i]);
            }
            top++;
        }
        else if (dir == 1)
        {
            for (int i = top; i <= down; i++)
            {
                ans.push_back(arr[i][right]);
            }
            right--;
        }
        else if (dir == 2)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(arr[down][i]);
            }
            down--;
        }
        else if (dir == 3)
        {
            for (int i = down; i >= top; i--)
            {
                ans.push_back(arr[i][left]);
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }

    return ans;
}

int main()
{
    int r, c;
    cin >> r >> c;

    vector<vector<int>> arr(r, vector<int>(c));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];

    vector<int> ans = spiralOrder(arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;

    return 0;
}