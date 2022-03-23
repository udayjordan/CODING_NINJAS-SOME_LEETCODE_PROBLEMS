//new technique to create BST



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
// void print_levelwise(binary_tree_node<int>*root){
//     if(root==NULL){
//         return;
//     }
//     queue<binary_tree_node<int>*>q;
//     q.push(root);
//     while(q.size()!=0){
//         binary_tree_node<int>* front=q.front();
//         cout<<front->data<<" ";
//         q.pop();
//         if(front->left!=NULL){
// q.push(front->left);
//         }
//         if(front->right!=NULL){
//             q.push(front->right);
//         }
//     }

// }

binary_tree_node<int>* insert_node(binary_tree_node<int>*root,int val){
    if (root==NULL){
        return new binary_tree_node<int>(val);
    }
    if(val<root->data){
root->left=insert_node(root->left,val);
    }

    else{
        root->right=insert_node(root->right,val);
    }
    return root;
}
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
int main(){
    binary_tree_node<int>*root=NULL;
    root=insert_node(root,4);
    insert_node(root,1);
    insert_node(root,3);
    insert_node(root,2);
    insert_node(root,5);
    insert_node(root,7);
    print_binary_tree(root);

}