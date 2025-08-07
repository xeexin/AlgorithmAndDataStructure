//
// Created by kosa on 25. 8. 7.
//
/*
    세준이는 크기가 N×N인 배열 A를 만들었다.
    배열에 들어있는 수 A[i][j] = i×j 이다.
    이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다.
    B를 오름차순 정렬했을 때, B[k]를 구해보자.

    배열 A와 B의 인덱스는 1부터 시작한다.

    첫째 줄에 배열의 크기 N이 주어진다.
    N은 105보다 작거나 같은 자연수이다.
    둘째 줄에 k가 주어진다.
    k는 min(109, N2)보다 작거나 같은 자연수이다.
 */
#include "G_1_1300.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    long long st = 1;
    long long ed = (long long) n * n;
    long long ans = 0;

    // 어떤 수 mid보다 작거나 같은 수가 배열 B에 몇 개 존재하는지를 구할 수 있다면,
    // k번째 수를 이분 탐색으로 찾을 수 있음

    while (st <= ed) {
        long long mid = (st + ed) / 2;

        long long cnt = 0;
        for (int x = 1; x <= n; x++) {
            cnt += min(mid / x, (long long) n);  // ** 이거 이해가 관건인듯
        }

        if (cnt < k) {
            st = mid + 1;
        } else {
            ans = mid;
            ed = mid - 1;
        }
    }

    cout << ans << endl;


    return 0;
}
