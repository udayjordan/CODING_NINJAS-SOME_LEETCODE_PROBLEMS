// @csalgo

// Coding Problem
// Problem Statement: Construct Tree from postorder  inorder
// Problem Level: MEDIUM
// Problem Description:
// For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
// Note:
// Assume that the Binary Tree contains only unique elements.

// Input Format:
// The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

// The second line of input contains N integers, all separated by a single space. It represents the Postorder-traversal of the binary tree.

// The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.

// Output Format:
// The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
// Elements on every level will be printed in a linear fashion. A single space will separate them.

// Constraints:
// 1 <= N <= 10^4
// Where N is the total number of nodes in the binary tree.

// Time Limit: 1 sec

// Sample Input 1:
// 7
// 4 5 2 6 7 3 1 
// 4 2 5 1 6 3 7

// Sample Output 1:
// 1 
// 2 3 
// 4 5 6 7

// Sample Input 2:
// 6
// 2 9 3 6 10 5 
// 2 6 3 9 5 10

// Sample Output 2:
// 5 
// 6 10 
// 2 3 
// 9

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


void print_binary_tree(binary_tree_node<int>*root){
 
    if(root==NULL){
        return;
    }
   cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<",";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data<<",";
    }
cout<<endl;
print_binary_tree(root->left);
print_binary_tree(root->right);

}
binary_tree_node<int>* binary_tree_helper(int *in,int *pos,int inS,int inE,int posS,int posE){
    if(inS>inE){
        return NULL;
    }
    int rootIndex=-1;
    int rootData=pos[posE];
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex=i;
        }
    }
    int LinS=inS;
    int LinE=rootIndex-1;
    int RinS=rootIndex+1;
    int RinE=inE;
    int LposS=posS;
    int LposE=LposS+LinE-LinS;
    int RposS=LposE+1;
    int RposE=posE-1;


    binary_tree_node<int> *root=new binary_tree_node<int>(rootData);
    root->left=binary_tree_helper(in,pos,LinS,LinE,LposS,LposE);
    root->right=binary_tree_helper(in,pos,RinS,RinE,RposS,RposE);
return root;

}
binary_tree_node<int>* binary_Tree_builder(int *in,int *pos,int size ){
return binary_tree_helper(in,pos,0,size-1,0,size-1);
}
int main(){
    int in[]={4,2,5,1,8,6,9,3,7};
    int pos[]={4,5,2,8,9,6,7,3,1};
binary_tree_node<int>*root= binary_Tree_builder(in,pos,9);
print_binary_tree(root);
delete root;
}