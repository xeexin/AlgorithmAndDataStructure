#include<iostream>
#include<cstdlib>
using namespace std;

int power[7] = { 90,20,36,48,80,60,70 };
int MIN = 21e8;
char path[10];
char check[10];
int visited[10];

void dfs(int lev, int sum){
    int against = 0; // 속하지 않은 팀의 합
    for (int x = 0; x < 7; x++) {
        if (visited[x] == 0) {
            against += power[x];
        }
    }

    int gap = abs(sum - against);
    if (gap < MIN) {
        MIN = gap;
        memcpy(check, path, sizeof(path));  // check에 복사...
    }

    if(lev==5) return; //team이니까 최소 두명이상이 팀이라고 가정하고 리턴 조건

    for (int x = 0; x < 7; x++) {
        if(lev>0 && path[lev-1] >= char ('a'+x)) continue; // 중복 조합 방지

        path[lev] = 'a' + x;
        visited[x] = 1;
        dfs(lev + 1, sum + power[x]);
        visited[x] = 0;
        path[lev] = 0;

    }
}
int main(){

    dfs(0, 0);
    cout << MIN << endl;
    cout << check ;

    return 0;
}