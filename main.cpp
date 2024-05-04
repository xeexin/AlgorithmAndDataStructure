#include<iostream>
using namespace std;
int map[20] = { 1,3,-1,6,-3,-1,5,100,3,2,5,1 };
int jump[3] = { 2,3,5 };
int MAX = -21e8;
int maxidx;
int sum;
void dfs(int lev, int idx){
     
    if (sum > MAX) {
        MAX = sum;
        maxidx = lev;
    }

    if(idx>11)return;

    for (int x = 0; x < 3; x++) {
        sum += map[idx + jump[x]];
        dfs(lev + 1, idx + jump[x]);
        sum -= map[idx + jump[x]];
    }
}
int main()
{
    dfs(0, 0);

    cout << maxidx << "번 점프해서 " << MAX;
    return 0;
}
