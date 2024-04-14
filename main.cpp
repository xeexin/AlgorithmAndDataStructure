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

bool compare(node f, node b){
    //1. 문자 내림차순
    //2. 숫자 오름차순

    if(f.ch > b.ch) return true;
    if (f.ch < b.ch) return false;
    else{
        return f.num < b.num; // 문자가 같다면, 숫자 오름 차순으로 정렬
    }
}
int main()
{
    for (int y = 0; y < 6; y++) {
        ret[y] = arr[y];
        for (int x = y; x > 0; x--) {
            if(compare(ret[x-1], ret[x]) == false) swap(ret[x - 1], ret[x]);
        }
    }


    for (int x = 0; x < 6; x++) {
        cout << ret[x].ch << " " << ret[x].num << endl;
    }

}