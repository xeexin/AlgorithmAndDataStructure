/*
1. sum 전역 (들어가며 누적합 출력)
*/

#include<iostream>
using namespace std;
int arr[5] = { 4,7,3,6,5 };
int sum = 0;

void abc(int level)
{
    if(level==5) return;

    sum += arr[level];
    cout << sum << endl;
    abc(level + 1);
}
int main()
{

    abc(0);


    return 0;
}