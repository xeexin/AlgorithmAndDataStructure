#include<iostream>
using namespace std;
struct Node {
    int value;
    Node *next;
};
Node *head, *last;

void addnode(int x){
    if (head == NULL) {
        head = new Node();
        head->value = x;
        last = head;
    } else {
        last->next = new Node();
        last = last->next;
        last->value = x;
    }
}
int top(){
    return  head->value;
}
void pop(){
    Node *temp = head;
    head = head->next;
    delete temp;
}
int main()
{
    for (int x = 1; x <= 50; x++)
    {
        addnode(x);
    }
    for (int x = 0; x < 50; x++)
    {
        cout << top() << " "; // 출력
        pop(); // 출력후 제거
    }

    return 0;
}