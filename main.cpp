/* 하드코딩 : "AKT[HAHA]GTX"
        HAHA만 출력하기*/

#include<iostream>
#include<string>

using namespace std;
int main(){
    string str = "ATK[HAHA]GTX";

    int idx1 = str.find("[", 0);
    int idx2 = str.find("]", idx1 + 1);

    string ret = str.substr(idx1 + 1, idx2 - idx1 - 1);

    cout << ret;

    return 0;
}
