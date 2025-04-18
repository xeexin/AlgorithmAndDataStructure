// 백준 S_4_10825

/*
    N명의 이름과 국어, 영어, 수학 점수

    국어 점수가 감소하는 순서로
    국어 점수가 같으면 영어 점수가 증가하는 순서로
    국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
    모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    string name;
    int kor;
    int eng;
    int math;
};
bool cmp(node a, node b) {
   //  국어 점수 내림차순
    if (a.kor != b.kor) { return a.kor > b.kor; }
   // 국어 같으면 영어 점수 오름차순
    if (a.eng != b.eng) { return a.eng < b.eng; }
   // 국어와 영어 같으면 수학 점수 내림차순
    if (a.math != b.math) { return a.math > b.math; }
   // 모두 같으면 이름 사전순 오름차순 (대문자 < 소문자, 아스키 순)
    return a.name < b.name;
}
int main() {
    int n;
    cin >> n;
    vector<node> v(n);
    for (int x=0; x<n; x++) {
        cin >> v[x].name;
        cin >> v[x].kor;
        cin >> v[x].eng;
        cin >> v[x].math;
    }

    //정렬 후 이름 출력
    sort(v.begin(), v.end(), cmp);

    for (int x=0; x<n; x++) {
        cout << v[x].name << "\n";  // endl 대신 -> "\n" 사용하기! (속도 문제)
    }

    return 0;
}
