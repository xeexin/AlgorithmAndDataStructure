#include<iostream>
using namespace std;
char name[5] = "ABCD";
int map[4][4] = {
        0,1,1,0,
        0,0,1,1,
        1,1,0,1,
        0,0,0,0,
};
struct node {
    int idx;
    int lev;
    int used[4];
} queue[30];

int main() {
    int cnt = 0;

    int head = 0;
    int tail = 1;

    queue[0]={0,0,{1,0,0,0}}; //시작 인덱스 'A'

    while (head != tail) {

        node now = queue[head++];

        if (name[now.idx] == 'D') cnt++;  //도착 인덱스 'D'

        for (int x = 0; x < 4; x++) {
            if (map[now.idx][x] == 1 && now.used[x] == 0) {
                queue[tail] = now;
                queue[tail].idx = x;
                queue[tail].lev = now.lev + 1;
                queue[tail].used[x] = 1;
                tail++;
            }
            }
        }
    cout << cnt;
    
    return 0;
}