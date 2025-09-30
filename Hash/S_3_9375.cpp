//
// Created by 임희진 on 9/30/25.
//

#include "S_3_9375.h"
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        unordered_map<string,int> um;


        int k;
        cin >> k;

        for (int y = 0; y < k; y++) {
            string a, b;
            cin >> a >> b;
            um[b]++;
        }

        int ans = 1;
        for(auto it = um.begin(); it != um.end(); it++){

            ans *= (it->second + 1);
        }

        cout << ans - 1 << "\n"; // 나체의 경우 빼기
    }

    return 0;
}
