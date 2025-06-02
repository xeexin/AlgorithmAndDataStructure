//
// Created by kosa on 25. 6. 2.
//

#include "S_1_2785.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/**
    2  - 체인의 개수
    3 3 - 각각의 체인 길이


    5
    4 3 5 7 9
    - - - -
    - - -
    - - - - -
    - - - - - - -
    - - - - - - - - -

 */
int main() {
    int n;
    cin >> n; //5

    int cnt = 0;
    vector<int> v;

    for (int x = 0; x < n; x++) {
        int a;
        cin >> a;
        v.push_back(a); //4 3 5 7 9
    }

    sort(v.begin(), v.end()); // 3 4 5 7 9

    while (true) {
        if (v.size() == 1) break;

        v[v.size() - 2] += v[v.size() - 1];
        v.pop_back();
        cnt++;
        v[0]--;

        if (v[0] == 0) {
            for (int x = 0; x < v.size(); x++) {
                v[x] = v[x + 1];
            }
            v.pop_back();
        }
    }

    cout << cnt;

    return 0;
}

/*
 3 4 5 7 9
 3 4 5 16 9
 3 4 5 16
 2 4 5 16
 2 4 21 16
 2 4 21
 1 4 21
 1 25 21
 1 25
 0 25
 25

 */
