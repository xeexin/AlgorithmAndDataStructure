#include<iostream>
using namespace std;
int arr[200];

char findBoss(char a){
    if(arr[a]==0) return a;

    char ret = findBoss(arr[a]);
    return ret;
}
void setunion(char a, char b){
    char aa = findBoss(a);
    char bb = findBoss(b);
    if(aa==bb)return;
    arr[bb] = aa;
}
int main() {

    setunion('a', 'b');
    setunion('d', 'e');
    setunion('b', 'e');
    setunion('a', 'e');
    setunion('c', 'f');

    return 0;
}
