/*
문제풀기 333 !!!~
양방향 그래프의
노드 갯수와 관계를 입력받으세요.
그 다음 그래프에는 cycle이 존재 할까요 ?

4
A B
B E
C B
A E

발견

3
A B
C D
A D

미발견 출력*/

#include<iostream>
#include<vector>
using namespace std;
int arr[200];
char findBoss(char member){
    if(arr[member]==0) return member;

    char ret = findBoss(arr[member]);
    return ret;
}
void setUnion(char a, char b){
    if(findBoss(a)== findBoss(b)) return;
    arr[findBoss(b)] = findBoss(a);
}
int main()
{
    int n;
    cin >> n;

    pair<char, char> p1;
    vector<pair<char,char>> vector;

    for (int x = 0; x < n; x++) {
        cin >> p1.first >> p1.second;
        vector.push_back(p1);
    }

    for(int x=0; x<n; x++){
        if(findBoss(vector[x].first) != findBoss(vector[x].second)) { //보스가 같지 않다면
            //묶어 주기
            setUnion(vector[x].first, vector[x].second);
        } else {
            cout << "cycle 존재";
            return 0;
        }
    }
    cout << "cycle 미존재";
    return 0;
}