//
// Created by kosa on 25. 7. 16.
//

#include "G_4_1806.h"
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s; // 10 15
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; // 5 1 3 5 10 7 4 9 2 8
    }

    // S 이상이 되는 것 중, 가장 짧은 것의 길이 (*연속된 m개의 합이 아님!)

    // 이 중 For문 사용 안됨 (시간 초과)
    int sum = 0, st = 0, ed = 0, minLen = n + 1;
    for (ed = 0; ed < n; ed++) {
        sum += v[ed];

        // if 아니고 while 써야함!!! (최단길이 이기 때문에)
        while (sum >= s) {
            minLen = min(minLen, ed - st + 1);
            sum -= v[st++];
        }
    }

    if (minLen == n + 1) cout << 0;
    else cout << minLen;


    return 0;
}
