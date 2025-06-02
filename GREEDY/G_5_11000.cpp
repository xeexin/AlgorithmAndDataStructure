//
// Created by 임희진 on 6/2/25.
//

#include "G_5_11000.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;  // 3

    vector<pair<int,int> > v(n);
    for(int x=0; x<n; x++){
        cin >> v[x].first >> v[x].second;
    }

    sort(v.begin(),v.end()); // 시작시간 오름차순
    priority_queue<int, vector<int>, greater<int> > pq; // MIN HEAP

    pq.push(v[0].second);

    for(int x=1; x<n; x++){
        if(pq.top() <= v[x].first){
            pq.pop();
        }
        pq.push(v[x].second);
    }

    cout << pq.size();

    return 0;
}
