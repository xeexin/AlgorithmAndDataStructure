#include<iostream>
using namespace std;
char name[6] = { "ABCDE" };
int map[5][5] = {
        0,1,1,0,0,
        0,0,0,1,1,
        0,0,0,0,0,
        0,0,0,0,0,
        0,0,0,0,0,
};
char path[10];
void dfs(int now, int lev){
    cout << path << endl;

    for (int x = 0; x < 5; x++) {
        if (map[now][x] == 1) {
            path[lev + 1] = name[x];
            dfs(x, lev + 1);
            path[lev + 1] = 0;
            
        }
    }
}
int main()
{

    path[0] = name[0]; //초기화

    dfs(0, 0);

    return 0;
}