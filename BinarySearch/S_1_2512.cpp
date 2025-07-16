//
// Created by kosa on 25. 7. 7.
//

#include "../BinarySearch//S_1_2512.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n; // 4

    vector<int> v(n);

    for (int x = 0; x < n; x++) {
        cin >> v[x]; //120 110 140 150
    }
    cin >> m; //485

    sort(v.begin(), v.end()); // 110 120 140 150

    int sum, ret;
    int st = 0;
    int ed = v[n - 1]; // 150

    while (st <= ed) {
        sum = 0;
        int mid = (st + ed) / 2;

        for (int x = 0; x < n; x++) {
            sum += min(v[x], mid);
        }

        if (sum <= m) {
            ret = mid;
            st = mid + 1;
        } else {
            ed = mid - 1;
        }
    }

    cout << ret;

    return 0;
}
