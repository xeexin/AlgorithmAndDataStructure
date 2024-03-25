#include<iostream>
#include<string>
using namespace std;

int findNum(string &arr, int idx){

    for (int x = idx; x < arr.length(); x++) {
        if (arr[x] >= '0' && arr[x] <= '9') return x;
    }

    return -1;
}

int findChar(string &arr, int idx){
    for (int x = idx; x < arr.length(); x++) {
        if (!(arr[x] >= '0' && arr[x] <= '9')) {
            return x;
        }
    }
    return -1;
}
int main(){
    string arr = "ATS47UK53KOR2G";

    int a,b,sum;
    a = 0;
    sum = 0;

    while (1) {
        //숫자 찾기
        a = findNum(arr,a);
        if(a==-1)break;

        //그 다음 문자 찾기
        b = findChar(arr, a + 1);
        if(b==-1)break;

        string ret = arr.substr(a, b - a);
        int ret2 = stoi(ret) + 5;
        sum += ret2;

        a = b + 1;
    }

    cout << sum;

    return 0;
}