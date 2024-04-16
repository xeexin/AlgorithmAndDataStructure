/*
5
0 0 0 1 0
0 0 1 0 0
0 0 0 1 1
1 0 1 0 1
0 0 1 1 0
 */

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v;

    for (int y = 0; y < n; y++) {
        v.push_back({});
        for (int x = 0; x < n; x++) {
            int a;
            cin >> a;
            v[y].push_back(a);
        }
    }

    return 0;
}