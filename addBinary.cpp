#include <iostream>
#include <algorithm>
using namespace std;

// Day 15 Add Binary
// Given Two binary return their binary sum

char findSum(char a, char b, char &carry)
{
    if (carry == '1')
    {
        if (a == '1' && b == '1')
        {
            carry = '1';
            return '1';
        }
        else if (a == '0' && b == '0')
        {
            carry = '0';
            return '1';
        }
        else
        {
            // When (a == '0' && b == '1' ) || (a == '1' && b == '0')
            carry = '1';
            return '0';
        }
    }
    else
    {
        if (a == '1' && b == '1')
        {
            carry = '1';
            return '0';
        }
        else if (a == '0' && b == '0')
        {
            carry = '0';
            return '0';
        }
        else
        {
            // When (a == '0' && b == '1' ) || (a == '1' && b == '0')
            carry = '0';
            return '1';
        }
    }
}

// TC O(N)
// SC O(1)
string addBinary(string a, string b)
{
    string ans = "";

    char carry = '0';
    int n = a.size();
    int m = b.size();
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0)
    {
        char sum = findSum(a[i], b[j], carry);
        ans += sum;
        i--;
        j--;
    }

    while (i >= 0)
    {
        ans += findSum(a[i], '0', carry);
        i--;
    }

    while (j >= 0)
    {
        ans += findSum('0', b[j], carry);
        j--;
    }

    if (carry == '1')
        ans += carry;

    reverse(ans.begin(), ans.end());
    return ans;
}

// Little compact code
// TC O(N)
// SC O(1)
string addBinary2(string a, string b)
{
    string ans = "";
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry != 0)
    {
        if (i >= 0)
        {
            carry += a[i] - '0';
            i--;
        }

        if (j >= 0)
        {
            carry += b[j] - '0';
            j--;
        }

        ans += (carry % 2) + '0';
        carry /= 2;
    }

    if (carry == 1)
        ans += carry + '0';

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a, b;
    cin >> a >> b;

    string ans = addBinary(a, b);
    cout << ans << endl;
    string ans2 = addBinary2(a, b);
    cout << ans2 << endl;

    return 0;
}