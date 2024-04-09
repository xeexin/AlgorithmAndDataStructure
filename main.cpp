#include<iostream>
using namespace std;
// 연속된 m개의 숫자의 합이 최대일 때의 Max값은?
int main()
{
    int arr[11] = { 4,2,1,2,2,1,3,4,0,2,3 };


    int n = 11;
    int m = 4;
    int sum = 0;

    for (int x = 0; x < 4; x++) {
        sum += arr[x];
    }

    int MAX = sum;

    for (int x = 0; x < n - m; x++) {
        if(MAX < sum) MAX = sum;

        sum += arr[x + m];
        sum -= arr[x];
    }

    cout << MAX;

    return 0;


    return 0;
}