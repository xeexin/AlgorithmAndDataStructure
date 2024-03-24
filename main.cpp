/*문자를 숫자로 바꾸기
        숫자를 문자로 바꾸기*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
    //문자 1234를 정수 1234로 바꾸기
    string arr = "1234";
    int t = stoi(arr);
    cout << t + 10 << endl;


    //정수 1234를 문자 1234로 바꾸기
    t = 124142312;
    string  str= to_string(t);
    cout << str;
    return 0;
}