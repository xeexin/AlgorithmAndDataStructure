// 백준 S_2_2805

/*
    나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M

    20
    15
    10
    17

    h : 15

    15 -> 5
    15 -> 0
    10 -> 0
    15 -> 2

    m미터 나무를 집에 가져가고 싶은데 그 최댓값을 구해라
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m; // 4 7
    int MAX=0;

    // 적어도 m미터

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; // 20 15 10 17
    }
    sort(v.begin(), v.end()); // 10 15 17 20

    long long st = 0;
    long long ed = v[n - 1];

    while(st<=ed) {
        long long sum = 0;
        long long mid = (st + ed) / 2;

        for(int x=0; x<n; x++){
            if(v[x]-mid > 0 ) sum += (v[x] - mid);
        }

        if(sum >= m){
            MAX = mid;
            st = mid+1;
        }else{
            ed = mid-1;
        }
    }

    cout << MAX;

    return 0;
}
