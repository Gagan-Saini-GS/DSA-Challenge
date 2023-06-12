#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Day 20 Length of Longest Substring without repeating characters

// TC O(N*N)
// SC O(256) + O(N)
// But this can also store the string of longest length in case
// you have to return string as well.

int lengthOfLongestSubstring(string str)
{
    int ans = INT32_MIN;
    bool visited[256] = {false};
    int n = str.size();

    unordered_map<string, int> mp;
    string s = "";

    for (int i = 0; i < n; i++)
    {
        if (!visited[str[i]])
        {
            s += str[i];
            visited[str[i]] = true;
        }
        else
        {
            int len = s.size();
            mp[s] = len;
            int j = 0;

            while (j < len)
            {
                visited[s[j]] = false;
                if (s[j] == str[i])
                {
                    j++;
                    break;
                }

                j++;
            }

            s = s.substr(j) + str[i];
            visited[str[i]] = true;
        }
    }

    mp[s] = s.size();
    string finalString = "";

    for (auto it : mp)
    {
        if (it.second > ans)
        {
            ans = it.second;
            finalString = it.first;
        }
    }

    // This is one of the possible longest string
    // It may happen that that other strings also have the same length
    cout << "Longest string is " << finalString << endl;
    return ans;
}

// TC O(N*N)
// SC O(256) = O(1)
// Test case like abcdeff -> TC O(N*N)

int lengthOfLongestSubstring2(string str)
{
    int ans = INT32_MIN;
    bool visited[256] = {false};
    int n = str.size();

    string s = "";

    for (int i = 0; i < n; i++)
    {
        if (!visited[str[i]])
        {
            s += str[i];
            visited[str[i]] = true;
        }
        else
        {
            int len = s.size();
            ans = max(ans, len);
            int j = 0;

            while (j < len)
            {
                visited[s[j]] = false;
                if (s[j] == str[i])
                {
                    j++;
                    break;
                }

                j++;
            }

            s = s.substr(j) + str[i];
            visited[str[i]] = true;
        }
    }

    int len = s.size();
    ans = max(ans, len);

    return ans;
}

// TC O(N)
// SC O(256) = Constant == O(1)

int lengthOfLongestSubstring3(string str)
{
    int n = str.size();
    int ans = 0, last = 0, rec = 0;
    vector<int> mp(256, -1);
    while (rec < n)
    {
        if (mp[str[rec]] != -1)
            last = max(last, mp[str[rec]] + 1);

        ans = max(ans, rec - last + 1);
        mp[str[rec]] = rec;
        rec++;
    }

    return ans;
}

int main()
{
    string str;
    cin >> str;

    int ans = lengthOfLongestSubstring(str);
    cout << "Length of Longest substring without repeating characters is = " << ans << endl;

    int ans2 = lengthOfLongestSubstring2(str);
    cout << "Length of Longest substring without repeating characters is = " << ans2 << endl;

    int ans3 = lengthOfLongestSubstring3(str);
    cout << "Length of Longest substring without repeating characters is = " << ans3 << endl;

    return 0;
}