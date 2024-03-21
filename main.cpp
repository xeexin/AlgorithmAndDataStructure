// 2차원 배열의 패턴 찾기


#include<iostream>
using namespace std;

char arr[5][5];
char input[2][2];

void init() {
    //arr 함수 초기화
    char val = 'A';
    for (int y = 0; y < 5; y++) {
        for (int x = 4; x >= 0; x--) {
            arr[y][x] = val++;
        }
    }

    //input 배열 입력 받기
    for (int y = 0; y < 2; y++)
        for (int x = 0; x < 2; x++) {
            cin >> input[y][x];
        }
}

int isPattern(int dy, int dx) {

    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 2; x++) {
            if (arr[dy + y][dx + x] != input[y][x]) {
                return 0;
            }
        }
    }
    return 1;

}
int main(){

    //초기화
    init();

    for (int y = 0; y <= 5-2; y++) {
        for (int x = 0; x <= 5-2; x++) {
            int ret = isPattern(y, x);
            if (ret == 1) {
                cout << "인덱스의 위치는 " << y << "," << x;
                return 0;
            }
        }
    }

    cout << "NOT FOUND";
    return 0;
}