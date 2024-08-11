// displaying linked list recursively;
#include <iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
void display(Node* head){ // a me address store hai ishlia pointer banaye hai
    if(head==NULL) return; // base case (we use this)
    
    display(head->next);
    cout<<head->val<<" ";
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

    display(a);// pass by value hua hai

}