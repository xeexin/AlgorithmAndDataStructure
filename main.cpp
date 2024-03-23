//bfs
// [주사위] 숫자 n개 입력 받고 n개의 모든 주사위 수 구하기
#include<iostream>
using namespace std;
int n;
int path[6];

void abc(int lev){

    //종료 조건
    if (lev == n) {
        //출력
        for (int x = 0; x < n; x++) {
            cout << path[x] << " ";
        }
        cout << "\n";
        return;
    }

    for (int x = 1; x <= 6; x++) {
        path[lev] = x;
        abc(lev + 1);
        path[lev] = 0;
    }

}
int main()
{
    cin >> n;
    abc(0);


    return 0;
}