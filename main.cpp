#include<iostream>
using namespace std;
int rate[5] = { 0,3,1,4,1 };
int map[5][5] = {
        0,1,1,0,0,
        1,0,0,1,1,
        1,0,0,1,0,
        0,1,1,0,1,
        0,1,0,1,0,
};
int stindex = 0;
int edindex = 4;

int used[5];
int MIN = 21e8;
void dfs(int now, int sum){

    if(sum > MIN)return;

    if (now == edindex) {
        if (sum < MIN) {
            MIN = sum;
            return;
        }
    }

    for (int x = 0; x < 5; x++) {
        if (map[now][x] == 1 && used[x] == 0) {
            used[x] = 1;
            dfs(x, sum + rate[x]); // += 사용하면 안됨!!
            used[x] = 0;
        }
    }

}
int main()
{
    used[stindex] = 1;
    dfs(stindex, rate[stindex]);

    cout << MIN;

    return 0;
}