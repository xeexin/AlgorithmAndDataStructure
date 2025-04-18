// 백준 S_2_108870

/*
    Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표 Xj의 개수와 같아야 한다.

[2 4 -10 4 -9]

-10 -9 2 4 4  -> 정렬
 2  3  0 3 1  -> 압축 (예. 2보다 작은게 2개, 4보다 작은게 3개, -10보다 작은거 0개...)


*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n); // 원본

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> vv(v); // vv에 v복사

    sort(vv.begin(), vv.end()); // 오름차순 정렬

    vv.erase(unique(vv.begin(), vv.end()), vv.end()); //중복 제거 + 중복 숫자 뒤로 밀림

    unordered_map<int, int> um;
    for (int x=0; x<vv.size(); x++) {
        um[vv[x]]=x;
    }

    for (int x=0; x<n; x++) {
        cout << um[v[x]] << " ";
    }

    return 0;
}
