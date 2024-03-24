/*7 3 1 2 카드 - 3묶음
각 묶음에서 1개씩 뽑아서 더할 경우, 합이 10이 나오는 경우?
[path안써서]*/

#include<iostream>
using namespace std;

// char path[20];
int cardList[4] = { 7,3,1,2 };
int cnt = 0;

void card(int lev, int sum) {
    //종료 조건
    if(sum >10)return;

    if (lev == 3 && sum == 10){
        cnt++;
        return;
    }

    for (int x = 0; x < 4; x++) {
        card(lev + 1, sum + cardList[x]);
    }
}

int main()
{
    card(0,0);
    cout << cnt;


    return 0;
}