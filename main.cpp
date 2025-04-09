// 백준 G_4_17141

#include <iostream>
#include <queue>
#include <vector>
#include<cstring>
using namespace std;
int n, m; // 바이러스 M개
int arr[51][51]; //. 0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 있는 칸
int visited[51][51];
bool check[51][51]; //바이러스 놓았는지 확인

struct node {
    int y, x;
};

vector<node> virus;
vector<node> virus_candidate; // 2인 위치 저장

int MIN = 21e8;
queue<node> q;
int direct[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};


//모두 퍼졌는지 확인
bool Spread() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (arr[y][x] == 0 && visited[y][x] == -1) {return false;}
        }
    }
    return true;
}


int bfs() {
    queue<node> q;

    memset(visited, -1, sizeof(visited));

    for (int i = 0; i < virus.size(); i++) {
        q.push({virus[i].y, virus[i].x});
        visited[virus[i].y][virus[i].x] = 0;
    }

    int res=0;

    while (!q.empty()) {
        node now = q.front();
        q.pop();

        for (int t=0; t<4; t++) {
            int dy = now.y + direct[t][0];
            int dx = now.x + direct[t][1];

            if (dy<0 || dx<0|| dy>=n|| dx>=n) continue;
            if (arr[dy][dx] != 1 && visited[dy][dx] == -1) {
                visited[dy][dx] = visited[now.y][now.x] + 1;
                res=max(res, visited[dy][dx]);
                q.push({dy, dx});
            }
        }
    }
    return Spread() ? res : 21e8; // 실패 시 큰 수 리턴
}

// 바이러스 위치 조합
void dfs(int yy, int xx, int lev) {
    if (lev == m) {
        int res = bfs();
        if (Spread() == true) {
            if (MIN > res) {
                MIN = res;
            }
        }
        return;
    }

    for (int y = yy; y < n; y++) {
        for (int x = xx; x < n; x++) {
            if (arr[y][x] != 2 || check[y][x] == true) continue;

            check[y][x] = true;
            virus.push_back({y, x});
            dfs(y, x, lev + 1);
            check[y][x] = false;
            virus.pop_back();
        }

        yy = 0;
    }
}


int main() {
    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> arr[y][x];
        }
    }

    dfs(0, 0, 0);

    if (MIN == 21e8) {
        MIN = -1;
    }
    cout << MIN << endl;


    return 0;
}
