// 백준 G_5_1759

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int l, c; //
vector<char> v;
vector<char> ret;

//최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성됨
bool check() {
    int mo=0;
    for (int x=0; x<l;x++) {
        if (ret[x] == 'a' || ret[x] == 'e' || ret[x] == 'i' || ret[x] == 'o'|| ret[x] == 'u') {mo++;}
    }

    if (mo >=1 && l-mo >=2) return true;
    else return false;

}
void dfs( int st) {

    if (ret.size()==l) {
        if (check()) {
            for (int x=0; x<l; x++) {
                cout<<ret[x];
            }
            cout<<endl;
        }
        return;
    }

    for (int x=st; x<c; x++) {
        ret.push_back(v[x]);
        dfs( x+1);
        ret.pop_back();
    }
}
int main() {
    cin >> l >> c;

    for (int x=0; x<c; x++) {
        char ch;
        cin>>ch;
        v.push_back(ch);
    }

    //정렬
    sort(v.begin(),v.end());

    dfs(0);
    return 0;
}
