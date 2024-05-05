//미로찾기
//시작(0,0)-도착(5,7)까지 갈수 있나
//방향 : 상하좌우
#include<iostream>
using namespace std;
int map[6][7]={
        0,0,0,0,0,0,0,
        0,0,1,0,1,1,0,
        0,0,1,0,0,0,0,
        1,0,0,1,0,1,1,
        0,1,0,1,0,0,0,
        0,1,0,0,1,0,2
}; //2는 도착  1은 장애물
int visited[6][7];
int direct[4][2] = {-1, 0,
                     1, 0,
                     0, -1,
                     0, 1};
int flag;

void dfs(int yy, int xx){
    if (map[yy][xx] == 2) {
        flag = 1;
        return;
    }

    if(flag==1)return;

    for (int t = 0; t < 4; t++) {
        int dy = yy + direct[t][0];
        int dx = xx + direct[t][1];

        if(dy <0 || dx<0|| dy>5 || dx >6)continue;
        if(map[dy][dx]==1)continue;
        if(visited[dy][dx]==1)continue;
        
        visited[yy][xx] = 1;
        dfs(dy, dx);
    }
}
int main()
{
    dfs(0, 0);  //출발점 (0,0)

    if(flag==1)cout << "갈 수 있음";
    else cout << "갈 수 없음";
    return 0;
}