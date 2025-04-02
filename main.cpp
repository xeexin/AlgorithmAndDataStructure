// 백준 S_1_14888

#include <iostream>
using namespace std;
int arr[12]; //순서 바뀌면 안됨.
int sam[4];
int n;
int MAX = -21e8;
int MIN = 21e8;

void dfs(int lev, int sum) {
    if (lev == n) {
        if (sum > MAX) MAX = sum;
        if (sum < MIN) MIN = sum;
        return;
    }
    for (int x = 0; x < 4; x++) {
        if (sam[x] > 0) {
            sam[x]--;
            if (x == 0) {
                // 덧셈
                dfs(lev + 1, sum + arr[lev]);
            } else if (x == 1) {
                // 뺄셈
                dfs(lev + 1, sum - arr[lev]);
            } else if (x == 2) {
                // 곱셈
                dfs(lev + 1, sum * arr[lev]);
            } else if (x == 3) {
                // 나눗셈
                int temp;
                if (sum < 0)
                    temp = -(-sum / arr[lev]);
                else
                    temp = sum / arr[lev];
                dfs(lev + 1, temp);
            }
            sam[x]++;
        }
    }
}

int main() {
    cin >> n;
    for (int x = 0; x < n; x++) {
        cin >> arr[x];
    }

    for (int x = 0; x < 4; x++) {
        cin >> sam[x];
    }

    dfs(1, arr[0]);

    cout << MAX << endl << MIN << endl;


    return 0;
}
