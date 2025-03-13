// 백준 10828번
/*

 * */

#include <iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s[7]; //줄 6개

    int n,p;
    cin >> n >> p;

    int a,b;
    int cnt = 0;

    for (int x = 0; x < n; x++) {
        cin >> a >> b;

        if(!s[a].empty() && s[a].top() > b) { //비어있지 않고 && 누르고 있는 프렛 번호 > 누를 프렛 번호
            while (!s[a].empty() && s[a].top() > b) {
                s[a].pop();
                cnt++;
            }
        }

        if (s[a].empty() || s[a].top() < b) { // 누르고 있는 프렛 번호 < 누를 프렛 번호
            cnt++;
            s[a].push(b);
        }
    }

    cout << cnt;

    return 0;
}
