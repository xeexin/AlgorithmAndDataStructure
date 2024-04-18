/*

그룹이 몇개 존재 할까요?
vector<string>vect = {
        "AE",
        "FE",
        "CE",
        "CA",
        "BD",
        "DB",
};

그룹화 시킨다면!! 그룹화 후,
        만들어진 그룹의 갯수는 무엇일까요?
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
// 다음과 같이 그룹화를 진행 했을 경우 총 몇개의 그룹이 형성될까요?
vector<string>arr = {
        "AE",
        "FE",
        "CE",
        "CA",
        "BD",
        "DB",
};
int vect[300];
char find_boss(char member){
    if(vect[member]==0) return member;
    char result = find_boss(vect[member]);
    vect[member] = result;
    return member;
}

void setUnion(char a, char b){
    vect[find_boss(b)] = find_boss(a);
}
int main()
{
    int ret = 6;

    for (int x = 0; x < arr.size(); x++) {
        if(find_boss(arr[x][0]) != find_boss(arr[x][1])) {
            setUnion(arr[x][0], arr[x][1]);
            ret--;
        }
    }

    cout << ret;
    return 0;
}