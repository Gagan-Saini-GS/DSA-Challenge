#include <iostream>
using namespace std;

// Day 5

// TC O(N) and SC O(1)
bool isAnagram(string s, string t)
{
    int n = s.size();
    int m = t.size();

    if (n != m)
        return false;

    // TC : O(N) and SC:O(1)
    // int freqS[26] = {0};
    // int freqT[26] = {0};
    // for(int i=0;i<n;i++){
    //     freqS[s[i]-'a']++;
    //     freqT[t[i]-'a']++;
    // }
    // for(int i=0;i<26;i++){
    //     if(freqS[i] != freqT[i]){
    //         return false;
    //     }
    // }

    // Little Optimization
    int freq[26] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;

    if (isAnagram(s, t))
        cout << "Valid Anagram" << endl;
    else
        cout << "Not a Valid Anagram" << endl;

    return 0;
}