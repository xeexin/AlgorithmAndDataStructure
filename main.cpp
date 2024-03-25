#include<iostream>
using namespace std;
struct Node {
    int value;
    Node *next;
};
Node *head;
Node *last;

void addnode(int num) {
    if (head == NULL) {
        head = new Node();
        last = head;
        head->value = num;
    } else {
        last->next = new Node();
        last = last->next;
        last->value = num;
    }
}
int main()
{
    addnode(3);
    addnode(4);
    addnode(5);


    return 0;
}