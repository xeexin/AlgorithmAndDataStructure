#include<iostream>
#include <queue>
using namespace std;
int arr[6] = { 5,4,2,7,6,3 };
struct node {
    int a;
};
bool operator<(node b, node a){
    if (a.a % 2 == 0 && b.a % 2 == 1)return true;
    if (a.a % 2 == 1 && b.a % 2 == 0) return false;
    return a.a > b.a;
}
// 짝수 우선, 내림차순
int main(){

    node b[6];

    for (int x = 0; x < 6; x++) {
        b[x].a = arr[x];
    }

    priority_queue<node>q;

    for (int x = 0; x < 6; x++) {
        q.push(b[x]);
    }

    for (int x = 0; x < 6; x++) {
        cout << q.top().a << " ";
        q.pop();
    }

    return 0;
}
