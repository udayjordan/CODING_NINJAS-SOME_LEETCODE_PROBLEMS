// @csalgo

// Coding Problem
// Problem Statement: Search in BST
// Problem Level: MEDIUM
// Problem Description:
// Given a BST and an integer k. Find if the integer k is present in given BST or not. You have to return true, if node with data k is present, return false otherwise.
// Note: Assume that BST contains all unique elements.
// Input Format:
// The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
// The following line of input contains an integer, that denotes the value of k.

// Output Format:
// The first and only line of output contains a boolean value. Print true, if node with data k is present, print false otherwise.

// Constraints:
// Time Limit: 1 second

// Sample Input 1 :
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 2

// Sample Output 1 :
// true

// Sample Input 2 :
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 12

// Sample Output 2 :
// false

// @csalgo
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class binary_tree_node{
public:
int data;
binary_tree_node<int> *left;
binary_tree_node<int> *right;
binary_tree_node(T data){
    this->data=data;
    left=NULL;
    right=NULL;
}
~binary_tree_node(){
    delete left;
    delete right;
}
};
bool search_data(binary_tree_node<int>*root,int val){
    if(root==NULL){
        return false; 
    }
if(val==root->data){
    return true;
}

if(val<root->data){
   return search_data(root->left,val);
}
if(val>root->data){
   return search_data(root->right,val); 
}

    
 

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
    int val;
    cout<<"enter the value to be searched";
    cin>>val;
binary_tree_node<int> *root=insert_data();
int x=search_data(root,val);
if(x==1){
    cout<<" true";

}
else{ cout<<"false";}
delete root;
}