#include<iostream>
using namespace std;
int main()
{
// 중간에 abs를 껴 넣어 주세요 abs
    string arr = "asdlkfjabslksdabsjfabslksdj";
// abs 문자열이 몇개 있는지 출력해 주세요~
    string target = "abs";

    int a = 0;
    int cnt = 0;

    while (1) {
        a = arr.find(target, a);
        if(a==-1)break;
        a = a + 1;
        // a += arr.length();
        cnt++;
    }

    cout << cnt;

    return 0;
}