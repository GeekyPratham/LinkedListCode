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

class DLL{
public:
    Node* head;
    Node* tail;
    int size;
    DLL(){
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
            temp->prev=tail; //extra
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
            head->prev = temp;//extra
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
            Node* temp = head;  //traversing
            int i = 1;
            while(i<idx){
                temp=temp->next;
                i++;
            }
            t->next = temp->next;
            temp->next = t;
            t->prev = temp;   // extra
            t->next->prev = t;   // extra
            size++;

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
            if(head)head->prev = NULL; //extra
            if(head==NULL) tail = NULL;
            size--;
            return;
        }

    }
    void deleteAtTail(){
        
        if(size==0){
            cout<<"list is empty";
            return;
        }
        else if(size==1){  // extra
            deleteAtHead();
            return;
        }
        else{
           Node* temp = tail->prev;
           temp->next =NULL;
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
            temp->next->prev = temp; //extra;
            size--;
            return;
        }
    }

    // int getElement(int idx){
    //     if(idx<0 || idx>= size){
    //         cout<<"invalid operation";
            
    //         return -1;
    //     }
    //     else if(idx==0){
    //         return head->val;
    //     }
    //     else if(idx == size-1){
    //         return tail->val;
    //     }
    //     else{
    //         Node* temp = head;
    //         for(int i=1;i<=idx;i++){
    //             temp = temp->next;
    //         }
    //         return temp->val;
    //     }        
    // }
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
            if(idx>=size/2){
                Node* temp = head;
                for(int i=1;i<=idx;i++){
                    temp = temp->next;
                }
                return temp->val;
            }
            else{
                Node* temp = tail;
                for(int  i = 1;i<= size-idx;i--){
                    temp = temp->prev;
                }
                return temp->val;
            }
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
    DLL list;

    list.insertAtEnd(10);
    list.display();
    list.insertAtEnd(45);
    list.display();
    list.insertAtBeg(11);
    list.display();
    list.insertAtAny(5,56);
    list.display();


    list.deleteAtHead();
    list.display();
    list.deleteAtTail(); // work nahi kia
    list.display();
    list.insertAtEnd(105);
    list.display();
    list.insertAtEnd(452);
    list.display();
    list.insertAtBeg(113);
    list.display();
    list.deleteAtIdx(2);
    list.display();
    cout<<list.getElement(1);
    

}