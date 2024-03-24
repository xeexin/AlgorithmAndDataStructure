/*
"JAN[[HEY]A[K]]T[HA]]BTS[[W]KT"
[[ 열리는 대괄호가 2개 이상일 때 안에 파싱
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string arr = "JAN[[HEY]A[K]]T[HA]]BTS[[W]KT";

    int a = 0;
    int b;

    while (1) {
        a = arr.find("[", a);
        if(a==-1) break;
        b = arr.find("]", a + 1);
        if(b==-1)break;

        while (1) {
            int c= arr.find("[", a + 1);
            if(c<b) {
                a = c;
                cout << arr.substr(a + 1, b - a - 1) << endl;
                a = b + 1;
            }
            else break;
        }
        a = b + 1;
    }


    return 0;
}

