//n 입력후 , n개의 정수 입력 받기
// ex) 4 9 3 2 7
//각 숫자에 3을 곱하거나 2로 나누거나 5를 빼서 숫자를 만든다
//만들어진 4개의 숫자의 곱이 max일 때의 값 구하기

#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> vect;
int MAX = -21e8;
int calcul[3] = {3, 2, -5};

void dfs(int lev, int sum){
    if (lev == n) {
        if (MAX < sum) {
            MAX = sum;
        }
        return;
    }

    for (int t = 0; t < 3; t++) {
        if(t==0) dfs(lev + 1, sum * vect[lev] * calcul[0]);
        if(t==1) dfs(lev + 1, sum * vect[lev] / calcul[1]);
        if(t==2) dfs(lev + 1, sum * vect[lev] + calcul[2]);
    }

}
int main(){

    cin >> n;
    for (int x = 0; x < n; x++) {
        int t;
        cin >> t;
        vect.push_back(t);
    }

    dfs(0, 1);

    cout << MAX;
    return 0;
}