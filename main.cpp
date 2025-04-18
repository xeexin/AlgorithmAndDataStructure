// 백준 S_4_1015

/*

A[0]=2=B[P[0]]
A[1]=3=B[P[1]]
A[2]=1=B[P[2]]

B[P[2]]=1=B[0]
B[P[0]]=2=B[1]
B[P[1]]=3=B[2]

P[2]=0
P[0]=1
P[1]=2


p = {1,2,0}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> a;
    for (int x=0; x<n; x++) {
        int num; cin>>num;
        a.push_back(make_pair(num, x)); // {{2,0}, {3,1}, {1,2}}
    }

    sort(a.begin(), a.end());  // {{1,2},{2,0},{3,1}}

    vector<int> p(n);
    for (int x=0; x<n; x++) {
        p[a[x].second] = x; // p[2]=0, p[0]=1, p[1]=2
    }

    for (int x=0; x<n; x++) {
        cout << p[x] << " ";
    }

    return 0;
}
