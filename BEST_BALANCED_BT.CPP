


// @csalgo

// Chapter Assignment
// Problem Statement:  Balanced
// Problem Level: MEDIUM
// Problem Description:
// Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, false otherwise.
// Input format :
// Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

// Sample Input 1 :
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

// Sample Output 1 :
// false

// Sample Input 2 :
// 1 2 3 -1 -1 -1 -1

// Sample Output 2 :
// true



// =====Answer=====
// Correct Option: 

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

pair<int,bool> balanced_BT(binary_tree_node<int>* root){
  if(root==NULL){
      pair<int,bool>p;
      p.first=0;
      p.second=true;
      return p;
  }
  pair<int,bool>leftAns=balanced_BT(root->left);
   pair<int,bool>rightAns=balanced_BT(root->right);
   int lh=leftAns.first;
   int rh=rightAns.first;
   bool a=leftAns.second;
   bool b=rightAns.second;
   int height=1+max(lh,rh);
   if(lh-rh<=1){
       a=true;
       b=true;
   }
   else{
       a=false;
       b=false;
   }
   bool ans=a&&b;
   pair<int,bool>p;
   p.first=height;
   p.second=ans;
   return p;
 
}

int main(){
binary_tree_node<int> *root=insert_data();
pair<int,bool>p=balanced_BT(root);
cout<<"height  "<<" "<<p.first<<"check balance  "<<p.second;
delete root;
}