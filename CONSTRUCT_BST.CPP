// @csalgo

// Coding Problem
// Problem Statement: Construct BST
// Problem Level: EASY
// Problem Description:
// Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
// Note: If array size is even, take first mid as root.
// Input format:
// The first line of input contains an integer, which denotes the value of n. The following line contains n space separated integers, that denote the values of array.

// Output Format:
// The first and only line of output contains values of BST nodes, printed in pre order traversal.

// Constraints:
// Time Limit: 1 second

// Sample Input 1:
// 7
// 1 2 3 4 5 6 7

// Sample Output 1:
// 4 2 1 3 6 5 7

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
void print_levelwise(binary_tree_node<int>*root){
    if(root==NULL){
        return;
    }
    queue<binary_tree_node<int>*>q;
    q.push(root);
    while(q.size()!=0){
        binary_tree_node<int>* front=q.front();
        cout<<front->data<<" ";
        q.pop();
        if(front->left!=NULL){
q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }

}

binary_tree_node<int>* construct(int *arr,int si,int ei){

if(si>ei){

return NULL ;
}
int mid=(si+ei)/2;
binary_tree_node<int>*root=new binary_tree_node<int>(arr[mid]);
root->left=construct(arr,si,((si+ei)/2)-1);
root->right=construct(arr,((si+ei)/2)+1,ei);


return root;

}
int main(){
    int x;
    cout<<"ENTER THE NO. OF ELEMENTS TO BE INSERTED ";
    cin>>x;
    int arr[100];
    cout<<"enterthe elements of which tree is to be made ";
    for(int i=0;i<x;i++){
        cin>>arr[i];
    }
   binary_tree_node<int>*root= construct(arr,0,x-1);
   print_levelwise(root);
}