#include<iostream>
using namespace std;
int path[10];
// 3개의 주사위 던졌을 경우 << 중복 조합 >> 조합인데.. 나왔던 숫자 또 사용 가능
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
        dfs(lev + 1, x);
        path[lev] = 0;
    }
}
int main()
{
    dfs(0, 1);

    return 0;
}