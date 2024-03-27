//이진트리 : 일차배열 path 출력
#include<iostream>
using namespace std;
char arr[10] = " ABC  DE"; //이진트리 1차 배열
char path[10];

void dfs(int now, int lev){
    //종료 조건
    if (now >= 10)return; //배열 길이 초과
    if (arr[now] == ' ' || arr[now] == '\0') return; // 공백이거나 널 일경우

    path[lev + 1] = arr[now * 2];
    dfs(now * 2, lev + 1);

    path[lev + 1] = arr[now * 2 + 1];
    dfs(now * 2 + 1, lev + 1);

    path[lev + 1] = 0;

}
int main()
{
    path[0] = arr[1]; // 'A'
    dfs(1, 0);
    return 0;
}