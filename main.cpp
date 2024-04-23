#include<iostream>
#include<queue>
using namespace std;

struct node {
    string name;
    int length;
};

priority_queue<node>q;

bool operator<(node b, node a)
{
    // 길이 오름차순 정렬
    return a.length < b.length;
}
int main()
{
    q.push({ "kevin",10 });
    q.push({ "jane",2 });
    q.push({ "john",5 });
    q.push({ "amy",2 });
    q.push({ "bob",3 });
    q.push({ "kate",5 });


    while (q.size()!=1) {
        node a = q.top(); // 첫번째로 가장 작은 값
        q.pop();

        node b = q.top(); // 두번째로 가장 작은 값
        q.pop();

        // 두 항목의 이름 중 작은 것을 선택하여 새로운 항목의 이름으로 설정
        string new_name = a.name;
        if (new_name > b.name) new_name = b.name;

        // 새로운 항목 생성 및 우선순위 큐에 삽입
        node neweber = { new_name,a.length + b.length };
        q.push(neweber);
    }
    cout << q.top().name << " " << q.top().length;


    return 0;
}

