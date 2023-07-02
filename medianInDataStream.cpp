#include <iostream>
#include <queue>
using namespace std;

// Day 55 Find Median from Data Stream

class MedianFinder
{
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;

public:
    MedianFinder() {}

    void addNum(int x)
    {
        if (mx.empty() || mx.top() >= x)
            mx.push(x);
        else
            mn.push(x);

        if (mx.size() > mn.size() + 1)
        {
            mn.push(mx.top());
            mx.pop();
        }
        else if (mx.size() < mn.size())
        {
            mx.push(mn.top());
            mn.pop();
        }
    }

    double findMedian()
    {
        if (mx.size() == mn.size())
            return mx.top() / 2.0 + mn.top() / 2.0;

        return mx.top();
    }
};

int main()
{

    MedianFinder md;
    md.addNum(1);
    md.addNum(2);
    cout << md.findMedian() << endl;
    md.addNum(3);
    cout << md.findMedian() << endl;

    return 0;
}