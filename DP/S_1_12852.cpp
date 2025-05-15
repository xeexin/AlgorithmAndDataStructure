//
// Created by kosa on 25. 5. 14.
//

#include "S_1_12852.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> dp(n + 1); // dp[i] = i를 1로 만드는 최소 연산 횟수
    vector<int> path(n + 1); // path[i]=i 이전에 거쳤던 수

    dp[1] = 0; // 1은 연산횟수 0임

    for (int x = 2; x <= n; x++) {
        dp[x] = dp[x - 1] + 1;  // x-1에서 +1 연산!!!
        path[x] = x - 1;

        if (x % 2 == 0 && dp[x] > dp[x / 2] + 1) {
            dp[x] = dp[x / 2] + 1;
            path[x] = x / 2;
        }

        if (x % 3 == 0 && dp[x] > dp[x / 3] + 1) {
            dp[x] = dp[x / 3] + 1;
            path[x] = x / 3;
        }
    }

    cout << dp[n] << endl;

    while (n > 0) {
        cout << n << " ";
        n = path[n];
    }
    return 0;
}
