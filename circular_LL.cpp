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
Node *input(){
int data;
cin>>data;
Node *head=NULL;
Node *tail=NULL;
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
return head;
}
void print(Node *head){
   Node *temp=head;
while(temp->next!=head){
    cout<<temp->data<<" ";
    temp=temp->next;

}
cout<<temp->data;

}
int main(){
    Node *head=input();
    
print(head);

}