// dat
//brr 배열에 있는 문자가 arr에 몇개 있는지 출력

#include<iostream>
using namespace std;
int main()
{

    char arr[10] = "NCT127";
    char brr[20] = "NCT127BTSRIZE";
    char bucket[200] = {0};

    //brr 배열 길이 구하기
    int len;
    for (int x = 0; x < 20; x++) {
        if (brr[x] == NULL) {
            len=x;
            break;
        }
    }

    for (int x = 0; x < len; x++) {
        bucket[brr[x]]++;
    }

    int cnt = 0;
    for (int x = 0; x < 6; x++) {
        if (bucket[arr[x]] > 0) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
