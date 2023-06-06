#include <iostream>
#include <vector>
using namespace std;

// Day 7
// TC O(N*M)
// SC O(N*M) for visited matrix

void dfs(vector<vector<int>> &arr, int n, int m, int i, int j, int color, vector<vector<bool>> &visited, vector<vector<int>> &ans)
{
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j])
        return;

    visited[i][j] = true;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    for (int k = 0; k < 4; k++)
    {
        int newI = i + dir[k].first;
        int newJ = j + dir[k].second;

        if (newI < 0 || newI >= n || newJ < 0 || newJ >= m || visited[newI][newJ])
            continue;
        if (arr[newI][newJ] != arr[i][j])
            continue;

        ans[i][j] = color;
        ans[newI][newJ] = color;
        dfs(arr, n, m, newI, newJ, color, visited, ans);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &arr, int sr, int sc, int color)
{
    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans[i][j] = arr[i][j];

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    ans[sr][sc] = color;
    dfs(arr, n, m, sr, sc, color, visited, ans);

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int sr, sc, color;
    cin >> sr >> sc >> color;

    vector<vector<int>> ans = floodFill(arr, sr, sc, color);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " ";

        cout << endl;
    }

    return 0;
}