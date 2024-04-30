//두 라인에서 숫자를 1개씩 번걸아 가면서 선택할 때
// 5 2 7 -5 -7 9
// 4 -5 -7 9 -5 3
// 첫번째 선택시 *1 두번째 선택한 값 *2 씩 가중치를 더한다고 할때
// 총 합이 0에 가장 가까운 수를 구하고자 한다면
// 그 총 합이 몇이 될까요?

#include<iostream>
#include<cstdlib>
using namespace std;
int line1[6] = { 5, 2 ,7, -5 ,-7, 9 };
int line2[6] = { 4 ,- 5, -7 ,9, -5, 3 };
int used1[6];
int used2[6];
int MIN = 21e8;
int answer;

void dfs(int lev, int sum){
    if (lev == 12) {
        if (abs(sum) < MIN) {
            MIN = sum;
            answer = sum;
        }
        return;
    }

    if (lev % 2 == 0) {
        for (int x = 0; x < 6; x++) {
            if(used1[x]==1) continue;
            used1[x] = 1;
            dfs(lev + 1, sum + (line1[x] * lev + 1));
            used1[x] = 0;
        }
    } else {
        for (int x = 0; x < 6; x++) {
            if(used2[x]==1 )continue;
            used2[x] = 1;
            dfs(lev + 1, sum + (line2[x] * lev + 1));
            used2[x] = 0;
        }
    }

}
int main()
{
    dfs(0, 0);
    cout << answer;
    return 0;
}
