#include<iostream>
using namespace std;
int path[10];
int used[10];
// 3개의 주사위 던졌을 경우 순열-> 한번 나왔던것은 또 나오면 않됨
void abc(int lev)
{
    if (lev == 3) {
        for (int x = 0; x < 3; x++) {
            cout << path[x];
        }
        cout << endl;
        return;
    }

    for (int x = 1; x <= 6; x++) {
        if(used[x]==1)continue;
        used[x] = 1;
        path[lev] = x;
        abc(lev + 1);
        path[lev] = 0;
        used[x] = 0;
    }

}
int main()
{
    abc(0);

    return 0;
}