#include<iostream>
#include<algorithm>
using namespace std;

// h~o 우선
// 오름차순
bool compare(char f, char b) {
    int aa = 0;
    int bb = 0;

    if(f>='h' && f <='o') aa = 1;
    if(b>='h' && b<='o') bb = 1;

    if(aa==1 && bb==0) return 1;
    if(aa=0 && bb== 1) return 0;
    return f < b;
};
int main()
{
    char arr[10] = "btsgood";

    sort(arr, arr + 7, compare);

    cout << arr;
    return 0;
}