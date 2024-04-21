#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int arr[8] = { 4,7,1,8,5,3,4,2 };
struct compare {
    bool operator()(int b, int f)
    {
        return f < b; //내림차순
    }
};
int main()
{
    priority_queue<int, vector<int>,compare>pq;
    for (int x = 0; x < 8; x++)
    {
        pq.push(arr[x]);
    }
    for (int x = 0; x < 8; x++)
    {
        cout<<pq.top() << " ";
        pq.pop();
    }


    return 0;
}