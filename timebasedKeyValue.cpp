#include <iostream>
#include <map>
using namespace std;

// Day 38 Time Based Key-value Store

class TimeMap
{
public:
    map<string, map<int, string>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if (mp.count(key) != 0)
        {
            auto it = mp[key].upper_bound(timestamp);

            if (it == mp[key].begin())
                return "";

            --it;
            return it->second;
        }
        return "";
    }
};

// Sample Test Case
/*
[[],

["cat","zebra",1],["vampire","hall",2],["geraaf","zebra",3],["cat","geraaf",4],

["geraaf",5],["cat",6],["cat",7],["geraaf",8],["vampire",9],["cat",10],

["vampire","kawla",11],

["vampire",12],["cat",13],["vampire",14],

["zebra","z",15],["kawla","hall",16],["w","vampire",17],["hall","g",18],

["kawla",19],["zebra",20]]

*/
int main()
{
    TimeMap *tm = new TimeMap();

    // Example Test Case
    tm->set("cat", "zebra", 1);
    tm->set("vampire", "hall", 2);
    tm->set("geraaf", "zebra", 3);
    tm->set("cat", "geraaf", 4);

    cout << tm->get("geraaf", 5) << endl;
    cout << tm->get("cat", 6) << endl;
    cout << tm->get("cat", 7) << endl;
    cout << tm->get("geraaf", 8) << endl;
    cout << tm->get("vampire", 9) << endl;
    cout << tm->get("cat", 10) << endl;

    tm->set("vampire", "kawla", 11);

    cout << tm->get("vampire", 12) << endl;
    cout << tm->get("cat", 13) << endl;
    cout << tm->get("vampire", 14) << endl;

    tm->set("zebra", "z", 15);
    tm->set("kawla", "hall", 16);
    tm->set("w", "vampire", 17);
    tm->set("hall", "g", 18);

    cout << tm->get("kawla", 19) << endl;
    cout << tm->get("zebra", 20) << endl;

    return 0;
}