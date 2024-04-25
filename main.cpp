#include<iostream>
using namespace std;
int path[10];
// 3개의 주사위 던졌을 경우 중복순열-> 다출력 하기
void abc(int level)
{
    if (level == 3) {
        for (int x = 0; x < 3; x++) {
            cout << path[x];
        }
        cout << endl;
        return;
    }

    for (int x = 1; x <= 6; x++) {
        path[level] = x;
        abc(level + 1);
        path[level]=0;
    }
}
int main()
{
    abc(0);

    return 0;
}