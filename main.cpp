//
//4 7 5 5 1 9 7 하드코딩 후
//4 또는 5또는 9가 등장 할때 마다 result 배열에 값 넣고 출력하기
//출력 결과는 4 5 5 9 */

#include<iostream>
#include <vector>

using namespace std;
int main(){
    vector<int> v = {4, 7, 5, 5, 1, 9, 7};
    vector<int> ret;

    for (int x = 0; x < v.size(); x++) {
        if (v[x] == 4 || v[x] == 5 || v[x] == 9) {
            ret.push_back(v[x]);
        }
    }

    for (int x = 0; x < ret.size(); x++) {
        cout << ret[x] << " ";
    }


    return 0;
}