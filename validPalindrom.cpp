#include <iostream>
#include <algorithm>
using namespace std;

// Day 3
// TC O(N) and SC O(1)
bool isPalindrome(string s)
{
    int n = s.size();
    string str = "";

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            str += s[i];
        else if (s[i] >= '0' && s[i] <= '9')
            str += s[i];
        else if (s[i] >= 'A' && s[i] <= 'Z')
            str += s[i] + 32;
    }

    string temp = str; // before reverse
    reverse(str.begin(), str.end());

    if (str == temp)
        return true;

    return false;
}

int main()
{

    string str;
    cin >> str;

    if (isPalindrome(str))
        cout << "Valid Palindrom" << endl;
    else
        cout << "Invalid not a palindrom" << endl;

    return 0;
}