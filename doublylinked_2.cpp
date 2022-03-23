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
Node *head,*tail;
void input(){
    int data;
    cin>>data;
    head=NULL;
    tail=NULL;
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
int length(){
int i=0;
Node *temp=head;
while(temp!=NULL){
    temp=temp->next;
    i++;
}
return i;
}
void delfrombeg(){
    Node *temp=head;
    head=temp->next;
    temp->next->prev=NULL;
    delete temp;
}
void delfromend(){
    Node *temp=tail;
    tail=temp->prev;
    temp->prev->next=NULL;
    delete temp;
}
 void func(){
    
     Node *temp=head;
    int len=length();

     int i=1;
   
    int pos;
    cin>>pos;
    if(pos==1){
        delfrombeg();
    }
  if(pos==len){
      delfromend();
  }
  else{
      while(i<pos){
          temp=temp->next;
          i++;
      }
      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;
      delete temp;
  }

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