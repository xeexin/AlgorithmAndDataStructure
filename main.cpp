#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char arr[5] = "asdf";
    char vect[5];
    //strcpy(vect, arr);  문자열
    memcpy(vect, arr, sizeof(arr)); //메모리 블록을 복사합니다. 문자열이나 다른 데이터 형식을 모두 복사할 수 있습니다.

    return 0;
}