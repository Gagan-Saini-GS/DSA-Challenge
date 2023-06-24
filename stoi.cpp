#include <iostream>
using namespace std;

// Day 41 String to Integer (atoi)

// TC O(N)
// SC O(1)

int myAtoi(string s)
{
    int len = s.size();
    double num = 0;
    int i = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    bool positive = s[i] == '+';
    bool negative = s[i] == '-';
    positive == true ? i++ : i;
    negative == true ? i++ : i;
    while (i < len && s[i] >= '0' && s[i] <= '9')
    {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    num = negative ? -num : num;

    num = (num > INT32_MAX) ? INT32_MAX : num;
    num = (num < INT32_MIN) ? INT32_MIN : num;

    return int(num);
}

int main()
{
    string str;
    cin >> str;

    int ans = myAtoi(str);
    cout << ans << endl;

    return 0;
}