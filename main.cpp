// 백준 10828번
/*

 * */

#include <iostream>
#include<stack>
using namespace std;
int main(){
    int n;
    cin >> n;

    stack<int> s;

    for (int x = 0; x < n; x++) {
        string str;
        cin >> str;

        if (str == "push") {
            int num;
            cin >> num;
            s.push(num);
        }
        if(str=="pop") {
            if (s.empty()) {
                cout << "-1" <<endl;
            } else {
                cout << s.top() << endl;
                s.pop();
            }
        }
        if(str=="size") cout << s.size() << endl;
        if(str== "empty") {
            if(s.empty()) cout << "1" << endl;
            else cout << "0" << endl;
        }
        if(str=="top") {
            if(s.empty()) cout << "-1" << endl;
            else cout << s.top() << endl;
        }
    }
    return 0;
}
