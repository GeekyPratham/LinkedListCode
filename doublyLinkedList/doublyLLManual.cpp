#include <iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void display(Node* head){  // space complexity is O(1)
    while(head){
        cout<<head->val<<" ";
        head= head->next;
    }
}
void displayRec(Node* head){// O(n) space
    if(head==NULL) return;
    cout<<head->val<<" ";
    displayRec(head->next);
}
void displayRecRev(Node* head){ // O(n) space
    if(head==NULL) return;
    displayRecRev(head->next);
    cout<<head->val<<" ";
    
}

void displayRev(Node* tail){
    while(tail){
        cout<<tail->val<<" ";
        tail=tail->prev;
    }
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;

    displayRecRev(a);
    cout<<endl;
    displayRev(e);

}