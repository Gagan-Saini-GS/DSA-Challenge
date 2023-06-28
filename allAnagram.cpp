#include <iostream>
#include <vector>
using namespace std;

// Day 49 Find All Anagram in a String

bool validAnagram(int *freqS, int *freqP)
{
    for (int i = 0; i < 26; i++)
    {
        if (freqS[i] != freqP[i])
            return false;
    }

    return true;
}

// TC O(N)
// SC O(26) = O(1)
vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;
    int n = s.size();
    int m = p.size();
    int freqP[26] = {0};
    int freqS[26] = {0};

    for (int i = 0; i < m; i++)
        freqP[p[i] - 'a']++;

    for (int i = 0; i < n; i++)
    {
        freqS[s[i] - 'a']++;
        if (i >= m - 1)
        {
            if (validAnagram(freqS, freqP))
            {
                ans.push_back(i - m + 1);
            }

            freqS[s[i - m + 1] - 'a']--;
        }
    }

    return ans;
}

int main()
{

    string s, p;
    cin >> s >> p;

    vector<int> ans = findAnagrams(s, p);

    for (auto &it : ans)
        cout << it << " ";

    cout << endl;

    return 0;
}