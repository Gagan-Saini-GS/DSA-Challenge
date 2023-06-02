// DAY-1

#include <bits/stdc++.h>
using namespace std;

// TC O(N)
// SC O(N)

bool validParentheses(string str)
{
    stack<char> st;
    int n = str.size();

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            st.push(str[i]);
        }
        else if (st.size() > 0)
        {
            if (st.top() == '(' && str[i] == ')')
                st.pop();
            else if (st.top() == '[' && str[i] == ']')
                st.pop();
            else if (st.top() == '{' && str[i] == '}')
                st.pop();
            else
                return false;
        }
        else
        {
            return false;
        }
    }

    if (st.size() > 0)
        return false;

    return true;
}

// Without Stack
// TC O(N)
// SC O(1)

bool validParentheses2(string str)
{
    int count = -1;
    int n = str.size();

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            str[++count] = str[i];
        }
        else
        {
            if (count >= 0 && count < n &&
                ((str[count] == '(' && str[i] == ')') || (str[count] == '[' && str[i] == ']') || (str[count] == '{' && str[i] == '}')))
                count--;
            else
                return false;
        }
    }

    if (count == -1)
        return true;

    return false;
}

int main()
{
    string str;
    cin >> str;

    if (validParentheses2(str))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;

    return 0;
}