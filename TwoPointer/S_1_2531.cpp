//
// Created by kosa on 25. 6. 9.
//

#include "S_1_2531.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, d, k, c;
int eated[3001];
vector<int> sushi;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> N >> d >> k >> c;
    sushi.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }

    /* 첫 구간(0으로부터 k칸까지) 계산 */
    int count = 0;
    for (int i = 0; i < k; i++) {
        if (eated[sushi[i]] == 0) count++;
        eated[sushi[i]]++;
    }

    int maxCount = 0;
    //. 쿠폰 적용
    if (eated[c] == 0)
        maxCount = max(maxCount, count + 1);
    else
        maxCount = max(maxCount, count);

    /* 슬라이딩 윈도우 */
    for (int i = 1; i < N; i++) {
        //. 앞 칸 스시 제외
        eated[sushi[i-1]]--;
        if (eated[sushi[i-1]] == 0) count--;

        //. 새 스시 추가
        if (eated[sushi[(i + k - 1) % N]] == 0) count++;
        eated[sushi[(i + k - 1) % N]]++;

        //. 쿠폰 적용
        if (eated[c] == 0)
            maxCount = max(maxCount, count + 1);
        else
            maxCount = max(maxCount, count);
    }

    cout << maxCount;
}
