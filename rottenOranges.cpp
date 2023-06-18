#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Day 32 Rotten Oranges

int orangesRotting(vector<vector<int>> &arr)
{
    int time = 0;
    int n = arr.size();
    int m = arr[0].size();
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 2)
                q.push({{i, j}, 0});
        }
    }

    pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (q.size() != 0)
    {
        auto front = q.front();
        q.pop();

        for (int it = 0; it < 4; it++)
        {
            int newI = front.first.first + dir[it].first;
            int newJ = front.first.second + dir[it].second;

            if (newI < 0 || newI >= n || newJ < 0 || newJ >= m || arr[newI][newJ] != 1)
                continue;

            arr[newI][newJ] = 2;

            q.push({{newI, newJ}, front.second + 1});
            time = max(time, front.second + 1);
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 1)
                return -1;

    return time;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    int maxTime = orangesRotting(arr);
    if (maxTime != -1)
        cout << "Time to rotting all oranges = " << maxTime << endl;
    else
        cout << "Rotting all oranges is not possible" << endl;

    return 0;
}