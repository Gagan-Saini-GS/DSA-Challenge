#include <iostream>
#include <vector>
using namespace std;

// Day 40 Sort Colors

// TC O(N)
// SC O(1)
// sort 0 1 2 (DNF sort)
void sortColors(vector<int> &arr)
{
    int zero = 0, one = 0, two = arr.size() - 1;

    while (one <= two)
    {
        if (arr[one] == 0)
        {
            swap(arr[one], arr[zero]);
            zero++;
            one++;
        }
        else if (arr[one] == 1)
        {
            one++;
        }
        else
        {
            swap(arr[one], arr[two]);
            two--;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sortColors(arr);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}