#include <iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    //constructor
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{

//     class Node{ //nested class
    // public:
    //     int val;
    //     Node* next;
    //     //constructor
    //     Node(int val){
    //         this->val = val;
    //         this->next = NULL;
    //     }
    // };
public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtEnd(int val){
        Node* temp = new Node(val);
        if(size==0){
            head = tail = temp;

        }
        else{
            tail->next=temp;
            tail= temp;
        }
        size++;
        
    }

    void insertAtBeg(int val){
        Node* temp = new Node(val);
        if(size==0){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertAtAny(int idx,int val){
        if(idx<0 || idx>size){
            cout<<"invalid index"<<endl;
           
        }
        else if(idx == 0){
            insertAtBeg(val);
           
        }
        else if(idx ==size){
            insertAtEnd(val);
          
        }
        else {
            Node* t = new Node(val);
            Node* temp = head;
            int i = 1;
            while(i<idx){
                temp=temp->next;
                i++;
            }
            t->next = temp->next;
            temp->next = t;
            size++;

        }

    }
    int getElement(int idx){
        if(idx<0 || idx>= size){
            cout<<"invalid operation";
            
            return -1;
        }
        else if(idx==0){
            return head->val;
        }
        else if(idx == size-1){
            return tail->val;
        }
        else{
            Node* temp = head;
            for(int i=1;i<=idx;i++){
                temp = temp->next;
            }
            return temp->val;
        }        
    }
    void deleteAtHead(){//deletion ho rahi hai tho kuch pass karna ka jarurat nahi hoga
        if( size == 0 ){
            cout<<"list is empty";
            return;
        }
        // else if(size==1){
        //     head = tail = NULL;
        //     size--;
        //     return;
        // }
        else{
            head = head->next;
            size--;
            return;
        }

    }
    void deleteAtTail(){
        
        if(size==0){
            cout<<"list is empty";
            return;
        }
        else{
            Node* temp = head;
            while(temp->next != tail){
                temp =temp->next;
            }
            temp->next=NULL;
            tail = temp;
            size--;
            return;
        }
    }
    void deleteAtIdx(int idx){
        if (idx<0 || idx>size){
            cout<<"invalid operation";
            return;
        }
        if(idx == 0){
            deleteAtHead();
            return;
        }
        else if(idx == size-1){
            deleteAtTail();
            return;
        }
        else{
            
            Node* temp = head;
            for(int i=1;i<=idx-1;i++){
                temp =temp->next;
            }
            temp->next = temp->next->next;
            size--;
            return;
        }
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList ll; // creating object of linked list class
    ll.insertAtEnd(10);
    ll.display();
    cout<<ll.size<<endl;
    ll.insertAtEnd(34);
    ll.display();
    cout<<ll.size<<endl;
    ll.insertAtEnd(36);

    ll.insertAtEnd(38);
    ll.display();
    cout<<ll.size<<endl;
    ll.insertAtBeg(50);
    ll.display();
    ll.insertAtAny(3,59);
    ll.display();

    cout<<ll.getElement(2)<<endl;
    cout<<ll.getElement(1)<<endl;
    cout<<ll.getElement(0)<<endl;
    cout<<ll.getElement(3)<<endl;
    cout<<ll.getElement(4)<<endl;
    cout<<ll.getElement(5)<<endl;
    cout<<ll.getElement(-1)<<endl;
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();
    ll.deleteAtIdx(1);
    ll.display();

}