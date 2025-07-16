//
// Created by kosa on 25. 7. 14.
//

#include "S_1_6236.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
    n일 동안
    m 번만 돈 빼
    k원 인출

    -> K를 최소화
 */
int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;

    vector<int> v(n);
    for (int x = 0; x < n; x++) {
        cin >> v[x]; // x번째 날에 이용할 금액
        sum += v[x]; // 누적값
    }

    int ret = 0;
    int st, mid, ed;
    st = 1; // 최솟값
    ed = sum; // 최댓값
    int total; // 현재 남은 금액

    while (st <= ed) {
        mid = (st + ed) / 2; // 인출금액
        total = mid; // 인출 금액으로 초기화
        bool flag = true; // 성립 가능한지
        int cnt = 1; // 인출 횟수 1 초기화

        for (int x = 0; x < n; x++) {
            int day_money = v[x];
            if (day_money > mid) {
                // 하루에 쓸 돈이 인출 금액보다 크면 X
                flag = false;
                break;
            }
            if (day_money > total) {
                // 하루 쓸 돈이 남은 돈 보다 큰 경우
                total = mid; // 돈을 인출
                cnt++;
            }
            total -= day_money;
        }

        if (!flag || cnt > m) {
            // 인출 횟수가 많거나 성립 X
            st = mid + 1; // 인출 금액 늘려줌
        } else {
            ret = mid; // 인출 금액 저장
            ed = mid - 1; // 금액 낮춰서 탐색
        }
    }


    //첫 번째 줄에 현우가 통장에서 인출해야 할 최소 금액 K를 출력한다.
    cout << ret << endl;


    return 0;
}
