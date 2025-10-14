//
// Created by 임희진 on 9/30/25.
//

#include "S_3_13414.h"
#include<iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k,l;
    cin >> k >> l; // 3 8

    unordered_map<string, int> um;
    for(int x=0; x<l; x++){
        string str;
        cin >> str;

//        기존의 값(value)이 새로운 값으로 덮어씌워집니다 (수정됩니다).
        um[str] = x;
    }

    vector<pair<int,string> > vp;

    for(auto x : um){
        vp.push_back(make_pair(x.second, x.first) ); // make_pair
    }

    sort(vp.begin(), vp.end());

    int cnt = 0;
    for(auto x :vp){
        if(cnt >= k) break;
        cout << x.second << "\n";
        cnt++;

    }
    return 0;
}
