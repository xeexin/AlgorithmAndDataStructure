#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
    //1. sort 범위는 맨끝 다음까지 하기

    //2. 배열 아니면 begin(),end()
    vector<int>v = { 2,67,23,32,1,7 };
    sort(v.begin(), v.end());


    string str = "asdf";
    sort(str.begin(), str.end());

    //3. 배열일 경우 : idx, idx+n 하기
    int arr[6]= { 2,67,23,32,1,7 };
    sort(&arr[0], &arr[6]);
    sort(arr, arr + 6);


    string s[3] = { "SBS","KBS","MBC" };
    sort(s, s + 3);

    return 0;
}