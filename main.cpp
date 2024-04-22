/*
문제Q
입력!
정수 n, m 입력 후
n개의 정수를 입력 받은 후
m개의 정수도 입력 받습니다.

문제!
m개의 정수가 n개의 정수 안에 존재하는지 존재여부 출력

9
1 4 2 15 6 3 2 -43 1
5
20 3 4 -22 -43

출력결과
XOOXO*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    //1. 입력
    int n, m;
    cin >> n;
    vector<int>v1(n);
    for (int x = 0; x < n; x++) cin >> v1[x];

    cin >> m;
    vector<int>v2(m);
    for (int x = 0; x < m; x++)cin >> v2[x];


    //2. 정렬
    sort(v1.begin(), v1.end());


    //3. 탐색
    for (int x = 0; x < m; x++)
    {
        int st = 0;
        int ed = v1.size() - 1;
        int flag = 0;

        while (st<=ed)
        {
            int mid = (st + ed) / 2;

            if (v1[mid] == v2[x])
            {
                flag = 1; break;
            }
            if (v1[mid] > v2[x]) ed = mid - 1;
            if (v1[mid] < v2[x]) st = mid + 1;
        }
        if (flag == 1) cout << "O ";
        else cout << "X ";
    }

    return 0;
}