// 꽃이 피네요
// bfs

#include<iostream>
using namespace std;
int map[4][4];
struct Node {
    int y, x;
    int lev;
};
int head=0;
int tail = 1;
Node queue[30] = {{3, 2, 1}};
int direct[4][2] = {
        -1, 0,
        1, 0,
        0, -1,
        0, 1
};
int main()
{
    map[3][2] = 1;
    int answer = 0;

    while (head != tail) {
        Node now = queue[head++];
        answer = now.lev;
        for (int t = 0; t < 4; t++) {
            int dy = now.y + direct[t][0];
            int dx = now.x + direct[t][1];
            if (dy < 0 || dy > 3 || dx < 0 || dx > 3) continue;
            if(map[dy][dx]!=0)continue;

            map[dy][dx] = map[now.y][now.x] + 1;
            queue[tail++] = {dy, dx, now.lev + 1};
        };

        }
    cout << answer << "일차에 꽃이 만개 합니다 :) ";


    return 0;
}



