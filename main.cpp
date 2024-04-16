#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int f, int b) {
    // 1. 짝수 우선
    // 2. 오름 차순  다중조건 sort
    if(f%2==0 && b%2==1) return 1; //앞이 짝수, 뒤에 홀수 -> 1
    if(f%2==1 && b%2==0) return 0; //앞이 홀수, 뒤에 짝수 -> 0
    return f < b; // 같은 값이면 오름차순
};
int main()
{
    int arr[5] = { 3,6,12,3,1 };

    sort(arr, arr + 5); //오름차순 정렬
    sort(arr, arr + 5, greater<int>()); //내림차순 정렬


    sort(arr, arr + 5, compare);


    return 0;
}