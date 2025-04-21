// 백준 G_5_2170

/*



*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //속도 향상
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n; //4

    vector<pair<int, int> > line(n);

    for (int x = 0; x < n; x++) {
        cin >> line[x].first >> line[x].second;
    }

    sort(line.begin(), line.end()); // 정렬


    int st = line[0].first;
    int ed = line[0].second;
    int ret = 0;

    for (int x = 1; x < n; x++) {
        int s = line[x].first;
        int e = line[x].second;

        if (ed >= s) {
            ed = max(ed,e); //겹치면 확장
        } else {
            ret += (ed - st); // 끊기면 누적
            st = s;
            ed = e;
        }
    }

    ret += (ed - st);

    cout << ret ;

    return 0;
}
