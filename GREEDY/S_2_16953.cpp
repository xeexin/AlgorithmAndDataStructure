//
// Created by 임희진 on 5/30/25.
//

#include "S_2_16953.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
    정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.

    2를 곱한다.
    1을 수의 가장 오른쪽에 추가한다.
    A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b; // 2 162

    int cnt = 0;

    // 2 → 4 → 8 → 81 → 162

    /*
        b부터 거꾸로 계산하기
        끝에 숫자가 1이면  오른쪽에 1 더한 경우
        짝수(2로 나눠짐)면 *2 한 경우
     */


    // 시간 초과....
    // 어떻게 해결할지...

    while (1) {
        cnt++;

        if (b == a) {
            break;
        }else if(b<a){
            cnt = -1;
            break;
        }


        if (b % 10 == 1) {
            b = (b-1)/10;
        }
        else if (b % 2 == 0) {
            b /= 2;
        }
    }
    cout << cnt;

    return 0;

}
