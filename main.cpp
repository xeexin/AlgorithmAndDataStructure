#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int arr[8] = { 4,7,1,8,5,3,4,2 };

int main()
{
    // queue FIFO
    queue<int>q;
    for (int x = 0; x < 8; x++)
    {
        q.push(arr[x]);
    }
    for (int x = 0; x < 8; x++)
    {
        cout<<q.front();   //    47185342
        q.pop();
    }
    cout << endl;
    stack<int>st;
    for (int x = 0; x < 8; x++)
    {
        st.push(arr[x]);
    }
    for (int x = 0; x < 8; x++)
    {
        cout << st.top();   //    24835741
        st.pop();
    }
    cout << endl;
    vector<int>vect;
    for (int x = 0; x < 8; x++)
    {
        vect.push_back(arr[x]);
    }
    for (int x = 0; x < 8; x++)
    {
        cout << vect.back();    //    24785341
        vect.pop_back();
    }
    cout << endl;
    priority_queue<int, vector<int>>pq; // maxheap

    for (int x = 0; x < 8; x++)
    {
        pq.push(arr[x]);
    }
    for (int x = 0; x < 8; x++)
    {
        cout << pq.top();   //    87431257
        pq.pop();
    }


    
    return 0;
}