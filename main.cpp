// 백준 S_4_1920

/*
존재하면 1을, 존재하지 않으면 0을 출력

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> v1;
void binary_search(int target) {
    int st = 0;
    int ed = n-1;
    int mid;

    while (st <= ed) {
        mid= (st+ed)/2;

        if (v1[mid] == target) {
            cout << 1 << "\n";
            return;
        }else if (v1[mid] > target) {
            ed = mid - 1;
        }else {
            st = mid + 1;
        }
    }
    cout << 0 << "\n";
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >>n; //5
    int k;
    for(int x=0;x<n;x++) {
        cin >> k;
        v1.push_back(k); //4 1 5 2 3
    }

    //정렬
    sort(v1.begin(),v1.end()); // 1 2 3 4 5

    cin>>m; //5
    int target;
    for (int x=0; x<m; x++) {
        cin >> target;
        binary_search(target);
    }

    return 0;
}
