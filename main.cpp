// 문자(열) 입력 받고, 존재하는지 확인하기

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string arr[3] = {
            "blackpink",
            "nct",
            "aespa"
    };

    string input;
    cin >> input;

    int flag = 0;

    for (int x = 0; x < 3; x++) {
        if (arr[x].find(input, 0) != -1) {
            flag = 1;
            break;
        }
    }

    if(flag) cout << "FOUND";
    else cout << "NOT FOUND";

    return 0;
}