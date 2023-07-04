#include <iostream>
#include <stack>
using namespace std;

// Day 57 Basic Calculator
// Using Sliding window

// TC O(N)
// SC O(N)
int calculate(string s)
{
    int n = s.size();
    int ans = 0;
    int sign = 1;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int num = 0;

            while (i < n && s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            ans += sign * num;
            i--;
        }
        else if (s[i] == '+')
            sign = 1;
        else if (s[i] == '-')
            sign = -1;
        else if (s[i] == '(')
        {
            st.push(ans);
            st.push(sign);
            ans = 0;
            sign = 1;
        }
        else if (s[i] == ')')
        {
            ans *= st.top(); // Getting Sign
            st.pop();
            ans += st.top(); // Getting Number
            st.pop();
        }
    }

    return ans;
}

int main()
{
    string str;
    cin >> str;

    int ans = calculate(str);
    cout << ans << endl;

    return 0;
}