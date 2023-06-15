#include <iostream>
#include <vector>
using namespace std;

// Day 25 Course Schedule

bool DFS(vector<int> adj[], int n, int sv, vector<bool> &visited, vector<bool> &dfsVisited)
{
    visited[sv] = true;
    dfsVisited[sv] = true;
    vector<int> temp = adj[sv];

    for (int i = 0; i < temp.size(); i++)
    {
        if (visited[temp[i]] == true && dfsVisited[temp[i]] == true)
            return true;
        else if (!visited[temp[i]])
        {
            if (DFS(adj, n, temp[i], visited, dfsVisited))
                return true;
        }
    }

    dfsVisited[sv] = false;
    return false;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int n, vector<int> adj[])
{
    vector<bool> visited(n, false);
    vector<bool> dfsVisited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (DFS(adj, n, i, visited, dfsVisited))
                return true;
        }
    }

    return false;
}

bool canFinish(int n, vector<vector<int>> &arr)
{
    // If graph has a cycle then false otherwise true;
    int m = arr.size();
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
        adj[arr[i][0]].push_back(arr[i][1]);

    if (isCyclic(n, adj))
        return false;

    return true;
}

int main()
{
    int n;
    cout << "Enter of nodes ";
    cin >> n;

    int m;
    cout << "Length of arr ";
    cin >> m;

    vector<vector<int>> arr(m, vector<int>(2));

    for (int i = 0; i < m; i++)
        cin >> arr[i][0] >> arr[i][1];

    if (canFinish(n, arr))
        cout << "All course can be completed!" << endl;

    else
        cout << "All course can not be completed!" << endl;

    return 0;
}