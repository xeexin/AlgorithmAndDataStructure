// 백준 1780

#include<iostream>
using namespace std;
int cnt_1, cnt0, cnt1;
int arr[2200][2200];
bool issame(int yy, int xx, int n){
    int target = arr[yy][xx];
    for (int y = yy; y < yy + n; y++) {
        for (int x = xx; x < xx + n; x++) {
            if (target != arr[y][x]) {
                return false;
            }
        }
    }
    return true;
}
void div(int yy, int xx, int n) {
    if (issame(yy, xx, n)) {
        if (arr[yy][xx] == -1) cnt_1++;
        if (arr[yy][xx] == 0) cnt0++;
        if (arr[yy][xx] == 1) cnt1++;
    }else{
        int volume = n / 3;
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                div(volume * y+yy, volume * x+xx, volume);
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> arr[y][x];
        }
    }

    div(0, 0, n);
    cout << cnt_1 << endl << cnt0 << endl << cnt1;
    return 0;
}