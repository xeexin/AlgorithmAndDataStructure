//
// Created by kosa on 25. 6. 5.
//

#include "S_3_2559.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int sum = 0;
    vector<int> v(n);
    for (int x = 0; x < n; x++) {
        cin >> v[x];
    }
    for (int x = 0; x < k; x++) {
        sum += v[x];
    }

    int max = sum;

    for (int x = 0; x < n - k; x++) {

        sum += v[x + k];
        sum -= v[x];

        if (max < sum) max = sum;
    }

    cout << max;

    return 0;
}
