#include "S_2_2630.h"
#include<iostream>
using namespace std;
int n;
int map[130][130];
int blue, white;

void solve(int yy, int xx, int size) {
    int check = map[yy][xx];

    for (int y = yy; y < yy + size; y++) {
        for (int x = xx; x < xx + size; x++) {
            if (check == 0 && map[y][x] == 1) { check = 2; } else if (check == 1 && map[y][x] == 0) { check = 2; }

            //다른 색 일 경우, 분할하기
            if (check == 2) {
                solve(yy, xx, size / 2); //왼쪽 위
                solve(yy, xx + size / 2, size / 2); //오른쪽 위
                solve(yy + size / 2, xx, size / 2); // 왼쪽 아래
                solve(yy + size / 2, xx + size / 2, size / 2); //오른쪽 아래
                return;
            }
        }
    }
    if (check == 0) {white++;}
    else blue++;
}

int main() {
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    solve(0, 0, n);
    cout << white << endl;
    cout << blue << endl;


    return 0;
}
