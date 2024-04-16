/*8. 문제
        숫자 하나 입력받고 입력받은 숫자만큼 숫자를 입력받기  ( n번 푸쉬백 또는  (n) 하기)
그다음 입력받은 숫자들의 합출력

3
1 2 4

출력결과: 7*/
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    int cnt = 0;

    for (int x = 0; x < n; x++) {
        int k;
        cin >> k;
        v.push_back(k);
    }
    for (int x = 0; x < v.size(); x++) {
        cnt += v[x];
    }
    cout << cnt;

    return 0;
}

