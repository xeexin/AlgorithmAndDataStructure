//백준 7576번

#include<iostream>
#include <queue>
using namespace std;
int map[1001][1001];
int visited[1001][1001];
int m,n;
struct node{
    int y,x,lev;
};
node now;
int direct[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

int check(){
    int cnt = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if(map[y][x]==0) cnt++; //안 익은 토마토 개수
        }
    }

    return cnt;
}
int main(){

    cin >> m >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            int a;
            cin >> a;
            map[y][x] = a;
        }
    }

    queue<node>q;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (map[y][x] == 1){
                q.push({y, x, 0});
                visited[y][x] = 1;
            }
        }
    }

    int ret = check();

    if(ret ==0) {
        cout << 0;
        return 0;
    }

    while (!q.empty()) {
        now = q.front();
        q.pop();

        for (int t = 0; t < 4; t++) {
            int dy = now.y + direct[t][0];
            int dx = now.x + direct[t][1];

            if(dy < 0 || dx<0 || dy > n-1 || dx > m-1) continue; //범위 밖
            if(visited[dy][dx]==1)continue; // 중복
            if(map[dy][dx]==-1) continue; // 벽
            visited[dy][dx] = 1;
            map[dy][dx] = 1;
            q.push({dy, dx, now.lev + 1});
        }
    }

    ret = check();
    if(ret > 0) cout << -1;
    else cout << now.lev;

    return 0;
}