// 백준 G_4_1477

/*
    첫째 줄에 현재 휴게소의 개수 N, 더 지으려고 하는 휴게소의 개수 M, 고속도로의 길이 L이 주어진다. 둘째 줄에 현재 휴게소의 위치가 공백을 사이에 두고 주어진다. N = 0인 경우 둘째 줄은 빈 줄이다.

    첫째 줄에 M개의 휴게소를 짓고 난 후에 휴게소가 없는 구간의 최댓값의 최솟값을 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, l;
    cin >> n >> m >> l;

    vector<int> v;
    for (int x = 0; x < n; x++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    // 양 끝점도 포함
    v.push_back(0);
    v.push_back(l);
    sort(v.begin(), v.end());

    int st = 1, ed = l - 1;
    int answer = 0;

    while (st <= ed) {
        int mid = (st + ed) / 2;
        int count = 0;

        for (int i = 1; i < v.size(); i++) {
            int dist = v[i] - v[i - 1];
            count += (dist - 1) / mid; // 이 구간에 필요한 휴게소 수
        }

        if (count > m) {
            st = mid + 1; // 너무 많은 휴게소가 필요 → mid가 작음
        } else {
            answer = mid; // 일단 가능한 mid → 더 작은 값도 가능한지 탐색
            ed = mid - 1;
        }
    }

    cout << answer;
    return 0;
}