#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int arr[8] = { 4,7,1,8,5,3,4,2 };

int main()
{   // 구조체 랑 vector 를 이용하서 만든 stl
    // max heap 디폴트...

    priority_queue<int, vector<int>, greater<int>> pq; //기본 값: 내림차순 -> greater<int> : 오름차순으로

    for (int x = 0; x < 8; x++) {
        pq.push(arr[x]);
    }

    for (int x = 0; x < 8; x++) {
        cout << pq.top() << " ";
        pq.pop();
    }


    return 0;
}