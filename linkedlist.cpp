#include <bits/stdc++.h>
using namespace std;

struct Node { int data; Node* next; Node(int x): data(x), next(nullptr) {} };

void push_front(Node*& head, int x) {
    Node* n = new Node(x);
    n->next = head;
    head = n;
}

void printList(Node* head) { for (Node* c=head;c;c=c->next) cout<<c->data<<" "; cout<<"\n"; }

int main(){
    Node* head = nullptr;         // empty list
    push_front(head, 30);         // 30
    push_front(head, 20);         // 20 30
    push_front(head, 10);         // 10 20 30
    printList(head);

    // cleanup
    for(Node* c=head; c; ){ Node* n=c->next; delete c; c=n; }
    return 0;
}
