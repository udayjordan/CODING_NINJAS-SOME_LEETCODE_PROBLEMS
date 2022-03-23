#include<bits/stdc++.h> 
using namespace std;
class Node{
public:
int data;
Node *next;
Node(int data){
    this -> data=data;
    next=NULL;
}
};
Node *head,*tail;
void input(){
int data;
cin>>data;
head=NULL;
tail=NULL;
while (data!=-1){
Node *n=new Node(data);
if(head==NULL){
    head=n;
    tail=n;
}
else{
    tail -> next=n;
    tail= tail->next;
}
cin>>data;
}
tail->next=head;

}
void func(){
    Node *prev=tail;
    Node *temp=head;
    Node *a;
    while(temp!=tail){
a=temp->next;
temp->next=prev;
prev=temp;
temp=a;
    }
    temp->next=prev;
    tail=head;
    head=temp;
}
void print(){
   Node *temp=head;
while(temp->next!=head){
    cout<<temp->data<<" ";
    temp=temp->next;

}

cout<<temp->data;
}
int main(){
input();
  func();  
print();

}