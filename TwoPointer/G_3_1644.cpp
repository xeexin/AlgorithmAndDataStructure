//
// Created by kosa on 25. 7. 18.
//

#include "G_3_1644.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/**
    에라토스테네스의 체 알고리즘
    📌 핵심 아이디어:
    2부터 n까지 모든 수를 소수라고 가정

    이후 각 소수의 배수들을 지워나가면서 소수가 아닌 수들을 제거

    마지막에 남은 수들이 소수
 */
bool isPrime(int num) {
    // a × b = num인데, 만약 a > √num이면 b < √num이어야 함
    // 그래서 한쪽 범위(1 ~√ num)만 검사해도 충분

    /*
        num = 29
        √29 ≈ 5.38

        검사해야 할 x는 2, 3, 4, 5까지

        x * x <= 29 조건을 쓰면:

        2*2 = 4 → OK

        3*3 = 9 → OK

        4*4 = 16 → OK

        5*5 = 25 → OK

        6*6 = 36 > 29 → 반복 종료

        → 즉, x = 2 ~ 5까지만 검사해도 충분
     */

    for (int x = 2; x * x <= num; x++) {
        if (num % x == 0) { return false; }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;

    // n에 따라서 소수를 생성해야함
    // 소수 : 1과 자기 자신의 곱으로만 이루어진 숫자 : 나눠지는 수가 있으면 안됨.
    for (int x = 2; x <= n; x++) {
        if (isPrime(x)) v.push_back(x);
    }


    int st = 0;
    int sum = 0;
    int ed = 0;
    int cnt = 0;


    // while문 돌리기
    while (true) {
        if (sum >= n) sum -= v[st++];
        else if (ed == v.size()) break;
        else sum += v[ed++];

        if (sum == n) cnt++;
    }


    // 연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력
    cout << cnt;

    return 0;
}
