// 중복 X

#include<iostream>
using namespace std;
char arr[5] = "ABCD";
char path[10];
int visited[4];
void abc(int lev){

    if (lev == 3) {
        cout << path <<endl;
        return;
    }
    for (int x = 0; x < 4; x++) {
        if(visited[x]==1) continue;
        visited[x] = 1;
        path[lev] = arr[x];
        abc(lev + 1);
        path[lev] = 0;
        visited[x] = 0; 
    }

}
int main()
{
    abc(0);

    return 0;
}