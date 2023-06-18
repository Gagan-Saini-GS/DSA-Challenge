#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Day 31 Number of Island

void dfs(vector<vector<char>> &arr, int n, int m, int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || arr[i][j] == '-')
        return;

    if (arr[i][j] == '0')
        return;

    arr[i][j] = '-';

    dfs(arr, n, m, i + 1, j);
    dfs(arr, n, m, i - 1, j);
    dfs(arr, n, m, i, j + 1);
    dfs(arr, n, m, i, j - 1);
}

void bfs(vector<vector<char>> &arr, int n, int m, int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});

    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (q.size() != 0)
    {
        pair<int, int> front = q.front();
        q.pop();

        if (arr[front.first][front.second] == '-')
            continue;

        arr[front.first][front.second] = '-';

        for (int it = 0; it < 4; it++)
        {
            int newI = front.first + dir[it].first;
            int newJ = front.second + dir[it].second;

            if (newI < 0 || newI >= n || newJ < 0 || newJ >= m || arr[newI][newJ] == '0' || arr[newI][newJ] == '-')
                continue;

            q.push({newI, newJ});
        }
    }
}

int numIslands(vector<vector<char>> &arr)
{
    int ans = 0;
    int n = arr.size();
    int m = arr[0].size();

    // Using array itself as visited array for space optimization
    // I can also use extra space O(N*M) for visited array in bfs.

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (arr[i][j] == '1')
    //         {
    //             bfs(arr, n, m, i, j);
    //             ans++;
    //         }
    //     }
    // }

    // In DFS using extra space as visited array gives TLE
    // And I don't know how.

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '1')
            {
                dfs(arr, n, m, i, j);
                ans++;
            }
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int numberOfIslands = numIslands(arr);
    cout << "Number of Islands is = " << numberOfIslands << endl;

    return 0;
}