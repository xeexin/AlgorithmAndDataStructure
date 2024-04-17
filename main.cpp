#include<iostream>
using namespace std;
struct node {
    char ch;
    int num;
};
node arr[6] = {
        {'B',7},
        {'B',6},
        {'A',7},
        {'A',2},
        {'C',5},
        {'C',3},
};
node ret[6];

// 문자 내림 // 숫자 오름
bool compare(node f, node b){
    if(f.ch > b.ch) return 1;
    if(f.ch<b.ch)return 0;
    return f.num < b.num;
}
int main()
{
    for (int x = 0; x < 6; x++) {
        ret[x] = arr[x];
        for (int y = x; y > 0; y--) {
            if(compare(ret[y-1],ret[y])==0) swap(ret[y - 1], ret[y]);
        }
    }

;}