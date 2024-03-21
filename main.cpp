// 1차원 배열의 패턴 찾기

//JTBCROKYCD

#include<iostream>
using namespace std;

char vect[10] = "KBSMBCSBS";
char arr[3];

int isPattern(int idx) {

    for (int x = 0; x < 3; x++) {
        if (vect[x + idx] != arr[x]) {
            return 0; //한글자라도 다르면 즉시 종료
        }
        return 1; //찾으면 1
    }
}
int main() {

    //입력
    cin >> arr;

    for (int x = 0; x <= 9 - 3; x++) {
        int ret = isPattern(x);
        if (ret == 1){
            cout << "Pattern Found";
            return 0;//패턴 있으면 즉시 종료
        }
    }

    cout << "Pattern Not Found";

    return 0;
}