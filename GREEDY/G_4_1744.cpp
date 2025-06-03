//
// Created by 임희진 on 6/3/25.
//

#include "G_4_1744.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p, m;  // 양수벡터, 음수벡터

    for(int x=0; x<n; x++){
        int num;
        cin >> num;;

        if(num < 1) m.push_back(num); // 음수에 0도 넣음
        else p.push_back(num);
    }

    //양수 내립차순
    sort(p.begin(), p.end(), greater<int>());

    //음수 오름차순
    sort(m.begin(), m.end());


    // 마이너스 처리...
    // 1. -끼리 곱하기
    // 2.  0하고 곱해서 0으로 만들기

    // 1은 곱하지 말고 더하기

    int cal = 0;
    if(p.size() % 2 !=0) cal += p[p.size() - 1];  //홀수인 경우 가장 작은수는 더해주기
    for(int x=0; x< (int) p.size()-1; x+=2){
        if(p[x+1]==1) cal += p[x] + p[x + 1];   // 1인 경우는 더하기
        else if (p[x+1] >0) cal += p[x] * p[x + 1]; // 나머지 곱하기
    }
    if(m.size() %2 !=0) cal += m[m.size() - 1]; // 음수가 홀수인 경우 마지막 요소(가장 작은 값을 더한다)
    for (int x = 0; x < (int) m.size() - 1; x += 2) cal += m[x] * m[x + 1];

    cout << cal;

    return 0;
}
