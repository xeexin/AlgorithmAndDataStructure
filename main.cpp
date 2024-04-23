#include<iostream>
#include<queue> // queue  priority queue
using namespace std;

int arr[5] = { 3,65,23,2,1 };
struct cmp{
    bool operator()(int b, int f){
        // 짝수 우선
        // 내림 차순
        if(f%2==0 && b%2==1) return 1;
        if(f%2==1 && b%2==0) return 0;
        return f > b;
    }
};

int main()
{

    priority_queue<int, vector<int>, cmp> pq;


    for (int x = 0; x < 5; x++)
    {
        pq.push(arr[x]);
    }

    for (int x = 0; x < 5; x++)
    {
        cout << pq.top()<<" ";
        pq.pop();
    }




}