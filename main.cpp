// T가 1등으로 내정되어 있다. 1~3등의 모든 가능한 경우의 수를 구하여라
#include<iostream>
#include<string>
using namespace std;
char arr[6] = "ATKBG";
char path[10];
int used[10];

void dfs(int lev){

    if(lev==3) {
        cout << path << endl;
        return;
    }

    for (int x = 0; x < 5; x++) {
        if (used[x] == 0) {
            if(lev >0 && path[0]!='T') continue;
            used[x] = 1;
            path[lev] = arr[x];
            dfs(lev + 1);
            used[x] = 0;
            path[lev] = 0;
        }
    }
}
int main(){
    dfs(0);
    return 0;
}