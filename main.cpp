#include<iostream>
using namespace std;
char name[6] = "ABTKG";
int map[5][5] = {
        0,1,1,0,0,
        0,0,1,1,1,
        1,1,0,1,0,
        0,1,0,0,0,
        0,0,0,0,0,
};
int used[5];
int cnt;

void dfs(int now, int edIdx){

    //도착지 도착
    if (now == edIdx) {
        cnt++;
    }

    for (int x = 0; x < 5; x++) {
        if (used[x] == 0 && map[now][x] == 1) {
            used[x] = 1;
            dfs(x, edIdx);
            used[x] = 0;  //갔다 오면 0으로 초기화 해주기
        }
    }
}
int main()
{
    char st, ed;
    cin >> st >> ed;

    int stidx, edidx;

    // 시작지와 도착지 인덱스 찾기
    for (int x = 0; x < 5; x++) {
        if (name[x] == st) stidx = x;
        if(name[x]==ed) edidx = x;
    }

    used[stidx] = 1;
    dfs(stidx, edidx);

    cout << cnt << "개의 루트가 있음";

    return 0;
}