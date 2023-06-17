#include <iostream>
#include <stack>
using namespace std;

// Day 29 MinStack

// Method 1
// TC O(1) for each operation
// SC O(N) due to we are using pair<int,int> in stack.

class MinStack
{
public:
    stack<pair<int, int>> st;

    MinStack() {}

    void push(int val)
    {
        int mini = st.empty() ? val : min(val, st.top().second);
        st.push({val, mini});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

// Method 2
// Space Optimization
// TC O(1) for each operation
// SC O(1) for each operation
class MinStack2
{
    stack<long long> s;
    long long minElem;

    MinStack2() {}

    long long getMin()
    {
        return minElem;
    }

    long long top()
    {
        long long t = s.top();
        return (t < minElem) ? minElem : t;
    }

    void pop()
    {
        long long t = s.top();
        s.pop();

        if (t < minElem)
            minElem = 2 * minElem - t;
    }

    void push(long long x)
    {
        if (s.empty())
        {
            minElem = x;
            s.push(x);
        }
        else if (x < minElem)
        {
            long long temp = 2 * x;
            s.push(temp - minElem);
            minElem = x;
        }
        else
        {
            s.push(x);
        }
    }
};

int main()
{
    MinStack minSt = MinStack();
    minSt.push(5);
    minSt.push(3);
    minSt.push(4);
    minSt.push(6);
    minSt.push(2);
    minSt.push(1);

    cout << minSt.getMin() << endl;
    minSt.pop();
    minSt.pop();
    minSt.pop();
    cout << minSt.top() << endl;
    cout << minSt.getMin() << endl;

    return 0;
}