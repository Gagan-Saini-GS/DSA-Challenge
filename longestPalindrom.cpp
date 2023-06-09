#include <iostream>
using namespace std;

// Day 14
// Returns the length of the longest palindrom

// TC O(N)
// SC O(255) = O(1) Constant space

int longestPalindrome(string s)
{
    int n = s.size();
    int freq[255] = {0};

    for (int i = 0; i < n; i++)
        freq[s[i]]++;

    int ans = 0, maxi = INT32_MIN;
    int maxFreqChar = 0;

    for (int i = 0; i < 255; i++)
    {
        if (freq[i] != 0)
        {
            if (freq[i] % 2 == 0)
                ans += freq[i];
            else
            {
                if (freq[i] > maxi)
                {
                    maxi = freq[i];
                    maxFreqChar = i;
                }
            }
        }
    }

    if (maxi != INT32_MIN)
        ans += maxi;

    for (int i = 0; i < 255; i++)
    {
        if (freq[i] % 2 != 0 && i != maxFreqChar)
            ans += (freq[i] - 1);
    }

    return ans;
}

int longestPalindrome2(string s)
{
    int n = s.size();
    int freq[58] = {0};

    for (int i = 0; i < n; i++)
        freq[s[i] - 'A']++;

    int ans = 0, maxi = INT32_MIN;
    int maxFreqChar = 0;

    for (int i = 0; i < 58; i++)
    {
        if (freq[i] != 0)
        {
            if (freq[i] % 2 == 0)
                ans += freq[i];
            else
            {
                if (freq[i] > maxi)
                {
                    maxi = freq[i];
                    maxFreqChar = i;
                }
            }
        }
    }

    if (maxi != INT32_MIN)
        ans += maxi;

    for (int i = 0; i < 58; i++)
    {
        if (freq[i] % 2 != 0 && i != maxFreqChar)
            ans += (freq[i] - 1);
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    int ans = longestPalindrome(s);
    cout << "Length of longest palindrom = " << ans << endl;

    int ans2 = longestPalindrome2(s);
    cout << "Length of longest palindrom = " << ans2 << endl;

    return 0;
}