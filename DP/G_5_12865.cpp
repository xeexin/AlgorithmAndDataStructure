//
// Created by kosa on 25. 5. 19.
//

#include "G_5_12865.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// N개의 물건이 있다. 각 물건은 무게 W와 가치 V
// V만큼 즐길 수 있다. K만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다.
int main() {
    int n; //물품의 수  (4)
    int k; // 버틸 수 있는 무게  (7)
    cin >> n >> k;

    vector<pair<int, int> > v(n + 1); // {무게, 가치}
    for (int x = 1; x <= n; x++) {
        cin >> v[x].first; // 물건의 무게
        cin >> v[x].second; // 뮬건의 가치
    }

    /*
    0 0
    6 13
    4 8
    3 6
    5 12
     */

    // 배낭에 넣을 수 있는 물건들의 가치합의 최댓값  n=4,k=7
    vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));

    for (int y=1; y<=n; y++) {
        for (int x=0; x<=k; x++) {
            if (x<v[y].first) {
                dp[y][x]=dp[y-1][x]; // 현재 물건을 못 넣음
            }else {
                dp[y][x]=max(dp[y-1][x], dp[y-1][x-v[y].first] + v[y].second);
            }
        }
    }

    cout << dp[n][k];
    return 0;
}
