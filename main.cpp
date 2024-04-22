/*
[HEAP]

-항상 완벽한 이진트리가 유지됨

-heap sort
1)MAX heap //내림차순 //부모노드가 자식노드보다 커야함!!
2)MIN heap // 오름차순 

출력 시 루트노드 출력 동시에 없애기 -> 트리의 맨 뒤 루트로 옮기고 -> 규칙 적용(자식 노드 중 큰 것으로)  -> 반복
*/

#include<iostream>
using namespace std;
int arr[8] = { 3,4,7,1,2,76,5,8 };
int heap[100];
int hcnt = 0; // heap배열의 인덱스
void insert(int value)
{
    heap[++hcnt] = value; // 트리의 뒤에 값 넣어주기
    int now = hcnt;
    while (1)
    {
        int p = now / 2; // 부모 인덱스 찾기
        if (p == 0)break;
        if (heap[p] > heap[now])break; // 부모랑 비교해서 부모가 더 크면 break
        else swap(heap[p], heap[now]); // 그게 아니면 swap 해서 (!! 항상 부모가 자식보다 크게 유지 !!)
        now = p;  // 위로 올라가면서 부모랑 비교!!
    }


}
int top()
{
    return heap[1];
}
void pop()
{
    heap[1] = heap[hcnt];  // 맨 뒤의 값 루트노드로 옮기기
    heap[hcnt--] = 0; // 올린 맨 뒤의 값을 삭제..
    int now = 1;
    while (1)
    {
        int son = now * 2;
        int rson = son + 1;  // now*2+1;
        if (heap[rson] != 0 && heap[rson] > heap[son])son = rson;  // 오른쪽 자식이 있고 그리고 오>왼 자식은 오른쪽 아이로 한다.
        if (heap[now] > heap[son])break; // now 랑 자식이랑 비교후 스왑
        else swap(heap[now], heap[son]);
        now = son;
    }
}
int main()
{
    for (int x = 0; x < 8; x++)
    {
        insert(arr[x]); // 트리모양으로 저장
    }


    for (int x = 0; x < 8; x++)
    {
        cout << top()<<" "; // 루트노드 리턴 (top)
        pop();        // 출력후 맨 뒤에 있는값 맨 앞으로 올린후
        // 다시 정렬을 해주는 함수 (pop)
    }

    return 0;
}