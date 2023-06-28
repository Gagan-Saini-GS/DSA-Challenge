#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Day 50 Minimum Height Tree

// TC O(N)
// SC O(N + M)

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1)
    {
        return {0};
    }

    vector<int> ans;
    vector<int> adj[n];
    vector<int> degree(n, 0);
    queue<int> q;
    int m = edges.size();

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
        {
            q.push(i);
        }
    }

    while (n > 2)
    {
        int size = q.size();
        n -= size;

        for (int i = 0; i < size; i++)
        {
            int front = q.front();
            q.pop();

            for (auto it : adj[front])
            {
                degree[it]--;
                if (degree[it] == 1)
                    q.push(it);
            }
        }
    }

    while (q.size() > 0)
    {
        ans.push_back(q.front());
        q.pop();
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0];
        cin >> edges[i][1];
    }

    vector<int> ans = findMinHeightTrees(n, edges);
    cout << "Answer nodes are : ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;

    return 0;
}