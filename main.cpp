// 백준 10799번
/*
 * ( -> 스택에 쌓기
 * () -> ( 개수만큼 늘어남
 * ) -> 팝 후 개수 하나 늘리기
 * */

#include <iostream>
#include<stack>
using namespace std;
int main(){

    string str;
    cin >> str;

    int cnt = 0;
    stack<int> s;

    for (int x = 0; x < str.size(); x++) {
        if (str[x] == '(' && str[x + 1] == ')') {
            cnt += s.size();
            x++;
        }
        else if(str[x]=='(') s.push(str[x]);
        else if (str[x]==')') {
            s.pop();
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
