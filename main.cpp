//map에서 갈수 있는 MAXPOINT 구하기 문제

#include<iostream>
using namespace std;

int map[5][4] = {
        4,7,1,8,
        9,0,5,4,
        0,1,9,9,
        1,1,9,0,
        1,1,9,9 }; //0은 벽

int direct[3] = {-1, 0, 1}; // 좌 , 자신, 우

int MAX = -21e8;

void dfs(int lev, int now, int sum){

    if(lev==5){
        if (sum > MAX) {
            MAX = sum;
        }
        return;
    }

    for (int x = 0; x < 3; x++) {
        int dy = lev;
        int dx = now + direct[x];

        if(dy<0 || dx <0||dy>4 || dx>3)continue;
        if(map[dy][dx]==0)continue;

        dfs(lev + 1, now + direct[x], sum + map[dy][dx]);
    }

}

int main()
{
    for (int x = 0; x < 4; x++) {
        dfs(0, x, 0);
    }

    cout << MAX;

    return 0;
}