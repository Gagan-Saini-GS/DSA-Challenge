#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Day 54 Minimum Window Substring

string minWindow(string str, string t)
{
    vector<int> mp(128, 0);
    int n = str.size();
    int m = t.size();

    if (m > n)
        return "";

    for (auto &ch : t)
        mp[ch]++;

    int count = m, begin = 0, end = 0, len = INT32_MAX, head = 0;

    while (end < n)
    {
        // mp[str[end++]]-- > 0;
        if (mp[str[end++]]-- > 0)
            count--;

        while (count == 0)
        {
            if (end - begin < len)
            {
                head = begin;
                len = end - begin;
            }

            if (mp[str[begin++]]++ == 0)
                count++;
        }
    }

    return len == INT32_MAX ? "" : str.substr(head, len);
}

string minWindow2(string str, string t)
{
    int n = str.size();
    int m = t.size();
    unordered_map<char, int> freq1; // Counting char's in s.
    unordered_map<char, int> freq2; // Counting char's in t.

    for (int i = 0; i < m; i++)
        freq2[t[i]]++;

    int s = 0, si = -1, minLen = INT32_MAX, count = 0;

    for (int i = 0; i < n; i++)
    {
        freq1[str[i]]++;

        if (freq1[str[i]] <= freq2[str[i]])
            count++;

        if (count == m)
        {
            while (freq1[str[s]] > freq2[str[s]] || freq2[str[s]] == 0)
            {
                if (freq1[str[s]] > freq2[str[s]])
                    freq1[str[s]]--;

                s++;
            }

            int len = i - s + 1;
            if (len < minLen)
            {
                minLen = len;
                si = s;
            }
        }
    }

    if (si == -1)
        return "";

    return str.substr(si, minLen);
}

int main()
{
    string str, t;
    cin >> str >> t;

    string ans1 = minWindow(str, t);
    cout << ans1 << endl;

    string ans2 = minWindow2(str, t);
    cout << ans2 << endl;

    return 0;
}