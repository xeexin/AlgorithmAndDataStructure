// 백준 S_2_1654

/*

오영식 k개의 랜선 (길이 제각각)
박성원  N개의 랜선

k개의 랜선으로 n개의 랜선을 만들쟈 (이때 최대 랜선 길이를 구하시오)

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> k >> n; // 4 11
    int max_len = 0;

    vector<int> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i]; // 802 743 457 539
        max_len = max(max_len, v[i]);
    }

    long long left = 1; // 0으로 못 나눔!
    long long right = max_len; //802
    long long mid = (left + right) / 2; //401

    while (left <= right) {
        int cnt = 0;
        for (int x = 0; x < k; x++) {
            cnt += v[x] / mid;
        }

        if (cnt >= n) left = mid + 1; //왜냐 최대길이를 구해야 함으로
        else right = mid - 1;
        mid = (left + right) / 2;
    }

    cout << mid << endl;


    return 0;
}
