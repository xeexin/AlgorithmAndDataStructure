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

void insert(int a, int b){
    for (Node *p = head; p != NULL; p = p->next) {
        if (p->value == a) {
            Node *temp = new Node();
            temp->value = b;
            temp->next = p->next;
            p->next = temp;
        }
    }
}
int main()
{

    for (int x = 1; x < 5; x++) {
        addnode(x);
    }
    insert(2, 6);

    return 0;
}