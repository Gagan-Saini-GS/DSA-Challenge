#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

public:
    int *parent;
    int *size;

    // Only use one rank or size they are
    // alternative to each other

    DisjointSet(int n)
    {
        parent = new int[n + 1];
        size = new int[n + 1];

        for (int i = 0; i <= n; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    // TC O(4alpha) ~= constant
    int findParent(int u)
    {
        if (u == parent[u])
            return u;

        // This is path compression to get parent in constant time
        // for next time
        return parent[u] = findParent(parent[u]);
    }

    // TC O(4alpha) ~= constant
    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

// Day 39 Account Merge
// A question with Dijoint Set

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &arr)
    {
        int n = arr.size();
        DisjointSet dj(n);
        sort(arr.begin(), arr.end());
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < arr[i].size(); j++)
            {
                string mail = arr[i][j];
                if (mp.find(mail) == mp.end())
                    mp[mail] = i;
                else
                    dj.unionBySize(i, mp[mail]);
            }
        }

        vector<string> mergedMails[n];

        for (auto it : mp)
        {
            string mail = it.first;
            int parent = dj.findParent(it.second);
            mergedMails[parent].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++)
        {
            if (mergedMails[i].size() == 0)
                continue;

            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(arr[i][0]); // pushing the name;

            for (auto it : mergedMails[i])
                temp.push_back(it);

            ans.push_back(temp);
        }

        return ans;
    }
};

// {
//     {"John", "j1@com", "j2@com", "j3@com"},
//         {"John", "j4@com"},
//         {"Raj", "r1@com", "r2@com"},
//         {"John", "j1@com", "j5@com"},
//         {"Raj", "r2@com", "r3@com"},
//     {
//         "Mary", "m1@com"
//     }
// }

// {{"Lily", "Lily3@m.co", "Lily4@m.co", "Lily17@m.co"}, {"Lily", "Lily5@m.co", "Lily3@m.co", "Lily23@m.co"}, {"Lily", "Lily0@m.co", "Lily1@m.co", "Lily8@m.co"}, {"Lily", "Lily14@m.co", "Lily23@m.co"}, {"Lily", "Lily4@m.co", "Lily5@m.co", "Lily20@m.co"}, {"Lily", "Lily1@m.co", "Lily2@m.co", "Lily11@m.co"}, {"Lily", "Lily2@m.co", "Lily0@m.co", "Lily14@m.co"}};

// {{"David", "David0@m.co", "David1@m.co"}, {"David", "David3@m.co", "David4@m.co"}, {"David", "David4@m.co", "David5@m.co"}, {"David", "David2@m.co", "David3@m.co"}, {"David", "David1@m.co", "David2@m.co"}}

int main()
{

    vector<vector<string>> accounts = {{"Lily", "Lily3@m.co", "Lily4@m.co", "Lily17@m.co"}, {"Lily", "Lily5@m.co", "Lily3@m.co", "Lily23@m.co"}, {"Lily", "Lily0@m.co", "Lily1@m.co", "Lily8@m.co"}, {"Lily", "Lily14@m.co", "Lily23@m.co"}, {"Lily", "Lily4@m.co", "Lily5@m.co", "Lily20@m.co"}, {"Lily", "Lily1@m.co", "Lily2@m.co", "Lily11@m.co"}, {"Lily", "Lily2@m.co", "Lily0@m.co", "Lily14@m.co"}};

    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);
    for (auto acc : ans)
    {
        cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++)
        {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}