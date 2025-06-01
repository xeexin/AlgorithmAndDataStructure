//
// Created by 임희진 on 5/31/25.
//


/*
 * 서류심사 성적과 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발!
    2  // 테스트 케이스
    5   // 지원자 숫자
   (1) 3 2 // (서류심사, 면접)  *1위부터 n위까지 동석차 없음
   (2) 1 4
   (3) 4 1
   (4) 2 3
   (5) 5 5
    7
    3 6
    7 3
    4 2
    1 4
    5 7
    2 5
    6 1

     선발할 수 있는 신입사원의 최대 인원수를 한 줄에 하나씩 출력한다.
 */

#include "S_1_1946.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t>0){
        int n;
        cin >> n;
        vector<pair<int, int> > v(n);

        for(int x=0; x<n; x++){
            cin >> v[x].first;
            cin >> v[x].second;
        }

        sort(v.begin(), v.end());
        int ret = 1;
        int tmp = 0;
        for(int x=1; x<n; x++){
            if(v[tmp].second > v[x].second){
                ret++;
                tmp=x;
            }
        }
        cout << ret << endl;
        t--;
    }

    return 0;
}
