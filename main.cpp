// 백준 G_5_2230

/*



*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[n];
    for (int x = 0; x < n; x++) {
        cin >> arr[x];
    }

    sort(arr, arr + n); // 정렬 1 3 5

    int MIN = 21e8;
    int st = 0;
    int ed = 0;

    while (ed < n) {
        int diff = arr[ed] - arr[st];

        if (diff < m) {
            ed++;
        } else {
            MIN = min(MIN, diff);
            st++;
        }
    }


    cout << MIN;

    return 0;
}
