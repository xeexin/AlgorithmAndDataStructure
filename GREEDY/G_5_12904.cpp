//
// Created by 임희진 on 6/3/25.
//

#include "G_5_12904.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/**
    두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임
    문자열의 뒤에 A를 추가한다.
    문자열을 뒤집고 뒤에 B를 추가한다.
    S를 T로 바꿀 수 있으면 1을 없으면 0을 출력한다

    B
    BA
    AB
    ABB

    ABBA
    ABBA
 */
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    while(t.length() > s.length()){
        if(t.back() == 'A') t.pop_back();
        else if (t.back()=='B'){
            t.pop_back();
            reverse(t.begin(),t.end());
        }
    }

    cout << (t == s ? 1 : 0);
    return 0;
}
