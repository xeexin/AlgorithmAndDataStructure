// 백준 13549

#include<iostream>
#include<queue>
using namespace std;
int main(){

    int n,k;
    cin >> n >> k;

    int visited[100001] = {0};
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> >pq; // 0초를 고려하여 우선순위 큐에 넣음, 오름차순으로 정렬


    pq.push(make_pair(0, n)); //시간 오름차순으로 큐에 넣어야함으로 first는 시간이 들어가야함

    while (!pq.empty()) {
        int t = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        visited[idx] = 1;

        if (idx == k) {
            cout << t;
            break;
        }

        if(idx-1 >=0 && visited[idx-1]==0) pq.push(make_pair(t + 1, idx - 1));
        if (idx + 1 <= 100000 && visited[idx + 1] == 0) pq.push(make_pair(t + 1, idx + 1));
        if (idx * 2 <= 100000 && visited[idx * 2] == 0) pq.push(make_pair(t, idx * 2));
    }


    return 0;
}