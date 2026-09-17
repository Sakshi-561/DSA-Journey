#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }

};
 class List{
    node* head;
    node* tail;
public:
    List(){
        head=tail=NULL;
    }
    void push_back(int val){
        node* newNode=new node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"Linked list is empty\n";
            return;
        }
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    void print(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    List ll;
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);

    ll.print(); 

    ll.pop_front();
    
     ll.print(); 
    return 0;
}
 