// 거스름돈을 최소로 받을 수 있는 갯수는?

#include<iostream>
using namespace std;
int coin[3] = { 110,70,10 };
int n;
int MIN = 21e8;
int answer;

void dfs(int lev, int sum){
    if(sum==0){
        if (lev < MIN) {
            MIN = lev;
        }
        return;
    }

    for (int x = 0; x < 3; x++) {
        dfs(lev + 1, sum - coin[x]);
    }

}
int main()
{
    cin >> n;
    dfs(0, n);
    cout << MIN;

    return 0;
}