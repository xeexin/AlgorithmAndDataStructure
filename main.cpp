//백준 1260번
#include<iostream>
#include<queue>
using namespace std;
int map[1001][1001];
int visited[1001];
int n,m,v;
void reset(){
    for (int x = 1; x <= n; x++)  visited[x] = 0;
}
void dfs(int v){
    visited[v]=1;
    cout << v << " ";

    for (int x = 1; x <= n; x++) {
        if(visited[x]==0 && map[v][x]==1) dfs(x);
        if(x==n) return;
    }

}
void bfs(int v){
    queue<int>q;
    q.push(v);
    visited[v] = 1;

    while (!q.empty()) {
        int now = q.front();
        cout << now << " ";
        q.pop();

        for (int x = 1; x <= n; x++) {
            if(map[now][x]==1 && visited[x]==0) {
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}

int main(){
    cin >> n >> m >> v;

    for (int x = 0; x < m; x++) {
        int a,b;
        cin >> a >> b;

        map[a][b] = 1;
        map[b][a] = 1;
    }

    dfs(v);
    cout << "\n";
    reset();
    bfs(v);


    return 0;
}