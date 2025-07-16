//
// Created by kosa on 25. 7. 15.
//

#include "../BinarySearch//G_5_3020.h"
#include<iostream>
#include<algorithm>
#include<vector>
/*
    동굴의 길이는 N미터(짝수)이고,
    높이는 H미터

    석순(바틈업)이고, 그 다음에는 종유석(탑다운)과 석순이 번갈아가면서 등장

    1. 장애물을 높이 별로 누적해서 저장합니다.
    2. 각 높이마다 부딪히는 석순 + 종유석의 개수를 계산합니다.
    3. 가장 작은 값과 그런 경우의 개수를 카운트합니다.


 */
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, h;
    cin >> n >> h;
    vector<int> bottom(h + 1, 0);
    vector<int> top(h + 1, 0);
    vector<int> ret(h + 1, 0);  // 각 높이별 총 충돌 수

    for (int x = 0; x < n / 2; x++) {
        int a, b;
        cin >> a >> b;

        // 석순: 아래에서 위로 자라므로 해당 높이부터 위까지 영향을 줌
        bottom[a]++;

        // 종유석: 위에서 아래로 자라므로, 역방향으로 누적할 예정이니
        // h+1 - b 위치에 +1 해놓고 아래에서부터 누적합을 계산할 것
        top[h + 1 - b]++;
    }

    // 누적합: 석순 - 아래에서 위로 올라오며 영향받는 구간 계산
    for (int x = h - 1; x >= 1; x--) {
        bottom[x] += bottom[x + 1];
    }

    int MIN = 21e8;
    int cnt = 0;

    // 누적합: 종유석 - 위에서 아래로 내려오며 영향받는 구간 계산
    for (int x = 1; x <= h; x++) {
        top[x] += top[x - 1];

        // 각 높이에서 충돌 수 = 석순 + 종유석
        ret[x] += top[x] + bottom[x];
        if (MIN > ret[x]) {
            cnt = 1;
            MIN = ret[x];
        } else if (ret[x] == MIN) { cnt++; }
    }
    cout << MIN << " " << cnt;
    return 0;
}
