#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Day 56 Word Ladder

// TC O(N*M*logN)
// SC O(N) + O(N)
int ladderLength1(string start, string end, vector<string> &arr)
{
    // bfs
    int n = arr.size();

    queue<pair<string, int>> q;
    q.push({start, 1});

    unordered_map<string, bool> mp;
    unordered_map<string, bool> visited;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = true;
    }

    while (q.size() != 0)
    {
        pair<string, int> front = q.front();
        int prevLen = front.second;
        q.pop();

        int size = front.first.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                string word = front.first;
                word[i] = j + 'a';

                if (mp.find(word) != mp.end() && visited.find(word) == mp.end())
                {
                    if (word == end)
                        return prevLen + 1;

                    q.push({word, prevLen + 1});
                    visited[word] = true;
                }
            }
        }
    }

    return 0;
}

// TC O(N*M*logN)
// SC O(N) for set

// N => Number of words
// M => Length of particular word
// logN => logN due to set it can be O(1) as well depends on set

int ladderLength2(string start, string end, vector<string> &arr)
{
    queue<pair<string, int>> q;
    q.push({start, 1});

    unordered_set<string> st(arr.begin(), arr.end());
    st.erase(start); // marking start as visited;

    while (q.size() != 0)
    {
        string word = q.front().first;
        int count = q.front().second;

        q.pop();

        if (word == end)
            return count;

        int m = word.size();
        for (int i = 0; i < m; i++)
        {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                if (st.find(word) != st.end())
                {
                    st.erase(word); // marking as visited;
                    q.push({word, count + 1});
                }
            }

            word[i] = original;
        }
    }

    return 0;
}

int main()
{

    string start, end;
    cin >> start >> end;

    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans1 = ladderLength1(start, end, arr);
    cout << ans1 << endl;

    int ans2 = ladderLength2(start, end, arr);
    cout << ans2 << endl;

    return 0;
}