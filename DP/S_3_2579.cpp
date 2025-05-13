//
// Created by 임희진 on 5/13/25.
//

/**
한 번에 한 계단 또는 두 계단 이동 가능.

세 계단 연속으로 밟는 건 불가능.

마지막 계단은 반드시 밟아야 함.

 */

#include "S_3_2579.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
// n<=300
int score[301]; //score[i]: i번째 계단까지 올라갔을 때의 최대 점수
int stair[301];
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int x=1; x<=n; x++) cin >> stair[x]; //1부터 입력 받기!

    score[1]=stair[1];
    score[2]=stair[2]+stair[1];
    score[3] = max(stair[1]+stair[3], stair[2]+stair[3]);

    for(int x=4; x<=n; x++){
        int a = score[x-2] + stair[x]; // 두칸
        int b = score[x-3] + stair[x-1] + stair[x]; // 두칸 한칸
        score[x]=max(a,b);
    }
    cout << score[n];

    return 0;
}
