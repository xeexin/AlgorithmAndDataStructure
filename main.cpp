#include<iostream>
using namespace std;
char name[5] = "ABCD";
int map[4][4] = {
        0,1,1,0,
        0,0,1,1,
        1,1,0,1,
        0,0,0,0,
};
struct Node {
    int idx;
    int lev;
} queue[20];
int used[4];

void bfs(int stIdx){
    queue[0] = {stIdx, 0};

    int head = 0;
    int tail = 1;

    while (head != tail) {
        Node now = queue[head++];
        cout << name[now.idx];

        for (int x = 0; x < 4; x++) {
            if (map[now.idx][x] == 1 && used[x] == 0) {
                used[x] = 1;
                queue[tail++] = {x, now.lev + 1};
            }
        }
    }
}
int main()
{
    char start;
    cin >> start;

    for (int x = 0; x < 4; x++) {
        if (name[x] = start) {
            used[x] = 1;
            bfs(x);
        }
    }


    return 0;
}