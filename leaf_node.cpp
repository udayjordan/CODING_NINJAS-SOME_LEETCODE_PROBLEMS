// @csalgo

// Coding Problem
// Problem Statement: Count leaf Nodes
// Problem Level: EASY
// Problem Description:
// Given a generic tree, count and return the number of leaf nodes present in the given tree.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

// Output Format :
// The first and only line of output prints the count of leaf nodes present in the given tree.

// Constraints:
// Time Limit: 1 sec

// Sample Input 1 :
// 10 3 20 30 40 2 40 50 0 0 0 0

// Sample Output 1 :
// 4

// @csalgo



#include<bits/stdc++.h>
#include<vector>
using namespace std;
template <typename T>
class treeNode{
public:
T data;
vector<treeNode<T>*>children;
treeNode(T data){
this->data=data;
}
};
void print(treeNode<int>* rootData){
    cout<<rootData->data<<':';
    for(int i=0;i<rootData->children.size();i++){
cout<<rootData->children[i]->data<<',';
}
cout<<endl;
for(int i=0;i<rootData->children.size();i++){
print(rootData->children[i]);
}
}
int ct=0;
treeNode<int>* insertNode(){
    int data;
    cout<<"enter the root";
    cin>>data;
    treeNode<int>*rootData=new treeNode<int>(data);
    int n;
    cout<<"enter the no. of nodes";
    cin>>n;
    if(n==0){
      ct++;
    }
    for(int i=0;i<n;i++){
      treeNode<int>* child=insertNode();
      rootData->children.push_back(child);  
    }
    return rootData;
}
// int ans=0;
// int sum_all_Nodes( treeNode<int>*root){
   
    
     
//     for(int i=0;i<root->children.size();i++){
//      ans=ans+sum_all_Nodes(root->children[i]);
        
//     }
      
    
//     return ans;
     
// }

int main(){
     treeNode<int>* root=insertNode();
    // treeNode<int>* node1=new treeNode<int>(2);
    // treeNode<int>* node2=new treeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
     cout<<ct;
    
   // print(root);
}
