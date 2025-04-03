// 백준 G_4_9663
// *** 꼭 다시 한번 풀어보기!!!

// 룰 : 같은 행 || 같은 열 || 대각선에 퀸이 존재하면 안됨!!!

#include <iostream>
#include<cstdlib>
using namespace std;
int col[15]; // col[i] = i번째 행에 놓은 퀸의 열(column) 위치
int n, tot; //체스판의 크기, 가능한 경우의 수

bool check(int lev) {
    for (int x=0; x<lev; x++) {
        //대각선이거나 같은 라인인지 확인
        if (col[x] == col[lev] || abs(col[lev]- col[x]) == lev-x ) return false;

        // col[i]가 의미하는 것이 x좌표, i가 의미하는 것 y좌표이므로 차이가 일정하다면 대각선에 있다는 것을 알 수 있다.
    }
    return true;

}

void nqueen(int x) {
    if (x == n) {
        tot ++;
    }
    else {
        for (int i=0; i<n; i++) {
            col[x] = i; //해당 위치에 퀸을 배치
            if (check(x)) {
                nqueen(x+1);
            }
        }
    }
}
int main() {

   cin >> n;
    nqueen(0);
    cout << tot<<endl;
    return 0;
}
