//
// Created by kosa on 25. 8. 5.
//

#include "G_4_2110.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 공유기 간의 최소 거리가 dist일 때, 설치 가능한 공유기 개수를 반환하는 함수
int canInstall(const vector<int> &v, int dist) { //수정이 필요 없으면 const 꼭 붙이는 게 좋음!

    int cnt = 1; // 첫집에 무조건 설치됨으로
    int last = v[0]; // 마지막으로 설치한 공유기 위치를 기록
    for (int x = 1; x < v.size(); x++) {
        if (v[x] - last >= dist) {
            cnt++;
            last = v[x];
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    int MAX = -21e8;
    for (int x = 0; x < n; x++) {
        cin >> v[x];
        if (v[x] > MAX) { MAX = v[x]; }
    }
    sort(v.begin(), v.end()); // 1 2 4 8 9

    // 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램

    int st = 1; // 최소거리
    int ed = v[n - 1] - v[0]; // 최대거리 (8)
    int ans = 0;


    while (st <= ed) {
        int mid = (st + ed) / 2;

        // mid 거리로 공유기를 설치했을 때 설치 가능한 개수를 계산
        if (canInstall(v, mid) >= c) { // c개 이상 설치 가능 → 거리를 더 벌릴 수 있음
            ans = mid;  // 일단 이 거리 저장
            st = mid + 1; // 더 넓은 거리 시도
        } else {
            ed = mid - 1;  // 설치 부족 → 거리 좁혀야 함
        }
    }

    cout << ans;

    return 0;
}
