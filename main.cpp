/*
9. 문제

3
    abcd
    btskbs
    pd

숫자하나 입력받고 vector에 입력받은 숫자 개수 만큼 문자열 입력받기
입력받은 후 가장 긴 문자열 출력!

*/

#include <iostream>
#include<vector>
using namespace std;
int main(){

    int n;
    cin >> n;
    vector<string> str(n);
    int MAX = 0;
    int maxIdx = 0;

    for (int x = 0; x < n; x++) {
        cin >> str[x];
    }
    for (int x = 0; x < n; x++) {
        if (str[x].length() > MAX) {
            MAX = str[x].length();
            maxIdx = x;
        }
    }

    cout << str[maxIdx];


    return 0;
}