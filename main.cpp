/*
JAN[HEY]AKT[HA]BTS[WOW]KT 입력
[ ]안에 있는 값 출력
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string arr = "JAN[HEY]AKT[HA]BTS[WOW]KT";

    int a = 0;
    int b;

    while (1) {

        a = arr.find("[", a);
        if(a==-1) break;

        b = arr.find("]", a + 1);
        cout << arr.substr(a + 1, b - a - 1) << endl;
        a = b + 1;
    }

    return 0;
}