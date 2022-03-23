// @csalgo

// ChapterAssignment
// Problem Statement: Create  Insert Duplicate Node
// Problem Level: EASY
// Problem Description:
// For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.
// The root will remain the same. So you just need to insert nodes in the given Binary Tree.
// Example:

// After making the changes to the above-depicted tree, the updated tree will look like this.


// You can see that every node in the input tree has been duplicated and inserted to the left of itself.

// Input format :
// The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

// Output Format :
// The updated tree will be printed in a level order fashion where each level will be printed on a new line. 
// Elements on every level will be printed in a linear fashion. A single space will separate them.

// Note:
// You are not required to print anything explicitly. It has already been taken care of. Just implement the function to achieve the desired structure of the tree.

// Constraints :
// 1 <= N <= 10^5
// Where N is the total number of nodes in the binary tree.

// Time Limit: 1 sec

// Sample Input 1:
// 10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1

// Sample Output 1:
// 10 
// 10 30 
// 20 30 60 
// 20 50 60 
// 40 50 
// 40

// Sample Input 2:
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

// Sample Output 2:
// 8 
// 8 10 
// 5 10 
// 5 6 
// 2 6 7 
// 2 7



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
void print_levelwise(binary_tree_node<int>*root){
    if(root==NULL){
        return;
    }
    
        queue<binary_tree_node<int>*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()!=0){
       binary_tree_node<int> *front = q.front();
        q.pop();
        if(front==NULL){
            if(q.size()==0){
                return;
            }
            cout<<endl;
            q.push(NULL);
        }
        
        else{
            cout<<front->data<<" ";
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
       }}
binary_tree_node<int>* insert_duplicate(binary_tree_node<int>* root){
if(root==NULL){
    return NULL ;
}

root->left =insert_duplicate(root->left);
root->right =insert_duplicate(root->right);
binary_tree_node<int>*leftchild=  root->left;
binary_tree_node<int>*rootNode=new binary_tree_node<int> (root->data);
root->left=rootNode;
rootNode->left=leftchild;
return root;
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
binary_tree_node<int> *root1=insert_duplicate(root);
print_levelwise(root1);

}