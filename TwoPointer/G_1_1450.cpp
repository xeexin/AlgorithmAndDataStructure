//
// Created by kosa on 25. 7. 18.
//
/*
    세준이는 N개의 물건을 가지고 있고, 최대 C만큼의 무게를 넣을 수 있는 가방을 하나 가지고 있다.
    N개의 물건을 가방에 넣는 방법의 수를 구하는 프로그램을 작성하시오.

    첫째 줄에 N과 C가 주어진다. N은 30보다 작거나 같은 자연수, C는 109보다 작거나 같은 음이 아닌 정수이다.
    둘째 줄에 물건의 무게가 주어진다. 무게도 109보다 작거나 같은 자연수이다.
 */

#include "G_1_1450.h"
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long c;
vector<long long> arr;
vector<long long> left_sum;
vector<long long> right_sum;

void dfs(int st, int ed, long long sum, vector<long long> &ret) {
    // '&' 써서 값이 참조 되도록 (not 복사)
    if (sum > c) return;
    if (st == ed) {
        ret.push_back(sum);
        return;
    }
    dfs(st + 1, ed, sum, ret); //현재 물건 선택 안함
    dfs(st + 1, ed, sum + arr[st], ret); //현재 물건 선택함
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    arr.resize(n);
    for (int i = 0; i < n; i++) { cin >> arr[i]; }

    // 앞 절반, 뒷 절반 나누기
    dfs(0, n / 2, 0, left_sum);
    dfs(n / 2, n, 0, right_sum);

    // 정렬
    sort(right_sum.begin(), right_sum.end());

    // 앞쪽 리스트 A와, 뒤쪽 리스트 B를 조합해서 A[i] + B[j] ≤ C인 경우의 수를 센다    →    이 때 B는 정렬 후 upper_bound 사용
    int ans = 0;
    for (long long x: left_sum) {
        ans += upper_bound(right_sum.begin(), right_sum.end(), c - x) - right_sum.begin();
    }

    cout << ans;

    return 0;
}
