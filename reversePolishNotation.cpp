#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Day 24 Evaluate Reverse Polish Notation

// ["2","1","+","3","*"] => ((2 + 1) * 3) = 9
// ["4","13","5","/","+"] => (4 + (13 / 5)) = 6
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"] => ((10 * (6 / ((9 + 3) * -11))) + 17) + 5 = 22

// Helper function
// TC O(Length of string)
// SC O(1)
int getNum(string str)
{
    int ans = 0;
    int n = str.size();

    int start;
    if (str[0] == '-')
        start = 1;
    else
        start = 0;

    for (int i = start; i < n; i++)
        ans = ans * 10 + (str[i] - '0');

    if (start == 1)
        return -ans;

    return ans;
}

// TC O(N)
// SC O(N) for stack
int evalRPN(vector<string> &arr)
{
    int n = arr.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/")
        {
            // calculation
            if (st.size() >= 2)
            {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                int newNum;

                if (arr[i] == "+")
                    newNum = second + first;
                else if (arr[i] == "-")
                    newNum = second - first;
                else if (arr[i] == "*")
                    newNum = second * first;
                else if (arr[i] == "/" && first != 0)
                    newNum = second / first;

                st.push(newNum);
            }
        }
        else
        {
            int num = getNum(arr[i]);
            st.push(num);
        }
    }

    return st.top();
}

int main()
{
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = evalRPN(arr);
    cout << "Ans of Evaluated Expression is = " << ans << endl;

    return 0;
}