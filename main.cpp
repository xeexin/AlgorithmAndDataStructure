//[Parametric Search Algorithm]

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string arr = "******____"; //60%
//string arr = "__________";
//string arr = "**********";
int main()
{
    int MAX = -1;

    int st = 0;
    int ed = arr.size() - 1;

    while (st <= ed) {
        int mid = (st + ed) / 2;

        if (arr[mid] == '*') {
            MAX = mid;
            st = mid + 1;
        } else {
            ed = mid - 1;
        }
    }

    cout << (MAX + 1) * 10 << "%";
    return 0;
}