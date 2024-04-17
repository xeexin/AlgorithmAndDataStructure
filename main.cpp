//  우선순위조건
//	1. 숫자 내림차순
//	2. 문자가 오름차순
#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

struct abc{
char ch;
int num;
};

abc arr[4] = {
        {'A',1},
        {'B',2},
        {'B',1},
        {'A',9},
};
abc ret[4];

int compare(abc f, abc b){
    if(f.num > b.num ) return 1;
    if(f.num < b.num) return 0;
    return f.ch < b.ch;
}
int main(){

    for (int y = 0; y < 4; y++) {
        ret[y] = arr[y];
        for (int x = y; x > 0; x--) {
            if(compare(ret[x-1], ret[x])==0) swap(ret[x-1], ret[x]);
        }
    }

    for (int x = 0; x < 4; x++) {
        cout << ret[x].ch << " " << ret[x].num << endl;
    }

    return 0;
}