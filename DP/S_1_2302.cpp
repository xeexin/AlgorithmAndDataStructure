//
// Created by kosa on 25. 5. 16.
//

#include "S_1_2302.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int dp[45];
int vip[45];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int x = 0; x < m; x++) {
        cin >> vip[x];
    }

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int x = 3; x <= n; x++) {
        dp[x] = dp[x - 1] + dp[x - 2];
    }

    int answer = 1;
    int st = 0;
    for (int x = 0; x < m; x++) {
        int ed = vip[x];
        answer = answer * dp[ed - st - 1];
        st = ed;
    }

    answer = answer * dp[n - st];
    cout << answer << endl;
    return 0;
}
