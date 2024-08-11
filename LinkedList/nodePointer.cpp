#include <iostream>
using namespace std;
class Node{ //Linked List node
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }

};
// displaying linked list;
// void display(Node* head ){
//     Node* temp = head;
//     while(temp!=NULL){
//     cout<<temp->val<<" ";
//     temp = temp->next;
//     }
    
// }

void display(Node* head ){
    // Node* temp = head;
    while(head!=NULL){
    cout<<head->val<<" ";
    head = head->next;
    }
    
}
// count no of nodes;
int size(Node* head){
    int count =0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
void insertAtEnd(Node* head,int val){
    Node* t = new Node(val);
    while(head->next!=NULL){
        head=head->next;
    }
    head->next = t;
    

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

    // Node* temp = a;
    // while(temp!=NULL){
    //     cout<<temp->val<<" ";
    //     temp = temp->next;

    // }

    // another method of displaying using function;

    // display(a); // pass by value hua hai
    // cout<<endl;
    // cout<<size(a)<<endl;

    // inasert at end;
    insertAtEnd(a,60);
    display(a);

}