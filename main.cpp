#include <iostream>
#include <string>
using namespace std;
char arr[4] = "012";
char path[10];
int n, cnt;

void dfs(int lev){
    if(path[0]=='0') return;

    if (lev == n) {
        int num = stoi(path);
        if (num % 3 == 0) {
            cnt++;
        }
        return;
    }

    for (int x = 0; x < 3; x++) {
        path[lev] = arr[x];
        dfs(lev + 1);
    }
}
int main() {
    cin >> n;

    dfs(0);
    cout << cnt;

}