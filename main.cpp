// dat 2차 배열
// (y,x) 좌표 입력 받고 상하좌우+본인의 값이 가장 큰 좌표 값 구하기

#include<iostream>
using namespace std;
int arr[4][4] = {
        4,7,1,8,
        4,9,5,9,
        2,6,1,2,
        1,5,1,3
};

int getSum(int yy, int xx){
    int sum =0;

    //자신, 상, 하, 좌, 우
    int direct[5][2] = {0, 0,
                        -1, 0,
                        1, 0,
                        0, -1,
                        0, 1};


    for (int t = 0; t < 5; t++) {
        int dy = yy + direct[t][0];
        int dx = xx + direct[t][1];

        if(dy <0 || dy > 3 || dx <0 || dx >3  )continue;

        sum += arr[dy][dx];
    }

    return sum;
    
}
int main()
{
    int Max = 0;
    int Maxy, Maxx;

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            int sum = getSum(y, x);
            if (sum > Max) {
                Max = sum;
                Maxy = y;
                Maxx = x;
            }
        }
    }

    cout << "최댓값은 " << Max << ". 좌표는 (" << Maxy << "," << Maxx << ") 입니다.";
    
    
    return 0;
}
