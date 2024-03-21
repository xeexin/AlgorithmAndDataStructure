// 몇층에 있나요?

#include<iostream>
using namespace std;
int arr[9][3]={
        3,5,1,
        2,3,6,
        3,6,1,
        3,1,1,
        4,5,6,
        2,4,5,
        7,3,4,
        5,7,2,
        8,6,4
};

int find(int idx, int target[3]) {
    for (int x = 0; x < 3; x++) {
        if (arr[idx][x] != target[x]) {
            return 0;
        }
    }
    return 1;
    
}
int main(){

    int target[3] = {3, 6, 1};

    for (int x = 0; x < 9; x++) {
        int ret = find(x, target);
        if (ret == 1) {
            cout << 9 - x << "층에 거주 중 ";
        }
    }

    return 0;
}
