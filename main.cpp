// 백준 S_4_2578

#include <iostream>

using namespace std;
int bingo[5][5];
bool check[5][5];
int line;

void iS_bingo(int yy, int xx) {
    int i;

    //가로
    for (i = 0; i < 5; i++) {
        if (!check[yy][i]) break;
    }
    if (i == 5) line++;

    //세로
    for (i = 0; i < 5; i++) {
        if (!check[i][xx]) break;
    }

    if (i == 5) line++;

    //대각선 1
    if (yy == xx) {
        for (i = 0; i < 5; i++) {
            if (!check[i][i]) break;
        }
        if (i == 5) line++;
    }

    //대각선 2
    if (yy == (4 - xx)) {
        for (i = 0; i < 5; i++) {
            if (!check[i][4 - i]) break;
        }
        if (i == 5) line++;
    }
}

void checking(int target) {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            if (bingo[y][x] == target) {
                check[y][x] = true;
                iS_bingo(y, x);
                return;
            }
        }
    }
}

int main() {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cin >> bingo[y][x];
        }
    }

    int num;
    int cnt = 0;

    for (cnt = 1; cnt<=25; cnt++) {
        cin >> num;
        checking(num);
        if (line >= 3) break; //빙고 조건
    }

    cout << cnt;

    return 0;
}
