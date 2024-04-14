//tong 에 하나씩 넣을 때, 겹치면 pop_back()해주기 문제
/*
 정수 n입력 후
 n개의 정수를 입력받는다.

 tong 안에 숫자를 담는데..
 앞뒤로 같은 숫자가 들어오면 숫자 두개는 사라진다.

 tong 안에 남는 숫자는 무엇이 있을까?

 10
 4 4 7 8 1 6 6 1 8 1

 입력시
 출력은 7 하고 1 이 됩니다.

*/


#include<iostream>
#include <vector>
using namespace std;
int main(){

    int n;
    cin >> n;

    vector<int> tong;

    for (int x = 0; x < n; x++) {
        int i;
        cin >> i;

        tong.push_back(i);

        int s = tong.size();
        if(s < 2) continue; // 사이즈가 둘 이상일 때 로직 실행됨
        if (tong[s - 1] == tong[s - 2]) { //최근 들어온 자신과 그 전에 것이 같은지 비교
            tong.pop_back();
            tong.pop_back();
        }
    }

    //출력
    for (int x = 0; x < tong.size(); x++) {
        cout << tong[x] << " ";
    }

    return 0;
}