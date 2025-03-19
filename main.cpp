// 백준 5427

#include<iostream>
#include<queue>
using namespace std;
char map[1002][1002];
int direct[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int tn,h,w; // 테스트케이스 개수, 높이, 너비
queue<pair<int,int>> sq; //상근이 위치 큐
queue<pair<int,int>> fq; //불 위치 큐
void movef(){

    int size = fq.size();

    for (int x = 0; x < size; x++) {
        pair<int, int> now = fq.front();
        fq.pop();

        for (int t = 0; t < 4; t++) {
            int dy = now.first + direct[t][0];
            int dx = now.second + direct[t][1];

            if(dy < 0 || dx < 0 || dy > h-1 || dx > w-1) continue; //범위 밖
            if(map[dy][dx] != '.') continue; // 빈 공간이 아니면 컨티뉴
            map[dy][dx] = '*'; //불이 번짐
            fq.push({dy, dx});
        }
    }
}
int moves(){
    int time = 0;

    while (!sq.empty()) {
        time++;
        movef(); // 불 bfs (1초뒤 불이 번지는 곳으로 못가니까 불 먼저 퍼져야함)

        int size = sq.size();
        for (int x = 0; x < size; x++) {
            pair<int, int> now = sq.front();
            sq.pop();

            for (int t = 0; t < 4; t++) {
                int dy = now.first + direct[t][0];
                int dx = now.second + direct[t][1];

                if (dy < 0 || dx < 0 || dy > h - 1 || dx > w - 1) return time; // 범위 밖 = 출구
                if(map[dy][dx] != '.') continue;

                map[dy][dx] = '@';
                sq.push({dy, dx});
            }
        }
    }
    return -1;
}

void reset(int w, int h){
    while(!sq.empty()) sq.pop();
    while(!fq.empty()) fq.pop();

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            map[y][x] = '.';
        }
    }
}
int main(){

    cin >> tn;

    for (int x = 0; x < tn; x++) {
        cin >> w >> h;

        reset(w, h);

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                cin >> map[y][x];

                if(map[y][x]=='@') sq.push({y, x}); //상근이 위치 큐에 넣기
                if(map[y][x]=='*') fq.push({y, x}); //불 위치 큐에 넣기
            }
        }

        int ret = moves(); //상근이 움직이는 bfs

        if (ret == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else cout << ret << endl;
    }

    return 0;
}