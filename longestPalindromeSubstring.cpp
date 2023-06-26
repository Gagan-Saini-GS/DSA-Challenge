#include <iostream>
#include <vector>
using namespace std;

// Day 45 Longest Palindrome Substring

// Best Method (Higest Optimized Apporach)
// TC O(N)
// SC O(1)

string longestPalindrome(string str)
{
    int n = str.size();

    if (n <= 1)
        return str;

    int maxIdx = 0;
    int maxLen = 1;
    int i = 0;

    while (i < n)
    {
        int start = i;
        int end = i;

        // expand the window from the end if it's an even palindrome
        while (end + 1 < n && str[end] == str[end + 1])
        {
            end++;
        }

        i = end + 1;

        // expand the window from both sides until it's not longer a palindrome
        while (start - 1 >= 0 && end + 1 < n && str[start - 1] == str[end + 1])
        {
            start--;
            end++;
        }

        int currLen = end - start + 1;
        if (currLen > maxLen)
        {
            maxIdx = start;
            maxLen = currLen;
        }
    }

    return str.substr(maxIdx, maxLen);
}

// Better Method Using Bottom-Up DP
// TC O(N*N)
// SC O(N*N)

string longestPalindrome2(string str)
{
    int n = str.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    string ans;
    int start = 0;
    int maxLen = 1; // Because a single character is always palindrome

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = k + i - 1;

            if (dp[i + 1][j - 1] && str[i] == str[j])
            {
                dp[i][j] = true;

                if (k > maxLen)
                {
                    maxLen = k;
                    start = i;
                }
            }
        }
    }

    return str.substr(start, maxLen);
}

bool checkPalindrome(string s)
{
    int l = 0, h = s.size() - 1;

    while (l < h)
    {
        if (s[l] != s[h])
            return false;

        l++;
        h--;
    }

    return true;
}

vector<string> generateAllSubstrings(string s)
{
    vector<string> ans;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for (int j = i; j < n; j++)
        {
            temp += s[j];
            ans.push_back(temp);
        }
    }

    return ans;
}

// Bruth Force
// Time Complexity O(N*N*N)
// SC O(1)
string longestPalindrome3(string str)
{
    // Step 1 : Generate all possible substrings
    // Step 2 : Check which is palidrome
    // Step 3 : Get max length string among them.

    string ans;
    int n = str.size();

    vector<string> allSubstrings = generateAllSubstrings(str);
    int len = allSubstrings.size();
    int max = INT32_MIN;

    for (int i = 0; i < len; i++)
    {
        if (checkPalindrome(allSubstrings[i]))
        {
            int tempLen = allSubstrings[i].size();
            if (tempLen > max)
            {
                max = tempLen;
                ans = allSubstrings[i];
            }
        }
    }

    return ans;
}

int main()
{
    string str;
    cin >> str;

    string s1 = longestPalindrome(str);
    cout << s1 << endl;

    string s2 = longestPalindrome2(str);
    cout << s2 << endl;

    string s3 = longestPalindrome3(str);
    cout << s3 << endl;

    return 0;
}