#include<iostream>
#include<string>
using namespace std;
int MIN = 21e8;
string str = "TSMC";
string target ="TCMS";

void rspin(){
    int temp = str[3];
    for (int x = 3; x > 0; x--) {
        str[x] = str[x - 1];
    }
    str[0] = temp;
}
void lspin(){
    int temp = str[0];
    for (int x = 0; x < 3; x++) {
        str[x] = str[x + 1];
    }
    str[3] = temp;
}

void tover() {
    char temp[4];
    for (int y = 0; y < 4; y++) {
        temp[3 - y] = str[y];
    }
    for (int x = 0; x < 4; x++) str[x] = temp[x];
}

void dfs(int lev){
    if (str == target) {
        if (MIN > lev) {
            MIN = lev;
            return;
        }
    }

    if(lev==5) return; //종료조건

    rspin();
    dfs(lev + 1);
    lspin(); //원상복구

    lspin();
    dfs(lev + 1);
    rspin(); //원상복구

    tover();
    dfs(lev+1);
    tover(); //원상복구
}
int main(){
    dfs(0);
    cout << MIN;
    return 0;
}