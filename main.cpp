// dat
//vect 배열에 arr 값이 몇개씩 있는지 출력하기

#include<iostream>
using namespace std;
int main(){
    int vect[8] = {3, 7, 2, 3, 4, 1, 2, 4};
    int arr[5] = {0, 1, 3, 5, 7};

    int bucket[10] = {0};

    for (int x = 0; x < 8; x++) {
        bucket[vect[x]]++;
    }

    for (int x = 0; x < 5; x++) {
        int idx = arr[x];
        cout << idx << "이(가)" << bucket[idx] << "개 있습니다.\n" ;
    }

    return 0;
}