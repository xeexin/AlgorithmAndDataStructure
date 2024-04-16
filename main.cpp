#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }


    return 0;
}