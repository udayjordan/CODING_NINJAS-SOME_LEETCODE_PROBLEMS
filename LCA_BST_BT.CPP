// @csalgo

// Chapter Assignment
// Problem Statement: LCA of Binary Tree
// Problem Level: MEDIUM
// Problem Description:
// Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree. Read about LCA if you are having doubts about the definition.
// If out of 2 nodes only one node is present, return that node.
// If both are not present, return -1.
// Input format :
// Line 1 :  Elements in level order form (separated by space)
// (If any node does not have left or right child, take -1 in its place)
// Line 2 : Two integers, Node 1 and Node 2 (separated by space)

// Output Format :
// LCA

// Constraints :
// 1 <= N <= 1000

// Sample Input 1:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 2 10

// Sample Output 1:
// 10

// Sample Input 2:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 2 6

// Sample Output 2:
// 5

// Sample Input 3:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 12 78

// Sample Output 3:
// -1



// =====Answer=====
// Correct Option: 

// @csalgo



#include<bits/stdc++.h>
#include<vector>
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

int lca_bt(binary_tree_node<int>*root,int n1,int n2,int c){
if(root==NULL){
    return -1 ;
}
   
   if(root->data==n1||root->data==n2){
    return root->data;
   }
  int a= lca_bt(root->left,n1,n2,c);
   int b=lca_bt(root->right,n1,n2,c);
   if(a!=-1 && b==-1){
       return a;
   }
   if(a==-1 && b!=-1){
       return b;

   }
   if(a==-1 && b==-1){
       return -1;
   }
if(a!=-1 && b!=-1){
return c;
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
  
binary_tree_node<int> *root=insert_data();
int c=root->data;
int n1,n2;
cin>>n1;
cin>>n2;
cout<<lca_bt(root,n1,n2,c);


}