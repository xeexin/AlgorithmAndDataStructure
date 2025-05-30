//
// Created by kosa on 25. 5. 30.
//

#include "S_2_1541.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str; //55-50+40  -> 55-(50+40)

    /*
        1. - 뒤에 +가 올 경우 ()로 묶기
        2. -뒤에 -가 오면 묶지 않기
        3. - + - 가 오면 - 이후에 다음 -나오기 전까지 괄호로 묶기
        4. + - 가 오면 -가 나오기 전까지는 그냥 계산 (괄호 필요 없음)
        5. -만 나오는 경우
        6. +만 나오는 경우

        * -가 있는지 확인
        * 있다면
        ** -는 그냥 빼고, -뒤에 나오는 +도 빼면 된다.
        * 처음 등장하는 - 앞에 +가 있는지 확인!
        *
        *없다면 다 더하기
     */

    int ret = 0;
    bool isMinus = false;
    string num = "";

    for (int x = 0; x <= str.length(); x++) {
        // 부호를 만나거나 문자열 끝까지 간 경우
        if (str[x] == '-' || str[x] == '+' || x == str.length()) {
            // minus를 만난 직후라면
            if (isMinus) {
                ret -= stoi(num);
                num = "";
            } else if (isMinus == false) {
                ret += stoi(num);
                num = "";
            }
        }
        // 숫자일 경우
        else {
            num += str[x];
        }
        // Minus 만날 경우 true로 바꿔주기
        if (str[x] == '-') isMinus = true;
    }


    cout << ret;

    return 0;
}
