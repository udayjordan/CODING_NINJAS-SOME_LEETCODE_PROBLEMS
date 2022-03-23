// @csalgo

// Coding Problem
// Problem Statement: BST to LL
// Problem Level: EASY
// Problem Description:
// Given a BST, convert it into a sorted linked list. You have to return the head of LL.
// Input format:
// The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

// Output Format:
// The first and only line of output prints the elements of sorted linked list.

// Constraints:
// Time Limit: 1 second

// Sample Input 1:
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

// Sample Output 1:
// 2 5 6 7 8 10

// @csalgo

#include<bits/stdc++.h>
#include"BST_CLASS.h"
#include"NODE_CLASS.h"

using namespace std;

class sortedLL{
    public:
    Node<int>* head;
    Node<int>* tail;
};

void print(Node<int> *head){
    
while(head!=NULL){
    cout<<head->data;
    head=head->next;
}
}
sortedLL constructLL(binary_tree_node<int>* root){
    if(root==NULL){
        sortedLL L;
        L.head=NULL;
        L.tail = NULL;
        return L;
    }
    
    Node<int>* rootNode = new Node<int>(root->data);
        sortedLL leftAns = constructLL(root->left);
        sortedLL rightAns = constructLL(root->right);
    if(leftAns.head==NULL)
    {
        leftAns.tail=rootNode;
        leftAns.head=rootNode;
    }
    else
    {
leftAns.tail->next=rootNode;
        leftAns.tail=rootNode;
    }
    if(rightAns.head==NULL)
    {

        return leftAns;
    }
    leftAns.tail->next=rightAns.head;
    leftAns.tail=rightAns.tail;
    return leftAns;

    
    
}

Node<int>* constructLinkedList(binary_tree_node<int>* root) {
	
    
   sortedLL finalAns = constructLL(root);
    
    return finalAns.head;
}
binary_tree_node<int>*insert_data(){
    int data;
    cout<<"enter the root data"<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    binary_tree_node<int> *root=new binary_tree_node<int>(data);
    queue<binary_tree_node<int>*>Q;
    Q.push(root);
    while(Q.size()!=0){

binary_tree_node<int> *front=Q.front();
Q.pop();
int leftchild_data;
cout<<"enter the left child of "<<front->data<<endl;
cin>>leftchild_data;
if(leftchild_data!=-1){
   binary_tree_node<int> *leftchild=new binary_tree_node<int>(leftchild_data); 
   front->left=leftchild;
   Q.push(leftchild);
}
int rightchild_data;
cout<<"enter the right child of "<<front->data<<endl;
cin>>rightchild_data;
if(rightchild_data!=-1){
   binary_tree_node<int> *rightchild=new binary_tree_node<int>(rightchild_data); 
   front->right=rightchild;
   Q.push(rightchild);
}



    }
    return root;

}


int main(){
binary_tree_node<int> *root=insert_data();
Node<int>*p=constructLinkedList(root);
print(p);
delete root;
}