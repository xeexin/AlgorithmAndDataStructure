// 백준 S_1_1629

#include <iostream>
using namespace std;
long long a,b,c;
long long rec(long long b){

    if(b==0) return 1;
    if(b==1) return a % c;

    long long k;
    k = rec(b / 2) % c; // b를 반으로 나눈 결과를 k에 저장
    if(b%2==0) return k * k % c; //짝수
    else return (k * k % c) * (a % c);   //홀수

}
int main(){

    cin >> a >> b >> c;

    cout << rec(b) % c;

    return 0;
}