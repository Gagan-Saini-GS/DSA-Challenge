#include <iostream>
using namespace std;

// Day 12 ransomNote
// TC O(N)
// SC O(1) due to constant space

bool canConstruct(string ransomNote, string magazine)
{
    int n = magazine.size();
    int m = ransomNote.size();

    // Because ransomNote and magazine can only have lowercase alphabets
    int freq[26] = {0};

    for (int i = 0; i < n; i++)
        freq[magazine[i] - 'a']++;

    for (int i = 0; i < m; i++)
    {
        if (freq[ransomNote[i] - 'a'] == 0)
            return false;

        freq[ransomNote[i] - 'a']--;
    }

    return true;
}

int main()
{

    string ransomNote, magazine;
    cin >> ransomNote >> magazine;

    if (canConstruct(ransomNote, magazine))
        cout << "Can be build" << endl;
    else
        cout << "Can't be build" << endl;

    return 0;
}