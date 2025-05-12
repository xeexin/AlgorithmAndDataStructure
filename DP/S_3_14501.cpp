//
// Created by kosa on 25. 5. 9.
//

#include "S_3_14501.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// n <= 15
int dp[16];  // dp[x] = x일 부터의 최대 수익
int main(){

    // 속도향상
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //입력
    int n;
    cin >> n;

    vector<pair<int,int> >v(n);
    for(int x=0; x<n; x++){
        cin >> v[x].first;
        cin >> v[x].second;
    }

    // 2. 풀이
    for(int x=n-1; x>=0; x--){
        int time = v[x].first;
        int profit = v[x].second;

        if(x+time <= n) dp[x] = max(dp[x+1], profit + dp[x+time]);
        else dp[x] = dp[x+1];
    }

    cout << dp[0];

  return 0;

}
