/*
정수 n을 입력받은 후
n개의 정수를 입력받습니다.
정수 m을 입력받습니다.
5<n,m<1000000 제한시간 2초
연속된 m개의 구간의 합이 가장 큰 구간은 몇번 인덱스 부터 이며
그 값은 얼마일까요??

 12 5 3 7 4 1 1 5 2 3 4 5 7 1

 입력시
 6 번인덱스 합은 21
 */


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    //슬라이딩 윈도우(?) 뭐시기,,,,,, //다 더하고 max 값 갱신 후 앞에거 하나 빼고 뒤에거 하나 더하고,,, 반복

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for (int x = 0; x < n; x++) cin >> arr[x];

    int sum = 0;
    for (int x = 0; x < m; x++) {
        sum += arr[x];  //최초 m개 구간의 합
    }

    int MAX = sum;
    int MaxIdx = 0;

    for (int x = 0; x < n - m; x++) {
        sum -= arr[x];
        sum += arr[x + m];

        if(sum >MAX) {
            MAX = sum;
            MaxIdx = x+1; //주의!
        }
    }


    cout << "연속된" << m << "개의 구가의 합이 가장 큰 구간은" << MaxIdx << "인덱스 부터 이며, 그 값은 " << MAX << "입니다";

    return 0;
}