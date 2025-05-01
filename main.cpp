// 백준 S_2_16401

/*
    M명의 조카가 있고 N개의 과자가 있을 때, 조카 1명에게 줄 수 있는 막대 과자의 최대 길이를 구하라.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> m >> n; // 3 10
    vector<int> snack(n);
    for (int i = 0; i < n; i++) {
        cin >> snack[i]; //1 2 3 4 5 6 7 8 9 10
    }
    sort(snack.begin(), snack.end());

    int st = 1;
    int ed = snack[n - 1];

    int ret = 0;

    while (st <= ed) {
        int mid = (st + ed) / 2;

        int cnt = 0;
        for (int x = 0; x < n; x++) {
            cnt += snack[x] / mid;
        }
        if (cnt < m) {
            ed = mid - 1;
        } else {
            ret = mid;
            st = mid + 1;
        }
    }
    cout << ret;

    return 0;
}
