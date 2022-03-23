// @csalgo

// Chapter Assignment
// Problem Statement: Largest BST
// Problem Level: HARD
// Problem Description:
// Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

// Output format:
// The first and only line of output contains the height of the largest BST.

// Constraints:
// Time Limit: 1 second

// Sample Input 1:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

// Sample Output 1:
// 2



// =====Answer=====
// Correct Option: 

// @csalgo







#include<bits/stdc++.h>
#include"BST_CLASS.h"
#include<vector>
using namespace std;
class largestBSTReturn{
public:
bool isBST;
int minimum;
int maximum;
int height;
};
largestBSTReturn largest_BST(binary_tree_node<int>*root){

    if(root==NULL){
        largestBSTReturn output;
        output.isBST=true;
        output.maximum=INT_MIN;
        output.minimum=INT_MAX;
        output.height=0;
        return output;
    }
largestBSTReturn leftoutput=largest_BST(root->left);

largestBSTReturn rightoutput=largest_BST(root->right);
int minimum=min(root->data,min(leftoutput.minimum,rightoutput.minimum));
int maximum=max(root->data,max(leftoutput.maximum,rightoutput.maximum));
bool isBST= (root->data>leftoutput.maximum) && (root->data<rightoutput.minimum) && leftoutput.isBST && rightoutput.isBST;
int height;

if(isBST){
height=1+max(leftoutput.height,rightoutput.height);

}
else{
    height=max(leftoutput.height,rightoutput.height);
}

largestBSTReturn output;
output.height=height;
output.isBST=isBST;
output.minimum=minimum;
output.maximum=maximum;
return output;

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

largestBSTReturn output=largest_BST(root);
cout<<output.height;

}