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
Node *input(){
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
    return head;
}
void disp(Node *head){
while(head!=NULL){
    cout<<head->data;
    head=head->next;
}

}


int main(){
    Node *head=input();
    disp(head);
}
