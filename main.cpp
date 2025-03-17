//백준 2606번
#include<iostream>
#include<queue>
using namespace std;
int map[101][101];
int visited[101];
int cnt;
int main(){

    int n,m;
    cin >> n >> m;

    for (int x = 0; x < m; x++) {
        int a,b;
        cin >> a >> b;
        map[a][b]=1;
        map[b][a] = 1;
    }

    visited[1] = 1;
    queue<int>q;
    q.push(1);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int x = 1; x <= n; x++) {
            if(visited[x]== 1) continue;
            if(map[now][x]==1) {
                q.push(x);
                visited[x] = 1;
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}