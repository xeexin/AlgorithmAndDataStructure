// 백준 S_1_14889

#include <iostream>
#include<cstdlib>
using namespace std;
int n;
int MIN = 21e8;
int arr[21][21];
bool check[21];

void dfs(int lev, int st) {
    if (lev == (n / 2)) {
        int teamStart, teamLink;
        teamLink = 0;
        teamStart = 0;

        for (int y=0; y<n; y++) {
            for (int x=0; x<n; x++) {
                if (check[y] == true && check[x]== true) teamStart+=arr[y][x];
                if (check[y] == false && check[x] == false) teamLink+=arr[y][x];
            }
        }

        int gap = abs(teamLink - teamStart);
        if (gap < MIN) MIN = gap;
        return;
    }

    for (int x=st; x<n; x++) {
        check[x] = true;
        dfs(lev+1, x+1);
        check[x] = false;
    }

}

int main() {
    //1. 입력
    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> arr[y][x];
        }
    }

    dfs(0, 0);

    cout << MIN << endl;
}
