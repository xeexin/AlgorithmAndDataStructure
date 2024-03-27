#include<iostream>
using namespace std;
char name[7] = { "AKTBGS" };
int map[6][6] = {
        0,1,1,0,0,0,
        0,0,0,1,1,0,
        0,0,0,0,0,1,
        0,0,0,0,0,0,
        0,0,0,0,0,0,
        0,0,0,0,0,0
};
struct Node {
    int idx;
    int lev;
};
Node queue[20] = {{0, 0}};
int head = 0;
int tail = 1;
int main()
{
    while (head != tail) {
        Node now = queue[head++];
        cout << name[now.idx] << " ";
        for (int x = 0; x < 6; x++) {
            if (map[now.idx][x] == 1) {
                queue[tail++] = {x, now.lev + 1};
            }
        }
    }



    return 0;
}


