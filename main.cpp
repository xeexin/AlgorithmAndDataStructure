// dat 2차 배열
// (y,x) 좌표 입력 받고 상하좌우 합 구하기

#include<iostream>
using namespace std;
int main()
{
    int arr[4][4] = {
            4,7,1,8,
            4,9,5,9,
            2,6,1,2,
            1,5,1,3
    };

    // 상, 하, 좌, 우
    int direct[4][2] = {-1, 0,
                        1, 0,
                        0, -1,
                        0, 1};

    //입력
    int y,x;
    cin >> y >> x;

    int sum=0;

    for (int t = 0; t < 4; t++) {
        int dy = y+ direct[t][0];
        int dx = x + direct[t][1];

        if(dy<0 || dy>3 || dx<0 || dx>3) continue;

        sum += arr[dy][dx];
    }

    cout << sum;
}
