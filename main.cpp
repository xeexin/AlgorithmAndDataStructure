//특정한 합을 가지는 부분 배열의 개수
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    //입력
    // n:배열의 갯수, m:타겟
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int x = 0; x < n; x++) cin >> v[x];


    int st = 0, ed = 0, sum = 0, cnt = 0;
    int target = m;

    while (1) {

        if(sum >= target) sum -= v[st++]; // 목표 값 보다 커진다면, start 인덱스 값 빼주기
        else if(ed == n) break; // 목표 값 보다 작은데, ed 인덱스가 끝까지 왔다면 종료
        else sum += v[ed++]; // 목표 값 보다 작다면, ed idx 값 더해주기
        if(sum==target) cnt++; // 같다면 카운트 쁠쁠
    }

    cout << cnt;

    return 0;
}