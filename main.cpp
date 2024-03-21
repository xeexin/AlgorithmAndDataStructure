// 비트배열 후 맥스 값 출력

#include<iostream>
using namespace std;
int arr[3][4]={
        3,5,6,1,
        2,4,2,5,
        1,2,3,4
};
int bit[2][2] = {
        1, 1,
        1, 0
};
int getSum(int dy, int dx){
    int sum = 0;
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 2; x++) {
            if (bit[y][x] == 1) {
                sum += arr[dy + y][dx + x];
            }
        }
    }
    return sum;
}
int main(){

    int MAX = -21e8;

    for (int y = 0; y <= 3 - 2; y++) {
        for (int x = 0; x <= 4 - 2; x++) {
            int sum = getSum(y, x);
            if(sum > MAX) MAX = sum;
        }
    }

    cout << "최댓값은 " << MAX;

    return 0;
}
