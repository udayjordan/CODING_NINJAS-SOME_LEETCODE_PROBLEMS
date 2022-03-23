#include<bits/stdc++.h> 
using namespace std;
class Node{
public:
int data;
Node *next;
Node *prev;
Node(int data){
    this -> data=data;
    next=NULL;
    prev=NULL;
}
};
Node *head, *tail;
void input(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
Node *n=new Node(data);
if(head==NULL){
    head=n;
    tail=n;
}
else{
    tail->next=n;
    n->prev=tail;
    tail=n;
}
cin>>data;
    }

}

void func(){
Node *new_node;

    Node *temp=head;
    while(temp!=NULL){
        new_node=temp->next;
temp->next=temp->prev;
temp->prev=new_node;
temp=new_node;
    }
 new_node=head;
  head=tail;
   tail=new_node; 
}
void disp(){
while(head!=NULL){
    cout<<head->data;
    head=head->next;
}

}


int main(){
    input();
    func();
    disp();
}