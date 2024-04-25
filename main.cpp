#include<iostream>
using namespace std;
int path[10];

// 3개의 주사위 던졌을 경우 << 조합 >> ->  농구팀 예.... 순서 중복 X
void dfs(int lev, int st){
    if (lev == 3) {
        for (int x = 0; x < lev; x++) {
            cout << path[x] << " ";
        }
        cout << endl;
        return;
    }

    for (int x = st; x <= 6; x++) {
        path[lev] = x;
        dfs(lev + 1, x + 1);
        path[lev] = 0;
    }
}
int main()
{

    dfs(0, 1);

    return 0;
}